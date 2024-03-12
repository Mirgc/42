#ifndef HTTP_REQUEST_HPP
#define HTTP_REQUEST_HPP

#include "LocationConfig.hpp"
#include "HTTPResponse.hpp"
#include "ServerConfig.hpp"
#include "HTTPHeader.hpp"

class HTTPRequest {
public: 
    HTTPRequest(
        const ServerConfig & serverConfig,
        const LocationConfig & location,
        const HTTPHeader & httpHeader
    );
    HTTPRequest(const HTTPRequest & src);
    virtual ~HTTPRequest();

    HTTPRequest & operator=(HTTPRequest const & rhs);

    // We need a way to clone a derived instance not knowing its derived form
    virtual HTTPRequest* clone() = 0;
    virtual HTTPResponse process() = 0;

    ServerConfig serverConfig;
    LocationConfig location;
    HTTPHeader httpHeader;
};

#endif
