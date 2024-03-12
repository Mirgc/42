#include <sstream>

#include "HTTPResponse504.hpp"

HTTPResponse504::HTTPResponse504(std::string str) {
	if (str.empty())
    	str = "<!DOCTYPE html><html><body><h1>504 Gateway Timeout</h1></body></html>";
	std::stringstream ss;

	ss << "HTTP/1.1 504\r\n"
		<< "Content-Type: text/html\r\n"
		<< "Content-Length: " << str.size()
		<< "\r\n\r\n"
		<< str;

	this->setResponse(ss.str());
}

HTTPResponse504::HTTPResponse504() {}

HTTPResponse504::~HTTPResponse504() {}

HTTPResponse504 &HTTPResponse504::operator=(const HTTPResponse504 &rhs)
{
	if (this != &rhs) {
    }
	return (*this);
}

HTTPResponse504::HTTPResponse504(const HTTPResponse504 &src) : HTTPResponse(src)
{
	*this = src;
}
