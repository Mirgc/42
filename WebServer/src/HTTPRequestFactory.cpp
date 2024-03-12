#include "HTTPRequestFactory.hpp"
#include "StaticFileHTTPRequest.hpp"
#include "RedirectionHTTPRequest.hpp"
#include "ErrorHTTPRequest.hpp"
#include "CGIHTTPRequest.hpp"
#include "LocationConfig.hpp"
#include "ServerConfig.hpp"
#include "HTTPHeader.hpp"
#include "HTTPBody.hpp"
#include "UploadFileRequest.hpp"

HTTPRequestFactory::HTTPRequestFactory()
{
}

HTTPRequestFactory::HTTPRequestFactory(const HTTPRequestFactory &src)
{
    *this = src;
}

HTTPRequestFactory::~HTTPRequestFactory() {}

HTTPRequestFactory &HTTPRequestFactory::operator=(const HTTPRequestFactory &rhs)
{
    if (this != &rhs)
    {
    }

    return (*this);
}

HTTPRequest *HTTPRequestFactory::createHTTPRequest(const ServerConfig &serverConfig, const HTTPHeader &httpHeader, const HTTPBody &httpBody)
{

    // Types could be:
    // Static file request; find a file, read it, send content to client
    // Redirection request; Just send HTTP 3xx redirection headers to the client
    // CGI request; call the CGI and return its response to the client
    // Directory listing request; If directory, read all files and directories in it, produce an HTML page with it
    // Upload request
    // Any other?
    const LocationConfig &location = this->getLocationWithRequest(serverConfig, httpHeader);
    if (!location.isMethodInLocation(httpHeader.getMethod()))
    {
        return (new ErrorHTTPRequest(serverConfig, location, httpHeader, 405));
    }

    if(!location.getRedirection().empty()){
        return (new RedirectionHTTPRequest(serverConfig, location, httpHeader));
    }

	if (httpHeader.getMethod() == "POST" && serverConfig.getClientMaxBodySize()) {
		if (httpBody.getBodySize() > serverConfig.getClientMaxBodySize()) {
			// https://developer.mozilla.org/es/docs/Web/HTTP/Status/413
			return (new ErrorHTTPRequest(serverConfig, location, httpHeader, 413));
		}
	}
    if (location.isPyCgi()) {
        return (new CGIHTTPRequest(serverConfig, location, httpHeader, httpBody));
    }

    if (!httpHeader.getMethod().compare("POST")) {
        return (new UploadFileRequest(serverConfig, location, httpHeader, httpBody));
    }
    return (new StaticFileHTTPRequest(serverConfig, location, httpHeader));
}

const LocationConfig HTTPRequestFactory::getLocationWithRequest(
    const ServerConfig &serverConfig,
    const HTTPHeader &httpHeader
)
{
    std::vector<LocationConfig> locations = serverConfig.getLocations();
    for (size_t i = 0; i < locations.size(); ++i) {
        // Checks for cgi extension match
        if ( httpHeader.getUrl().find(".py") != std::string::npos &&
             locations[i].getLocationName().find(".py") != std::string::npos) {
            return locations[i];
        }

        // Checks for part starting with
        if (httpHeader.getUrl().find(locations[i].getLocationName()) == 0) {
            return locations[i];
        }
    }

    throw std::runtime_error("Location not found for path: " + httpHeader.getUrl());
}

