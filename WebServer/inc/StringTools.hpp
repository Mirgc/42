
#ifndef STRINGTOOLS_HPP
# define STRINGTOOLS_HPP
#include <iostream>

class StringTools{
	
	private:
		std::string _toTrim;
        std::string _string;
		
		StringTools(void);
		StringTools(const std::string toTrim, const std::string string);
		StringTools(StringTools const & src);
		~StringTools(void);

		StringTools & operator=(StringTools const & rhs);

	public:
		// string trim method support functions
        // totrim is a default argument if no explicit one is passed
        static std::string ltrim(const std::string &s, std::string totrim = " }\n\r\t\f\v{");

        static std::string rtrim(const std::string &s, std::string totrim = " }\n\r\t\f\v{");

        static std::string trim(const std::string &s, std::string totrim = " }\n\r\t\f\v{");

        static std::string toUpper(const std::string& s);
        static std::string toLower(const std::string& s);
};

#endif
