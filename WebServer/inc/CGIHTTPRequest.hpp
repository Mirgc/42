#ifndef CGI_HTTP_REQUEST_HPP
#define CGI_HTTP_REQUEST_HPP

#include "HTTPRequest.hpp"
#include "HTTPBody.hpp"

class HTTPResponse;
class LocationConfig;

class CGIHTTPRequest : public HTTPRequest
{
public:
	CGIHTTPRequest(
		const ServerConfig &serverConfig,
		const LocationConfig &location,
		const HTTPHeader &httpHeader,
        const HTTPBody &httpBody
    );
	CGIHTTPRequest(const CGIHTTPRequest &src);
	~CGIHTTPRequest();

	CGIHTTPRequest &operator=(CGIHTTPRequest const &rhs);

	// We need a way to clone a derived instance not knowing its derived form
	CGIHTTPRequest *clone();

	HTTPResponse process();

private:

    std::string execCGI(std::string cgiScriptRelativePath, std::string queryString);
    std::string getAbsolutePath(const std::string& relativePath);
    char** createEnvironment(const std::string& cgiScriptAbsolutePath, const std::string& queryString);
    char** createArgs(const std::string& cgiInterpreter, const std::string& cgiScriptAbsolutePath, const std::string& queryString);
    char** createCharPtrArray(const std::vector<std::string>& strings);
    std::string readFromPipe(int pipefd);

    const HTTPBody & httpBody;

};

#endif
