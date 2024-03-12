#ifndef CONFIGFILEPARSER_H
# define CONFIGFILEPARSER_H

# include <string>
# include <iostream>
# include <sys/stat.h>
# include <unistd.h>
# include <fstream>
# include <sstream>
# include <vector>
# include <map>

class ConfigFileParser{
	protected:
		std::string 								_fileContent;
		std::vector<std::string>					_serverConfig;
		std::map<int, std::vector<std::string> > 	_eachServer;
		size_t										_numServ;

	public:
		ConfigFileParser();
		~ConfigFileParser();

		void checkFile(const std::string &fileName);
		bool isEmptyFile(const std::string &fileName);
		std::string removeCommentsWhiteLines(const std::string &fileName);
		std::vector<std::string>  const & getServerCfg(void) const;
		void splitServers();
		void eachServerCfg();

		class ParseException : public std::exception
		{
			private:
				std::string _message;
			public:
				ParseException(std::string message) throw(){
					_message = "ERROR: " + message;
				}
				virtual const char* what() const throw(){
					return (_message.c_str());
				}
				virtual ~ParseException() throw() {}
		};
};

std::ostream & operator<<(std::ostream & o, std::vector<std::string> const & rhs);

#endif
