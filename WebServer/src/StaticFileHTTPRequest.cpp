#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <fcntl.h>
#include <cstdlib>

#include "StaticFileHTTPRequest.hpp"
#include "HTTPResponse.hpp"
#include "HTTPResponse404.hpp"
#include "HTTPResponse500.hpp"
#include "MIMETypes.hpp"

StaticFileHTTPRequest::StaticFileHTTPRequest(
    const ServerConfig &serverConfig,
    const LocationConfig &location,
    const HTTPHeader &httpHeader) : HTTPRequest(serverConfig, location, httpHeader)
{
}

StaticFileHTTPRequest::StaticFileHTTPRequest(const StaticFileHTTPRequest &src)
    : HTTPRequest(src.serverConfig, src.location, src.httpHeader)
{
    *this = src;
}

StaticFileHTTPRequest::~StaticFileHTTPRequest() {}

StaticFileHTTPRequest &StaticFileHTTPRequest::operator=(const StaticFileHTTPRequest &rhs)
{
    (void)rhs;
    return (*this);
}

// We need a way to clone a derived instance not knowing its derived form
StaticFileHTTPRequest *StaticFileHTTPRequest::clone()
{
    return (new StaticFileHTTPRequest(*this));
}

std::string StaticFileHTTPRequest::generateAutoindexPage(const std::string& directoryPath) {
    
    std::string htmlPage = "<html><head></head><body>\n";

    // we have to check what happens when we move through the files.
    // Read the contents of the directory
    DIR* dir = opendir(directoryPath.c_str());
    std::string dc = directoryPath.c_str();
    RequestTools::removeSubstring(dc, this->location.getDocroot());
    size_t lastPosition = dc.find_last_of('/');
    if (lastPosition != std::string::npos && lastPosition != dc.length() - 1) {
        dc += "/";
    }
    if (dir != NULL) {
        struct dirent* entry;
        while ((entry = readdir(dir)) != NULL) {
            htmlPage += "<li><a href=\"" + dc + std::string(entry->d_name) + "\">" + std::string(entry->d_name) + "</a></li>";
        }

        closedir(dir);
    } else {
        throw std::runtime_error("Failed to create a listening socket");
    }

    htmlPage += "</body></html>";
    int length = static_cast<int>(htmlPage.length());
    std::string htmlPageF = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\nContent-Length: " + RequestTools::intToString(length) + "\r\n\r\n" + htmlPage;
    return htmlPageF;
}

std::string fileDeleted() {
    std::string response;
    response += "HTTP/1.1 200 OK\r\n";
    response += "Content-Length: 0\r\n";
    response += "\r\n";  // Fin de las cabeceras
    return response;
}

HTTPResponse StaticFileHTTPRequest::process()
{
    HTTPResponse response;
    std::string pathComplete;
    // I have to make sure that when concatenating the paths, there is no / tucked in between.
    try
    {
        pathComplete = this->location.getDocroot() + this->httpHeader.getUrl();
        if (RequestTools::isFile(pathComplete))
        {
            if (!this->httpHeader.getMethod().compare("DELETE") && this->location.isMethodInLocation(this->httpHeader.getMethod()))
            {
                if (std::remove(pathComplete.c_str()) == 0)
                {
                    response.setResponse(fileDeleted());
                    return response;
                }
                else
                    return (HTTPResponse500(this->serverConfig.get500Content()));
            }
            response.setResponse(RequestTools::getResponse(pathComplete));
        }
        else if (RequestTools::isDirectory(pathComplete))
        {
            size_t lastPosition = pathComplete.find_last_of('/');
            if (lastPosition != std::string::npos && lastPosition != pathComplete.length() - 1) {
                pathComplete += "/";
            }
            if (!this->location.getAutoIndexBool())
            {
                pathComplete += this->location.getIndex();
                if (RequestTools::isFile(pathComplete))
                {
                    response.setResponse(RequestTools::getResponse(pathComplete));
                }
                else
                    return HTTPResponse404(this->serverConfig.get404Content());
            }
            else 
            {
                response.setResponse(this->generateAutoindexPage(pathComplete));
            }
        }
        else
            return HTTPResponse404(this->serverConfig.get404Content());
        return response;
    }
    catch (...)
    {
        return (HTTPResponse500(this->serverConfig.get500Content()));
    }
    return (response);
}
