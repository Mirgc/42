#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <fcntl.h>
#include <vector>

#include "UploadFileRequest.hpp"
#include "HTTPResponse.hpp"
#include "HTTPResponse400.hpp"
#include "HTTPResponse404.hpp"
#include "HTTPResponse500.hpp"
#include "MIMETypes.hpp"

UploadFileRequest::UploadFileRequest(
    const ServerConfig &serverConfig,
    const LocationConfig &location,
    const HTTPHeader &httpHeader,
    const HTTPBody &httpBody) : HTTPRequest(serverConfig, location, httpHeader), httpBody(httpBody)
{
}

UploadFileRequest::UploadFileRequest(const UploadFileRequest &src)
    : HTTPRequest(src.serverConfig, src.location, src.httpHeader), httpBody(src.httpBody)
{
    *this = src;
}

UploadFileRequest::~UploadFileRequest() {}

UploadFileRequest &UploadFileRequest::operator=(const UploadFileRequest &rhs)
{
    (void)rhs;
    return (*this);
}

// We need a way to clone a derived instance not knowing its derived form
UploadFileRequest *UploadFileRequest::clone()
{
    return (new UploadFileRequest(*this));
}

std::string getBoundary(const std::string &contentTypeHeader)
{
    // Buscar la posición de "boundary="
    size_t posBoundary = contentTypeHeader.find("boundary=");

    // Verificar si se encontró "boundary="
    if (posBoundary != std::string::npos)
    {
        // Extraer la cadena después de "boundary="
        return contentTypeHeader.substr(posBoundary + 9);
    }
    else
    {
        // "boundary=" no encontrado
        return "";
    }
}

HTTPResponse UploadFileRequest::process()
{
    HTTPResponse response;

    std::string boundary = getBoundary(this->httpHeader.getHeaderValueWithKey("Content-Type"));
    if (boundary.empty()) {
        // Must be a 400 error
        return HTTPResponse400(this->serverConfig.get400Content());
    }

    boundary = "--" + boundary;
    
    std::vector<char> bodyVec = httpBody.getFullBody();
    std::string body(bodyVec.begin(), bodyVec.end());

    // Find the limit of the boundary
    size_t pos = body.find(boundary);
    if (pos == std::string::npos)
    {
        return HTTPResponse404(this->serverConfig.get404Content());
    }

    // Extract Content-Disposition and filename
    size_t start = body.find("Content-Disposition: ", pos);
    size_t end = body.find("\r\n\r\n", start);
    if (start == std::string::npos || end == std::string::npos)
    {
        return HTTPResponse404(this->serverConfig.get404Content());
    }

    std::string contentDisposition = body.substr(start, end - start);
    size_t filenamePos = contentDisposition.find("filename=\"");
    if (filenamePos == std::string::npos)
    {
        return HTTPResponse404(this->serverConfig.get404Content());
    }

    filenamePos += 10; // "filename=\" size"
    size_t filenameEnd = contentDisposition.find("\"", filenamePos);
    std::string filename = contentDisposition.substr(filenamePos, filenameEnd - filenamePos);

    // Take content from the file
    size_t contentStart = end + 4; // "\r\n\r\n" size
    size_t contentEnd = body.find(boundary, contentStart);
    std::string fileContent = body.substr(contentStart, contentEnd - contentStart);
    // Change to the specific getter
    filename = this->location.getUploadPath() + "/" + filename;
    // Save content in the file
    FILE *outFile = std::fopen(filename.c_str(), "wb");
    if (outFile == NULL)
    {
        return HTTPResponse500(this->serverConfig.get500Content());
    }
    std::fwrite(fileContent.c_str(), 1, fileContent.size(), outFile);
    std::fclose(outFile);

    std::string responseBody =
        "<!DOCTYPE html>"
        "<html>"
        "<head>"
        "    <title>HTTP 201 Created</title>"
        "</head>"
        "<body>"
        "    <h1>HTTP 201 Created</h1>"
        "    <p>La operación se realizó con éxito.</p>"
        "</body>"
        "</html>";

    std::stringstream ss;
    ss << "HTTP/1.1 201 Created\r\n";
    ss << "Content-Length: " << responseBody.size() << "\r\n";
    ss << "Content-Type: text/html\r\n";
    ss << "\r\n"; // End of the headers
    ss << responseBody;
    response.setResponse(ss.str());
    return (response);
}
