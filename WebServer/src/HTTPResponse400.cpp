#include <sstream>

#include "HTTPResponse400.hpp"

HTTPResponse400::HTTPResponse400(std::string str)
{
	if (str.empty()) // This checks if the response is empty and if not, does the inline assignment
		str = "<!DOCTYPE html><html><body><h1>400 Bad Request.</h1></body></html>";
	std::stringstream ss;

	ss << "HTTP/1.1 400\r\n"
	   << "Content-Type: text/html\r\n"
	   << "Content-Length: " << str.size()
	   << "\r\n\r\n"
	   << str;

	this->setResponse(ss.str());
}

HTTPResponse400::HTTPResponse400() {}

HTTPResponse400::~HTTPResponse400() {}

HTTPResponse400 &HTTPResponse400::operator=(const HTTPResponse400 &rhs)
{
	if (this != &rhs)
	{
	}
	return (*this);
}

HTTPResponse400::HTTPResponse400(const HTTPResponse400 &src) : HTTPResponse (src)
{
	*this = src;
}
