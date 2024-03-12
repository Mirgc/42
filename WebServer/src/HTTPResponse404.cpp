#include <sstream>

#include "HTTPResponse404.hpp"

HTTPResponse404::HTTPResponse404(std::string str)
{
	if (str.empty()) // This checks if the response is empty and if not, does the inline assignment
		str = "<!DOCTYPE html><html><body><h1>404 Not Found.</h1></body></html>";
	std::stringstream ss;

	ss << "HTTP/1.1 404\r\n"
	   << "Content-Type: text/html\r\n"
	   << "Content-Length: " << str.size()
	   << "\r\n\r\n"
	   << str;

	this->setResponse(ss.str());
}

HTTPResponse404::HTTPResponse404() {}

HTTPResponse404::~HTTPResponse404() {}

HTTPResponse404 &HTTPResponse404::operator=(const HTTPResponse404 &rhs)
{
	if (this != &rhs)
	{
	}
	return (*this);
}

HTTPResponse404::HTTPResponse404(const HTTPResponse404 &src) : HTTPResponse (src)
{
	*this = src;
}
