#include <sstream>

#include "HTTPResponse413.hpp"

HTTPResponse413::HTTPResponse413(std::string str)
{
	if (str.empty()) // This checks if the response is empty and if not, does the inline assignment
        str = "<!DOCTYPE html><html><body><h1>413 Content Too Large.</h1></body></html>";
	std::stringstream ss;

	ss << "HTTP/1.1 413\r\n"
	   << "Content-Type: text/html\r\n"
	   << "Content-Length: " << str.size()
	   << "\r\n\r\n"
	   << str;

	this->setResponse(ss.str());
}

HTTPResponse413::HTTPResponse413() {}

HTTPResponse413::~HTTPResponse413() {}

HTTPResponse413 &HTTPResponse413::operator=(const HTTPResponse413 &rhs)
{
	if (this != &rhs)
	{
	}
	return (*this);
}

HTTPResponse413::HTTPResponse413(const HTTPResponse413 &src) : HTTPResponse (src)
{
	*this = src;
}
