#ifndef HTTP_RESPONSE_400_HPP
#define HTTP_RESPONSE_400_HPP

#include "HTTPResponse.hpp"

class HTTPResponse400 : public HTTPResponse
{
private:
    HTTPResponse400();
public:
    HTTPResponse400(std::string str);
    virtual ~HTTPResponse400();
    HTTPResponse400(const HTTPResponse400 &src);
    HTTPResponse400 &operator=(HTTPResponse400 const &rhs);
};

#endif
