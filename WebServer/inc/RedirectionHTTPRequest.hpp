#ifndef REDIRECTION_HTTP_REQUEST_HPP
#define REDIRECTION_HTTP_REQUEST_HPP

#include "HTTPRequest.hpp"

class HTTPResponse;
class LocationConfig;

class RedirectionHTTPRequest: public HTTPRequest {
public:
    RedirectionHTTPRequest(
        const ServerConfig & serverConfig,
        const LocationConfig & location,
        const HTTPHeader & httpHeader
    );
    RedirectionHTTPRequest(const RedirectionHTTPRequest & src);
    ~RedirectionHTTPRequest();

    RedirectionHTTPRequest & operator=(RedirectionHTTPRequest const & rhs);

    // We need a way to clone a derived instance not knowing its derived form
    RedirectionHTTPRequest * clone();

    HTTPResponse process();

};

#endif
