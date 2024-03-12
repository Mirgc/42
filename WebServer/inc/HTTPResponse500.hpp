#ifndef HTTP_RESPONSE_500_HPP
#define HTTP_RESPONSE_500_HPP

#include "HTTPResponse.hpp"

class HTTPResponse500 : public HTTPResponse
{
private:
    HTTPResponse500();
public:
    HTTPResponse500(std::string str);
    virtual ~HTTPResponse500();
    HTTPResponse500(const HTTPResponse500 &src);
    HTTPResponse500 &operator=(HTTPResponse500 const &rhs);
};

#endif
