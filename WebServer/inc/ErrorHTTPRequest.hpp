#ifndef ERROR_HTTP_REQUEST_HPP
#define ERROR_HTTP_REQUEST_HPP

#include "HTTPRequest.hpp"

class HTTPResponse;
class LocationConfig;

class ErrorHTTPRequest: public HTTPRequest {
public:
    ErrorHTTPRequest(
        const ServerConfig & serverConfig,
        const LocationConfig & location,
        const HTTPHeader & httpHeader,
        const int httpResponseStatusCode
    );
    ErrorHTTPRequest(const ErrorHTTPRequest & src);
    ~ErrorHTTPRequest();

    ErrorHTTPRequest & operator=(ErrorHTTPRequest const & rhs);

    // We need a way to clone a derived instance not knowing its derived form
    ErrorHTTPRequest * clone();

    HTTPResponse process();

private:

    int httpResponseStatusCode;

};

#endif
