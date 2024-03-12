#ifndef HTTP_METHOD_HPP
#define HTTP_METHOD_HPP

#include <string>

typedef enum e_http_method
{
    HTTP_METHOD_NONE = 0,
    HTTP_METHOD_GET = 1,
    HTTP_METHOD_HEAD = 2,
    HTTP_METHOD_POST = 3,
    HTTP_METHOD_PUT = 4,
    HTTP_METHOD_DELETE = 5,
    HTTP_METHOD_CONNECT = 6,
    HTTP_METHOD_OPTIONS = 7,
    HTTP_METHOD_TRACE = 8,
    HTTP_METHOD_PATCH = 9
} t_http_method;

class HttpMethod
{
public:
    static t_http_method getMethod(std::string method);
    static std::string toString(t_http_method method);
};

#endif
