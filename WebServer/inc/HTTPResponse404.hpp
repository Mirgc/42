#ifndef HTTP_RESPONSE_404_HPP
#define HTTP_RESPONSE_404_HPP

#include "HTTPResponse.hpp"

class HTTPResponse404 : public HTTPResponse
{
private:
    HTTPResponse404();
public:
    HTTPResponse404(std::string str);
    virtual ~HTTPResponse404();
    HTTPResponse404(const HTTPResponse404 &src);
    HTTPResponse404 &operator=(HTTPResponse404 const &rhs);
};

#endif
