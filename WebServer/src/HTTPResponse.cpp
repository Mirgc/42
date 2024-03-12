#include "HTTPResponse.hpp"

HTTPResponse::HTTPResponse() {
    this->totalBytesSentToClient = 0;
}

HTTPResponse::HTTPResponse(const HTTPResponse & src) {
    *this = src;
}

HTTPResponse::~HTTPResponse() {}

HTTPResponse& HTTPResponse::operator=(const HTTPResponse &rhs) {
	if (this != &rhs) {
        this->setResponse(rhs.response);
        this->totalBytesSentToClient = rhs.totalBytesSentToClient;
    }

	return (*this);
}

const std::vector<char> & HTTPResponse::getFullResponse() {
	return (this->response);
}

std::vector<char> HTTPResponse::getNextResponseChunkToBeSent() {
    if (!this->getTotalBytesSentToClient()) {
        return (this->getFullResponse());
    }

    // Create a copy of the response vector starting from totalBytesSentToClient to the end
    std::vector<char> nextChunk(this->response.begin() + this->totalBytesSentToClient, this->response.end());

    // Return the next chunk
    return (nextChunk);
}

ssize_t HTTPResponse::getResponseSize() {
	return (this->response.size());
}

void HTTPResponse::setResponse(const std::vector<char> & response) {
	this->response = response;
}

void HTTPResponse::setResponse(const std::string & response) {
    this->setResponse(std::vector<char>(response.begin(), response.end()));
}

ssize_t HTTPResponse::getTotalBytesSentToClient() {
    return this->totalBytesSentToClient;
}

void HTTPResponse::addBytesSentToClient(ssize_t bytesSentToClient) {
    this->totalBytesSentToClient += bytesSentToClient;
}

bool HTTPResponse::isRequestFullySent() {
    return this->getTotalBytesSentToClient() >= this->getResponseSize();
}
