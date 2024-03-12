#include "HTTPMethod.hpp"

t_http_method HttpMethod::getMethod(std::string method)
{
    if (method == "GET")
        return HTTP_METHOD_GET;
    else if (method == "HEAD")
        return HTTP_METHOD_HEAD;
    else if (method == "DELETE")
        return HTTP_METHOD_DELETE;
    else if (method == "POST")
        return HTTP_METHOD_POST;
    else if (method == "PUT")
        return HTTP_METHOD_PUT;
    else if (method == "CONNECT")
        return HTTP_METHOD_CONNECT;
    else if (method == "OPTIONS")
        return HTTP_METHOD_OPTIONS;
    else if (method == "TRACE")
        return HTTP_METHOD_TRACE;
    else if (method == "PATCH")
        return HTTP_METHOD_PATCH;

    return HTTP_METHOD_NONE;
}

std::string HttpMethod::toString(t_http_method method)
{
    switch (method)
    {
    case HTTP_METHOD_GET:
        return "GET";
    case HTTP_METHOD_HEAD:
        return "HEAD";
    case HTTP_METHOD_POST:
        return "POST";
    case HTTP_METHOD_PUT:
        return "PUT";
    case HTTP_METHOD_DELETE:
        return "DELETE";
    case HTTP_METHOD_CONNECT:
        return "CONNECT";
    case HTTP_METHOD_OPTIONS:
        return "OPTIONS";
    case HTTP_METHOD_TRACE:
        return "TRACE";
    case HTTP_METHOD_PATCH:
        return "PATCH";
    default:
        return "NONE";
    }
}
