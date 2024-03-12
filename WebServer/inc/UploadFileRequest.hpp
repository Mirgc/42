#ifndef UPLOAD_FILE_REQUEST_HPP
#define UPLOAD_FILE_REQUEST_HPP

#include "HTTPRequest.hpp"
#include "HTTPBody.hpp"


class HTTPResponse;

class UploadFileRequest: public HTTPRequest {
public:
     UploadFileRequest(
        const ServerConfig & serverConfig,
        const LocationConfig & location,
        const HTTPHeader & httpHeader,
        const HTTPBody &httpBody
    );
    UploadFileRequest(const UploadFileRequest & src);
    ~UploadFileRequest();

    UploadFileRequest & operator=(UploadFileRequest const & rhs);

    // We need a way to clone a derived instance not knowing its derived form
    UploadFileRequest * clone();


    HTTPResponse process();
    const HTTPBody & httpBody;

};

#endif
