#ifndef HTTP_BODY_H
#define HTTP_BODY_H

#include <iostream>
#include <vector>
#include <string>

class HTTPBody
{
	public:
		HTTPBody(void);
		HTTPBody(const HTTPBody & src);
		HTTPBody & operator=(HTTPBody const & src);
		~HTTPBody(void);

		void                        setBody(const std::vector<char> & bodyChunk);
        const std::vector<char> &   getFullBody(void) const;
        std::size_t                 getBodySize(void) const;
        std::string                 getBodySizeString(void) const;

	private:
		std::vector<char> body;

};

#endif
