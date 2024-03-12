#ifndef HTTP_RESPONSE_413_HPP
#define HTTP_RESPONSE_413_HPP

#include "HTTPResponse.hpp"

class HTTPResponse413 : public HTTPResponse
{
private:
    HTTPResponse413();
public:
    HTTPResponse413(std::string str);
    virtual ~HTTPResponse413();
    HTTPResponse413(const HTTPResponse413 &src);
    HTTPResponse413 &operator=(HTTPResponse413 const &rhs);
};

#endif
