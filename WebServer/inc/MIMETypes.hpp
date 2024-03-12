#ifndef MIMETYPES_HPP
# define MIMETYPES_HPP
# include <iostream>
# include <map>

class MIMETypes{
	
	private:
		
		MIMETypes(void);
		MIMETypes(MIMETypes const & src);
		~MIMETypes(void);

		MIMETypes & operator=(MIMETypes const & rhs);

	public:

        static std::string getContentType(std::string str);
};

#endif
