#ifndef HTTP_RESPONSE_504_HPP
#define HTTP_RESPONSE_504_HPP

#include "HTTPResponse.hpp"

class HTTPResponse504 : public HTTPResponse
{
private:
    HTTPResponse504();
public:
    HTTPResponse504(std::string str);
    virtual ~HTTPResponse504();
    HTTPResponse504(const HTTPResponse504 &src);
    HTTPResponse504 &operator=(HTTPResponse504 const &rhs);
};

#endif
