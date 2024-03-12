#include <fstream>

#include "Path.hpp"
#include "StringTools.hpp"

Path::Path(void) {

}

Path::Path(Path const & src){
	*this = src;
}

Path::~Path(void){

}

Path & Path::operator=(Path const & rhs){
	if (this != &rhs){
	}
	return(*this);
}

std::string Path::concatenate(const std::string & docRoot, const std::string & path) {
    std::string docRootTrimmed = StringTools::trim(docRoot, "/");
    std::string pathTrimmed = StringTools::trim(path, "/");

    return docRootTrimmed + "/" + pathTrimmed;
}

bool Path::isFileAccessible(const std::string& filename) {
    std::ifstream file(filename.c_str());
    return file.good();
}
