#include "RequestTools.hpp"

/* orthodox canonical class form requirement */
RequestTools::RequestTools(void) {

}

RequestTools::RequestTools(RequestTools const & src){
	*this = src;
}

RequestTools::~RequestTools(void){

}

RequestTools & RequestTools::operator=(RequestTools const & rhs){
	if (this != &rhs){
	}
	return(*this);
}

// Methods
bool RequestTools::isFile(const std::string &path)
{
    struct stat info;
    return stat(path.c_str(), &info) == 0 && S_ISREG(info.st_mode);
}

bool RequestTools::isDirectory(const std::string &path)
{
    DIR *directory = opendir(path.c_str());
    if (directory != NULL)
    {
        closedir(directory);
        return true;
    }
    return false;
}

std::string RequestTools::getResponse(const std::string& path)
{
    int fd = open(path.c_str(), O_RDONLY);
    if (fd == -1) {
        throw std::runtime_error("Failed to open the file");
    }

    std::stringstream ss;
    const int bufferSize = 4096;
    char buffer[bufferSize];
    ssize_t bytesReaded;

    while ((bytesReaded = read(fd, buffer, sizeof(buffer))) > 0) {
        ss.write(buffer, bytesReaded);
    }

    if (bytesReaded == -1) {
        throw std::runtime_error("Failed to read from file");
    }

    close(fd);

    std::string content = ss.str();
    
    ss.str("");  // Clean up the stringstream to reuse it
    ss << "HTTP/1.1 200 OK\r\n"
    << "Content-Type: "
    << MIMETypes::getContentType(path)
    << "\r\n"
    << "Content-Length: " << content.size()
    << "\r\n\r\n"
    << content;

    return ss.str();

}

std::string RequestTools::intToString(int value) {
    std::ostringstream oss;
    oss << value;
    return oss.str();
}

void RequestTools::removeSubstring(std::string& mainString, const std::string& substringToRemove) {
    size_t pos = mainString.find(substringToRemove);
    if (pos != std::string::npos) {
        mainString.erase(pos, substringToRemove.length());
    }
}
