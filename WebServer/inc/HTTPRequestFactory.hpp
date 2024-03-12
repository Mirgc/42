#ifndef HTTP_REQUEST_FACTORY_HPP
#define HTTP_REQUEST_FACTORY_HPP

#include "HTTPRequest.hpp"

class ServerConfig;
class HTTPHeader;
class HTTPBody;

class HTTPRequestFactory {
public:
    HTTPRequestFactory();
    HTTPRequestFactory(const HTTPRequestFactory & src);
    virtual ~HTTPRequestFactory();

    HTTPRequestFactory & operator=(HTTPRequestFactory const & rhs);

    // TODO: add parameters so that the factory knows what concrete instance should create
    HTTPRequest * createHTTPRequest(const ServerConfig &serverConfig, const HTTPHeader & httpHeader, const HTTPBody & httpBody);

    const LocationConfig getLocationWithRequest(
        const ServerConfig &serverConfig,
        const HTTPHeader &httpHeader
    );
};

#endif
