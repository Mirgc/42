#include <sstream>

#include "HTTPResponse500.hpp"

HTTPResponse500::HTTPResponse500(std::string str) {
	// This could be replaced by the configuration 500 error file set up if any.
	if (str.empty()) // This checks if the response is empty and if not, does the inline assignment
    	str = "<!DOCTYPE html><html><body><h1>500 Internal error.</h1></body></html>";
	std::stringstream ss;

	ss << "HTTP/1.1 500\r\n"
		<< "Content-Type: text/html\r\n"
		<< "Content-Length: " << str.size()
		<< "\r\n\r\n"
		<< str;

	this->setResponse(ss.str());
}

HTTPResponse500::HTTPResponse500() {}

HTTPResponse500::~HTTPResponse500() {}

HTTPResponse500 &HTTPResponse500::operator=(const HTTPResponse500 &rhs)
{
	if (this != &rhs) {
    }
	return (*this);
}

HTTPResponse500::HTTPResponse500(const HTTPResponse500 &src) : HTTPResponse(src)
{
	*this = src;
}
