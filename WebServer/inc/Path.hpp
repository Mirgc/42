
#ifndef PATH_HPP
# define PATH_HPP

#include <iostream>

class Path {
	
	private:
		
		Path(void);
		Path(Path const & src);
		~Path(void);

		Path & operator=(Path const & rhs);

	public:

        static std::string concatenate(const std::string & docRoot, const std::string & path);
        static bool isFileAccessible(const std::string& filename);

};

#endif
