#include "HTTPResponse405.hpp"
#include <sstream>

HTTPResponse405::HTTPResponse405(std::string str)
{
	// This could be replaced by the configuration 405 error file set up if any.
	if (str.empty()) // This checks if the response is empty and if not, does the inline assignment
		str = "<!DOCTYPE html><html><body><h1>405 Method Not Allowed.</h1></body></html>";
	std::stringstream ss;

	ss << "HTTP/1.1 405\r\n"
	   << "Content-Type: text/html\r\n"
	   << "Content-Length: " << str.size()
	   << "\r\n\r\n"
	   << str;

	this->setResponse(ss.str());
}

HTTPResponse405::HTTPResponse405() {}

HTTPResponse405::~HTTPResponse405() {}

HTTPResponse405 &HTTPResponse405::operator=(const HTTPResponse405 &rhs)
{
	if (this != &rhs)
	{
	}
	return (*this);
}

HTTPResponse405::HTTPResponse405(const HTTPResponse405 &src) : HTTPResponse(src)
{
	*this = src;
}
