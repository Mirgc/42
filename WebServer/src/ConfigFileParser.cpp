#include "ConfigFileParser.hpp"

ConfigFileParser::ConfigFileParser(){
}

ConfigFileParser::~ConfigFileParser(){
}

// TODO: Change checkfile method this fails too many times
void ConfigFileParser::checkFile(const std::string &fileName){
	struct stat	fileInfo; //Structure that gives us information about the file

        if (stat(fileName.c_str(), &fileInfo) != -1){ // If when trying to get the status it gives an error
			if (fileInfo.st_mode & S_IFREG) { // If it is a route but empty, without indicating a file
				if (access(fileName.c_str(), R_OK) == 0) { // We have read permissions on the file
			        if (isEmptyFile(fileName)) // The file is empty or contains only white spaces
						throw ParseException("File is empty.");
					else{
						this->_fileContent = removeCommentsWhiteLines(fileName);
						splitServers();
						eachServerCfg();
					}
				}
				else
					throw ParseException("Access denied.");
			}
			else
				throw ParseException("File is invalid");
        }
        else
			throw ParseException("File is invalid");

}

bool ConfigFileParser::isEmptyFile(const std::string &fileName){
	std::ifstream	file(fileName.c_str());
	char			ch;

	while (file.get(ch)){
		if(!isspace(static_cast<unsigned char>(ch))){
			file.close();
			return false;
		}
	}
	file.close();
	return true;
}

std::string ConfigFileParser::removeCommentsWhiteLines(const std::string &fileName){
	std::ifstream		input(fileName.c_str());
	std::ostringstream	output;
	std::string			line;
	std::string			content;
	size_t				pos;

	while (std::getline(input, line)){ // Remove whitespace and tabs at the beginning and end of the line
		size_t start = line.find_first_not_of(" \t");
		size_t end = line.find_last_not_of(" \t");

		if (start != std::string::npos && end != std::string::npos)
			line = line.substr(start, end - start + 1);
		else
			line.clear(); // The line only has spaces and tabs, it becomes an empty line

		output << line << std::endl;
	}
	content = output.str();

	// We delete comments
        pos = 0;
        while ((pos = content.find("#", pos)) != std::string::npos)
			content.erase(pos, content.find("\n", pos + 1) - pos);

	// We eliminate empty lines
	pos = 0;
	while ((pos = content.find("\n\n", pos)) != std::string::npos)
		content.erase(pos, 1);

    	input.close();
	return content;
}

void ConfigFileParser::splitServers(){
	size_t start = this->_fileContent.find("server");;
	size_t end = 1;	
	while (start != end && start != this->_fileContent.length()){
		if (this->_fileContent.compare(start, 6, "server") != 0)
			throw ParseException("File is invalid");
		start += 6;
		while (this->_fileContent[start] && isspace(this->_fileContent[start]))
			start++;
		if (this->_fileContent[start] != '{')
			throw ParseException("File is invalid");

		size_t j = 1;
		for (size_t i = start + 1; this->_fileContent[i]; i++){
			if (this->_fileContent[i] == '{')
				j++;
			if (this->_fileContent[i] == '}'){
				j--;
				if (!j){
					end = i + 1;
					break;
				}
			}
		}
		if (j != 0)
        		throw ParseException("No valid server blocks found in the file");
		this->_serverConfig.push_back(this->_fileContent.substr(start, end - start + 1));
		this->_numServ++;
		start = end + 1;	
	}
}

const std::vector<std::string> & ConfigFileParser::getServerCfg(void) const{
	return(this->_serverConfig);
}

std::ostream & operator<<(std::ostream & o, std::vector<std::string> const & rhs){
	for(std::vector<std::string>::const_iterator it = rhs.begin();
	it != rhs.end(); ++it)
		std::cout << (*it) << std::endl;
	return (o);
}

void ConfigFileParser::eachServerCfg(){

	std::vector<std::string>::iterator start;
	std::vector<std::string>::iterator end;
	int index = 0;
	
	end = this->_serverConfig.end();

	for(start = this->_serverConfig.begin(); start != end; start++){
			std::istringstream split(*start);
			std::vector<std::string> tokens;
			for (std::string each; std::getline(split, each, '\n'); tokens.push_back(each));
			this->_eachServer[index] = tokens;
			index++;
	}
}
