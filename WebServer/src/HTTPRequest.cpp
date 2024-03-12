#include "HTTPRequest.hpp"
#include "ServerConfig.hpp"
#include "LocationConfig.hpp"
#include "HTTPHeader.hpp"

HTTPRequest::HTTPRequest(
    const ServerConfig & serverConfig,
    const LocationConfig & location,
    const HTTPHeader & httpHeader
): serverConfig(serverConfig), location(location), httpHeader(httpHeader) {}

HTTPRequest::HTTPRequest(const HTTPRequest & src)
    :serverConfig(src.serverConfig), location(src.location), httpHeader(src.httpHeader) {
    *this = src;
}

HTTPRequest::~HTTPRequest() {}

HTTPRequest& HTTPRequest::operator=(const HTTPRequest &rhs) {
    if (this != &rhs) {
        this->serverConfig = rhs.serverConfig;
        this->httpHeader = rhs.httpHeader;
        this->location = rhs.location;
    }

	return (*this);
}
