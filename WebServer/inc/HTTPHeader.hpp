#ifndef HTTPHEADER_H
#define HTTPHEADER_H
#include <iostream>
#include <vector>
#include <string>

class HTTPHeader
{
	private:

	public:
		HTTPHeader(void);
		HTTPHeader(const HTTPHeader & src);
		HTTPHeader & operator=(HTTPHeader const & src);
		~HTTPHeader(void);

		std::vector<std::pair<std::string, std::string> > header;
		std::string method;
		std::string url;
		std::string ver;

		std::string getMethod() const;
        std::string getUrl(bool removeQueryString = true) const;

		void		addHeader(const std::string & value1, const std::string & value2);
		std::string getHeaderValueWithKey(const std::string & key) const;
		bool		addMethod(std::string line);
		void		printHeader(void) const;
		bool		checkMethod(void) const;
		bool		isMethod(std::string str) const;
		std::string	generateResponse(void) const;
		bool		parseHTTPHeader (const std::vector<char>& request);
		std::string getQueryString(void);

        void        clear();

};

#endif
