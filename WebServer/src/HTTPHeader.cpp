#include "HTTPHeader.hpp"
#include "StringTools.hpp"
#include <sstream>
#include <algorithm>

HTTPHeader::HTTPHeader(void)
{
}

HTTPHeader::~HTTPHeader(void)
{
}

HTTPHeader::HTTPHeader(const HTTPHeader &src)
{
	*this = src;
}

HTTPHeader &HTTPHeader::operator=(HTTPHeader const &src)
{
	if (this != &src)
	{
		this->header = src.header;
		this->method = src.method;
		this->url = src.url;
		this->ver = src.ver;
	}
	return (*this);
}

std::string HTTPHeader::getMethod() const
{
	return (this->method);
}

std::string HTTPHeader::getUrl(bool removeQueryString) const
{
    if (!removeQueryString) {
        return (this->url);
    }

    std::size_t queryPosition = this->url.find("?");
    if (queryPosition != std::string::npos)
        return this->url.substr(0, queryPosition);
    else
        return this->url;

}

bool HTTPHeader::isMethod(std::string str) const
{
	for (std::vector<std::pair<std::string, std::string> >::const_iterator it = this->header.begin(); it != this->header.end(); ++it)
	{
		if (it->first == str)
		{
			return true;
		}
	}
	return false;
}

std::string HTTPHeader::getQueryString(void)
{
	size_t queryPosition = this->url.find('?');

	if (queryPosition != std::string::npos)
	{
		return this->url.substr(queryPosition + 1);
	}
	return "";
}

bool HTTPHeader::addMethod(std::string line)
{
	std::istringstream lineStream(line);
	lineStream >> this->method >> this->url >> this->ver;
    this->method = StringTools::toUpper(this->method);
    this->url = StringTools::toLower(this->url);
    this->ver = StringTools::toUpper(this->ver);
	std::string restOfTheContent;
	std::getline(lineStream, restOfTheContent);
	if (!restOfTheContent.compare("\r")) // If there is a space even after 1.1, it fails
		return false;
	return true;
}

void HTTPHeader::addHeader(const std::string &key, const std::string &value)
{
	this->header.push_back(std::make_pair(StringTools::toLower(key), value));
}

std::string HTTPHeader::getHeaderValueWithKey(const std::string & key) const
{
    std::string lowercaseKey = StringTools::toLower(key);
	for (size_t i = 0; i < this->header.size(); ++i)
	{
        if (this->header[i].first == lowercaseKey) {
            return this->header[i].second;
        }
	}

    return std::string();
}

std::string HTTPHeader::generateResponse(void) const
{
	std::string response;

	response += this->method + " " + this->url + "\n"; // HTTP status
	for (size_t i = 0; i < this->header.size(); ++i)
	{
		response += this->header[i].first + ": " + this->header[i].second + "\n";
	}
	return response;
}

bool HTTPHeader::checkMethod(void) const
{
	// t_http_method HttpMethod::getMethod(std::string method)
	//  Here we are going to check that the version is correct. It could be checked that the method was valid.
	if (this->method.empty() || this->url.empty() || this->ver.empty() || this->ver.compare("HTTP/1.1") != 0)
		return false;
	const std::string allowedMethods[] = {"GET", "DELETE", "POST"};
	const size_t numMethods = sizeof(allowedMethods) / sizeof(allowedMethods[0]);
	bool ver = false;
	// Check if this->method is in the array
	for (size_t i = 0; i < numMethods; ++i)
	{
		if (allowedMethods[i] == this->method)
		{
			ver = true;
			break; // Method found, exit loop
		}
	}
	return ver;
}

bool HTTPHeader::parseHTTPHeader(const std::vector<char> &request)
{
    this->clear();

    std::string requestStr(request.begin(), request.end());
    std::istringstream iss(requestStr);
	std::string line;
	std::string tmp;

	std::getline(iss, line);
	if (this->addMethod(line) || !this->checkMethod())
	{
		std::cout << "Invalid HTTPRequest" << std::endl;
		return false;
	}

	while (std::getline(iss, line))
	{
		line = StringTools::trim(line, " \n\r\t");
		size_t pos = line.find(':');
		if (pos != std::string::npos && pos > 0 && pos < line.length() - 1) // Now we have to see if we can empty something.
		// What happens if we put two identical ones?
		{
			std::string key = line.substr(0, pos);
			std::string value = line.substr(pos + 1);												   // +1 for omitting the ':' after the header
			this->addHeader(StringTools::rtrim(key, " \n\r\t"), StringTools::ltrim(value, " \n\r\t")); // the rtrim(key), in reality, is not done.
		}
		else
		{
			if (line.compare(""))
				std::cout << "Bad description" << std::endl;
			else
				// Here we have found an empty line, so we assume that the boy begins;
				// std::cout << "Checkbody" << std::endl;
				return true;
		}
	}

    return true;
}

void HTTPHeader::printHeader(void) const
{
	std::cout << "Method: " << this->method << std::endl;
	std::cout << "URL: " << this->url << std::endl;
	std::cout << "Version: " << this->ver << std::endl;
	for (size_t i = 0; i < this->header.size(); ++i)
	{
		std::cout << this->header[i].first << ": " << this->header[i].second;
		std::cout << std::endl;
	}
}

void HTTPHeader::clear(void) {
    this->header.clear();
    this->method.clear();
    this->url.clear();
    this->ver.clear();
}
