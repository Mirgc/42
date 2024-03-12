#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <cstring>
#include <sstream>
#include <signal.h>
#include <iomanip>
#include <fstream>
#include <iostream>

#include "ServeRequestEventHandler.hpp"
#include "Reactor.hpp"
#include "HTTPRequestFactory.hpp"
#include "HTTPHeader.hpp"
#include "HTTPBody.hpp"
#include "HTTPResponse400.hpp"

ServeRequestEventHandler::ServeRequestEventHandler(Reactor& reactor, int fd, const VirtualHostServer & virtualHostServer) 
    : EventHandler(reactor, fd, virtualHostServer) {
    this->httpRequest = NULL;
    this->setRequestStatus(REQUEST_STATUS_WAITING);
    this->bytesRead = 0;
}

ServeRequestEventHandler::ServeRequestEventHandler(const ServeRequestEventHandler & src)
    : EventHandler(src.reactor, src.fd, src.virtualHostServer) {
    this->requestStatus = src.requestStatus;
    this->bytesRead = src.bytesRead;
    this->httpResponse = src.httpResponse;
    this->httpHeader = src.httpHeader;
    this->copyHTTPRequest(src.httpRequest);
}

ServeRequestEventHandler::~ServeRequestEventHandler() {
    this->freeHTTPRequest();
}

void ServeRequestEventHandler::copyHTTPRequest(HTTPRequest * httpRequest) {

    this->freeHTTPRequest();
    if (httpRequest) {
        this->httpRequest = httpRequest->clone();
    }
}

void ServeRequestEventHandler::freeHTTPRequest() {
    if (this->httpRequest) {
        delete this->httpRequest;
        this->httpRequest = NULL;
    }
}

ServeRequestEventHandler& ServeRequestEventHandler::operator=(const ServeRequestEventHandler &rhs) {
	if (this != &rhs) {
        this->fd = rhs.fd;
        this->virtualHostServer = rhs.virtualHostServer;
        this->requestStatus = rhs.requestStatus;
        this->bytesRead = rhs.bytesRead;
        this->httpResponse = rhs.httpResponse;
        this->httpHeader = rhs.httpHeader;
        this->buffer = rhs.buffer;
        this->copyHTTPRequest(rhs.httpRequest);
    }

	return (*this);
}

void ServeRequestEventHandler::handleEvent(const t_event_handler_type eventType) {

    std::cout << "ServeRequestEventHandler::handleEvent() (fd = " << fd << ") (request status: " << (std::string)this->requestStatus << ")" << std::endl;

    switch(this->requestStatus.getStatus()) {
        case REQUEST_STATUS_WAITING:

            if (eventType != EVENT_HANDLER_TYPE_READ) {
                std::cout << "ServeRequestEventHandler::handleEvent() REQUEST_STATUS_WAITING ignoring write event when no data has been read yet." << std::endl;
                this->setRequestStatus(REQUEST_STATUS_CLOSED_OK);
                reactor.unregisterEventHandler(fd);
                break;
            }

            this->setRequestStatus(REQUEST_STATUS_READING_REQUEST);
        case REQUEST_STATUS_READING_REQUEST:
            this->readOrCloseRequest();

            if (!this->isRequestHeaderFullyRead()) {
                // let this call go. Select will call again and will go straight to REQUEST_STATUS_READING_REQUEST
                break;
            }

            this->isValidHTTPRequestHeader = this->httpHeader.parseHTTPHeader(this->buffer);

            std::cout << "Expected Content-Length " << this->httpHeader.getHeaderValueWithKey("Content-Length") << std::endl;

            if (!this->isRequestBodyFullyRead()) {
                // let this call go. Select will call again and will go straight to REQUEST_STATUS_READING_REQUEST
                break;
            }

            this->setRequestStatus(REQUEST_STATUS_PROCESSING);

        case REQUEST_STATUS_PROCESSING:
            this->processRequest();
            this->setRequestStatus(REQUEST_STATUS_PROCESSING_COMPLETE);

        case REQUEST_STATUS_PROCESSING_COMPLETE:
            this->setRequestStatus(REQUEST_STATUS_SENDING);

            // We break here, to let select call us again for writing.
            break;

        case REQUEST_STATUS_SENDING:
            this->sendResponse();
            if (!this->isRequestFullySent()) {
                // let this call go. Select will call again and will go straight to REQUEST_STATUS_SENDING
                break;
            }

            this->setRequestStatus(REQUEST_STATUS_SENDING_COMPLETE);
            break;

        case REQUEST_STATUS_SENDING_COMPLETE:

            if (eventType != EVENT_HANDLER_TYPE_READ) {
                std::cout << "ServeRequestEventHandler::handleEvent() REQUEST_STATUS_SENDING_COMPLETE ignoring write event when no data has been read yet." << std::endl;
                this->setRequestStatus(REQUEST_STATUS_CLOSED_OK);
                reactor.unregisterEventHandler(fd);
                break;
            }

            this->readOrCloseRequest();
            break;

        case REQUEST_STATUS_CLOSED_OK:
            break;

        case REQUEST_STATUS_CLOSED_ERROR:
        default:
            break;
    }
}

bool ServeRequestEventHandler::isRequestHeaderFullyRead() {
    size_t bufferSize = buffer.size();

    if (bufferSize < 4) {
        // Insufficient data to determine the end of headers
        return false;
    }

    for (size_t i = 0; i < bufferSize - 3; ++i) {
        if (buffer[i] == '\r' && buffer[i + 1] == '\n' &&
            buffer[i + 2] == '\r' && buffer[i + 3] == '\n') {
            // Found two consecutive '\r\n\r\n' sequences, indicating the end of headers
            return true;
        }
    }

    return false;
}

bool ServeRequestEventHandler::isRequestBodyFullyRead() {
    if (this->httpHeader.getMethod() == "GET" || this->httpHeader.getMethod() == "DELETE") {
        // GET requests do not allow BODY
        return true;
    }

    std::string contentLenghtStr = this->httpHeader.getHeaderValueWithKey("Content-Length");
    if (contentLenghtStr.empty()) {
        // We are waiting to read the body of a valid request
        if (this->isValidHTTPRequestHeader && (
            this->httpHeader.getMethod() == "POST" ||
            this->httpHeader.getMethod() == "PUT"
        )) {
            return false;
        }

        // This should be an error, as it is an invalid request and there is no content lenght to
        // read out of the socket. Let it give a bad request error.
        return true;
    }

    std::istringstream iss(contentLenghtStr);
    ssize_t contentLenght;

    if (!(iss >> contentLenght)) {
        // This should be an error, as by now we should have the content length and there is none
        // or is not a number
        // Bad request, no valid content lenght
        this->isValidHTTPRequestHeader = false;
        return true;
    }

    if (this->getCurrentBodySize(this->buffer) != contentLenght) {
        // No error, but we have not yet read the full content length
        return false;
    }

    return true;
}

bool ServeRequestEventHandler::isRequestFullyRead() {
    return this->isRequestHeaderFullyRead() && this->isRequestBodyFullyRead();
}

bool ServeRequestEventHandler::isRequestFullySent() {
    return this->httpResponse.isRequestFullySent();
}

void ServeRequestEventHandler::setRequestStatus(t_http_request_status requestStatus)
{
#ifdef DEBUG_MODE
	bool isInvalidStatus = true;
    t_http_request_status currentStatus = this->requestStatus.getStatus();

    if (currentStatus == REQUEST_STATUS_WAITING)
	{
		isInvalidStatus = requestStatus != REQUEST_STATUS_WAITING &&
                          requestStatus != REQUEST_STATUS_READING_REQUEST &&
                          requestStatus != REQUEST_STATUS_CLOSED_OK;
	}
	else if (currentStatus == REQUEST_STATUS_READING_REQUEST)
	{
		isInvalidStatus = (requestStatus != REQUEST_STATUS_PROCESSING);
	}
	else if (currentStatus == REQUEST_STATUS_PROCESSING)
	{
		isInvalidStatus = (requestStatus != REQUEST_STATUS_PROCESSING_COMPLETE);
	}
	else if (currentStatus == REQUEST_STATUS_PROCESSING_COMPLETE)
	{
		isInvalidStatus = (requestStatus != REQUEST_STATUS_SENDING);
	}
	else if (currentStatus == REQUEST_STATUS_SENDING)
	{
		isInvalidStatus = (requestStatus != REQUEST_STATUS_SENDING_COMPLETE);
	}
	else if (currentStatus == REQUEST_STATUS_SENDING_COMPLETE)
	{
		isInvalidStatus = (requestStatus != REQUEST_STATUS_CLOSED_OK) &&
                          (requestStatus != REQUEST_STATUS_PROCESSING) &&
                          (requestStatus != REQUEST_STATUS_CLOSED_ERROR);
	}

	if (isInvalidStatus)
	{
		std::cout << "ServeRequestEventHandler::setRequestStatus invalid set from " << (std::string)this->requestStatus << " to " << requestStatus << std::endl;
		throw std::runtime_error("erveRequestEventHandler::setRequestStatus error.");
	}
#endif

    this->requestStatus.setStatus(requestStatus);
    std::cout << "ServeRequestEventHandler::setRequestStatus on (fd = " << fd << ") to status " << (std::string)this->requestStatus << std::endl;
}

void ServeRequestEventHandler::processRequest() {

    if (!this->isValidHTTPRequestHeader) {
        const ServerConfig & serverConfig = this->virtualHostServer.getServerConfig();
        this->httpResponse = HTTPResponse400(serverConfig.get400Content());
        this->buffer.clear();
        this->httpHeader.clear();

        return;
    }

    HTTPRequestFactory httpRequestFactory;

    HTTPBody httpBody;
    httpBody.setBody(
        this->extractBodyFromHttpRequest(this->buffer)
    );

    this->httpRequest = httpRequestFactory.createHTTPRequest(
        this->virtualHostServer.getServerConfig(),
        this->httpHeader,
        httpBody
    );

    if (!this->httpRequest) {
        this->buffer.clear();
        this->httpHeader.clear();
        this->setRequestStatus(REQUEST_STATUS_CLOSED_ERROR);
        throw std::runtime_error("Error creating HTTPRequest from factory");
    }

    this->httpResponse = this->httpRequest->process();
    this->buffer.clear();
    this->httpHeader.clear();
    this->freeHTTPRequest();
}

void ServeRequestEventHandler::sendResponse() {
    ssize_t bytesSent;
    std::vector<char> response = this->httpResponse.getNextResponseChunkToBeSent();

    bytesSent = send(fd, &response[0], response.size(), 0);
    if (bytesSent == -1) {
        std::runtime_error("Error sending reposnse to the client");
    } else if (bytesSent == 0) {
        // No bytes were sent
        std::cout << "No bytes were sent to the client" << std::endl;
    } else {
        // bytesSent bytes were sent
        this->httpResponse.addBytesSentToClient(bytesSent);

        // Process the received data, send responses back to the client here...
        std::cout << "ServeRequestEventHandler write data to client on (fd = " << fd << ") (bytesSent " << bytesSent << ")" << std::endl;
        std::cout.write(response.data(), std::min(response.size(), static_cast<size_t>(80)));
        std::cout << std::endl;
    }
}

void ServeRequestEventHandler::readOrCloseRequest() {

    std::vector<char> tmpBuffer(BUFFER_SIZE);
    std::fill(tmpBuffer.begin(), tmpBuffer.end(), 0);

    std::cout << "ServeRequestEventHandler reading data from (fd = " << fd << ")" << std::endl;

    ssize_t bytesRead = recv(fd, &tmpBuffer[0], tmpBuffer.size(), 0);
    std::cout << "ServeRequestEventHandler read data from (fd = " << fd << ") (bytesRead = " << bytesRead << ")" << std::endl;

    if (bytesRead == -1) {
        this->setRequestStatus(REQUEST_STATUS_CLOSED_ERROR);
        std::runtime_error("ServeRequestEventHandler error bytesRead -1");
    } else if (bytesRead == 0) {
        if (this->requestStatus.getStatus() == REQUEST_STATUS_SENDING_COMPLETE) {
            // Normal closure of a connection
            this->setRequestStatus(REQUEST_STATUS_CLOSED_OK);
            std::cout << "ServeRequestEventHandler connection closed by client" << std::endl;
        } else {
            this->setRequestStatus(REQUEST_STATUS_CLOSED_ERROR);
            std::cout << "ServeRequestEventHandler unexpected connection closed by client" << std::endl;
        }
        reactor.unregisterEventHandler(fd);
    } else {
        if (this->requestStatus.getStatus() == REQUEST_STATUS_SENDING_COMPLETE) {
            this->buffer.clear();
        }

        this->buffer.insert(this->buffer.end(), tmpBuffer.begin(), tmpBuffer.begin() + bytesRead);

        std::cout.write(tmpBuffer.data(), std::min(tmpBuffer.size(), static_cast<size_t>(80)));
        std::cout << std::endl;

        if (this->requestStatus.getStatus() == REQUEST_STATUS_SENDING_COMPLETE) {
            if (!this->isRequestHeaderFullyRead()) {
                this->setRequestStatus(REQUEST_STATUS_READING_REQUEST);
            } else {
                this->isValidHTTPRequestHeader = this->httpHeader.parseHTTPHeader(this->buffer);

                std::cout << "Expected Content-Length " << this->httpHeader.getHeaderValueWithKey("Content-Length") << std::endl;
                std::cout << "Read " <<  "" << this->buffer.size() << std::endl;

                if (!this->isRequestBodyFullyRead()) {
                    this->setRequestStatus(REQUEST_STATUS_READING_REQUEST);
                } else {
                    std::cout << "ServeRequestEventHandler connection has been reused as a keep-alive (fd = " << fd << ")." << std::endl;
                    this->setRequestStatus(REQUEST_STATUS_PROCESSING);
                    this->handleEvent();
                }
            }
        }
    }
}

std::vector<char> ServeRequestEventHandler::extractBodyFromHttpRequest(const std::vector<char> & httpRequest) const {
    const char *data = &httpRequest[0];
    const char *end = data + httpRequest.size();
    const char *delimiter = "\r\n\r\n";
    const char *pos = std::search(data, end, delimiter, delimiter + 4);

    if (pos != end) {
        return std::vector<char>(pos + 4, end);
    } else {
        return std::vector<char>();
    }
}

ssize_t ServeRequestEventHandler::getCurrentBodySize(const std::vector<char> & httpRequest) const {
    const char *data = &httpRequest[0];
    const char *end = data + httpRequest.size();
    const char *delimiter = "\r\n\r\n";
    const char *pos = std::search(data, end, delimiter, delimiter + 4);

    if (pos != end) {
        return (end - (pos + 4));
    }

    return 0;
}
