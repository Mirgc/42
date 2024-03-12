#include "RedirectionHTTPRequest.hpp"
#include "HTTPResponse.hpp"
#include "HTTPResponse500.hpp"
#include "RequestTools.hpp"

RedirectionHTTPRequest::RedirectionHTTPRequest(
    const ServerConfig &serverConfig,
    const LocationConfig &location,
    const HTTPHeader &httpHeader) : HTTPRequest(serverConfig, location, httpHeader)
{
}

RedirectionHTTPRequest::RedirectionHTTPRequest(const RedirectionHTTPRequest &src)
    : HTTPRequest(src.serverConfig, src.location, src.httpHeader)
{
    *this = src;
}

RedirectionHTTPRequest::~RedirectionHTTPRequest() {}

RedirectionHTTPRequest &RedirectionHTTPRequest::operator=(const RedirectionHTTPRequest &rhs)
{
    (void)rhs;
    return (*this);
}

// We need a way to clone a derived instance not knowing its derived form
RedirectionHTTPRequest *RedirectionHTTPRequest::clone()
{
    return (new RedirectionHTTPRequest(*this));
}

HTTPResponse RedirectionHTTPRequest::process()
{
    HTTPResponse response;
    std::string redir;
    
    try
    {
        std::stringstream ss;
        
        ss.str("");  // Clean up the stringstream to reuse it
        ss << "HTTP/1.1 302 Found\r\n"
        << "Location:" << this->location.getRedirection() << "\r\n" 
        << "\r\n\r\n";
        response.setResponse(ss.str());
        return response;
    }
    catch (...)
    {
        return (HTTPResponse500(this->serverConfig.get500Content()));
    }
    return (response);
}
