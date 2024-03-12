#ifndef HTTP_RESPONSE_405_HPP
#define HTTP_RESPONSE_405_HPP

#include "HTTPResponse.hpp"

class HTTPResponse405 : public HTTPResponse
{
private:
    HTTPResponse405();

public:
    HTTPResponse405(std::string str);
    virtual ~HTTPResponse405();
    HTTPResponse405(const HTTPResponse405 &src);
    HTTPResponse405 &operator=(HTTPResponse405 const &rhs);
};

#endif
