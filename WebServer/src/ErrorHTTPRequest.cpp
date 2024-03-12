#include <string>
#include <sstream>
#include <fstream>
#include <iostream>

#include "ErrorHTTPRequest.hpp"
#include "HTTPResponse.hpp"
#include "HTTPResponse400.hpp"
#include "HTTPResponse404.hpp"
#include "HTTPResponse405.hpp"
#include "HTTPResponse413.hpp"
#include "HTTPResponse500.hpp"
#include "HTTPResponse504.hpp"

ErrorHTTPRequest::ErrorHTTPRequest(
    const ServerConfig & serverConfig,
    const LocationConfig & location,
    const HTTPHeader & httpHeader,
    const int httpResponseStatusCode
): HTTPRequest(serverConfig, location, httpHeader) {
    this->httpResponseStatusCode = httpResponseStatusCode;
}

ErrorHTTPRequest::ErrorHTTPRequest(const ErrorHTTPRequest & src)
    : HTTPRequest(src.serverConfig, src.location, src.httpHeader) {
        *this = src;
}

ErrorHTTPRequest::~ErrorHTTPRequest() {}

ErrorHTTPRequest& ErrorHTTPRequest::operator=(const ErrorHTTPRequest &rhs) {
	if (this != &rhs) {
        this->httpResponseStatusCode = rhs.httpResponseStatusCode;
    }
	return (*this);
}

// We need a way to clone a derived instance not knowing its derived form
ErrorHTTPRequest * ErrorHTTPRequest::clone() {
    return (new ErrorHTTPRequest(*this));
}

HTTPResponse ErrorHTTPRequest::process() {
    try {
        if (this->httpResponseStatusCode >= 400 && this->httpResponseStatusCode < 500) {
            if (this->httpResponseStatusCode == 404) {
                return HTTPResponse404(this->serverConfig.get404Content());
            } else if (this->httpResponseStatusCode == 405) {
                return HTTPResponse405(this->serverConfig.get405Content());
            } else if (this->httpResponseStatusCode == 413) {
                return HTTPResponse413(this->serverConfig.get413Content());
            }
            return HTTPResponse400(this->serverConfig.get400Content());
        }
        else if (this->httpResponseStatusCode >= 500 && this->httpResponseStatusCode < 600) {
            if (this->httpResponseStatusCode == 504) {
                return HTTPResponse504(this->serverConfig.get504Content());
            }
            return (HTTPResponse500(this->serverConfig.get500Content()));
        }

        std::cout << "ErrorHTTPRequest: Not supportted http response status code: " << this->httpResponseStatusCode << std::endl;

    } catch (...) {
        return (HTTPResponse500(this->serverConfig.get500Content()));
    }
    return (HTTPResponse500(this->serverConfig.get500Content()));
}

