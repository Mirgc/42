
#ifndef REQUESTTOOLS_HPP
# define REQUESTTOOLS_HPP
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <fcntl.h>

#include "StaticFileHTTPRequest.hpp"
#include "HTTPResponse.hpp"
#include "HTTPResponse404.hpp"
#include "HTTPResponse500.hpp"
#include "MIMETypes.hpp"

class RequestTools{
	
	private:
		RequestTools(void);
		RequestTools(RequestTools const & src);
		~RequestTools(void);

		RequestTools & operator=(RequestTools const & rhs);

	public:
        static bool isFile(const std::string &path);
        static bool isDirectory(const std::string &path);
        static std::string getResponse(const std::string& path);
        static std::string intToString(int value);
        static void removeSubstring(std::string& mainString, const std::string& substringToRemove);

};

#endif
