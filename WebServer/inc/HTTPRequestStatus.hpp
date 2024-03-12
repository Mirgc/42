#ifndef HTTP_REQUEST_STATUS
#define HTTP_REQUEST_STATUS

#include <string>

typedef enum e_http_request_status
{
    // Serving the request process has not yet started.
    REQUEST_STATUS_WAITING = 0,

    // We have received none or part of the request. Not all.
    REQUEST_STATUS_READING_REQUEST = 1,

    // We are currently processing the request; calling cgi, reading file, etc...
    REQUEST_STATUS_PROCESSING = 2,
    // Incoming request has been fully processed.
    REQUEST_STATUS_PROCESSING_COMPLETE = 3,

    // We have sent none or part of the request to the client. Not all.
    REQUEST_STATUS_SENDING = 4,
    // Incoming request has been fully sent to the client.
    REQUEST_STATUS_SENDING_COMPLETE = 5,

    REQUEST_STATUS_CLOSED_OK = 6,
    REQUEST_STATUS_CLOSED_ERROR = 7
} t_http_request_status;

class HTTPRequestStatus {
public:
    HTTPRequestStatus();
    HTTPRequestStatus(const HTTPRequestStatus & src);
    virtual ~HTTPRequestStatus();

    HTTPRequestStatus & operator=(HTTPRequestStatus const & rhs);
    operator std::string();
    std::string toString(t_http_request_status status);

    t_http_request_status getStatus();
    void setStatus(t_http_request_status status);

private:

    t_http_request_status status;
};

#endif
