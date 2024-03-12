#include "ServerConfig.hpp"

ServerConfig::ServerConfig()
{
        // Default values ​​will be overwritten with httpd.conf values ​​if they exist
        this->_host = 16777343;
        this->_serverName = "localhost";
        this->_docRoot = "/";
        this->_clientMaxBodySize = 1024;
        this->_index = "index.html";
        this->_upload_enable = "off";
        this->_autoindex = "off";
}

ServerConfig::~ServerConfig() {}

/* copy constructor */
ServerConfig::ServerConfig(const ServerConfig &copy)
{
	*this = copy;
}

ServerConfig &ServerConfig::operator=(const ServerConfig &obj)
{
        if (this != &obj)
        {
                this->_port = obj._port;
                this->_host = obj._host;
                this->_serverName = obj._serverName;
                this->_docRoot = obj._docRoot;
                this->_clientMaxBodySize = obj._clientMaxBodySize;
                this->_index = obj._index;
                this->_upload_enable = obj._upload_enable;
                this->_autoindex = obj._autoindex;
                this->_errorPageMap = obj._errorPageMap;
                this->_locations = obj._locations;
                this->_listendPorts = obj._listendPorts;
        }
        return (*this);
}

void ServerConfig::addListenedPorts(unsigned int port){
        this->_listendPorts.push_back(port);
}

void ServerConfig::setListenedPorts(std::vector<unsigned int> ports){
        this->_listendPorts = ports;
}

void ServerConfig::setPort(unsigned int const &port){
	this->_port = port;
}

void ServerConfig::setHost(in_addr_t const &host){
	this->_host = host;
}

void ServerConfig::setServerName(std::string const &serverName){
	this->_serverName= serverName;
}

void ServerConfig::setDocRoot(std::string const &docRoot){
	this->_docRoot = docRoot;
}

void ServerConfig::setClientMaxBodySize(unsigned int const &clientMaxBodySize){
	this->_clientMaxBodySize = clientMaxBodySize;
}

void ServerConfig::setIndex(std::string const &index){
	this->_index = index;
}

void ServerConfig::setErrorPageMap(int const &httpStatus, std::string const &path){
	this->_errorPageMap.insert(std::pair<int,std::string>(httpStatus,path));
}

void ServerConfig::addLocation(LocationConfig location){
	this->_locations.insert(_locations.end(), location);
}

void ServerConfig::setLocation(std::vector<LocationConfig> const &locations){
	this->_locations = locations;
}

const unsigned int &ServerConfig::getPortAt(unsigned int pos) const{
	return (this->_listendPorts.at(pos));
}

const unsigned int &ServerConfig::getPort() const{
	return (this->_port);
}

const std::vector<unsigned int> &ServerConfig::getListenPorts() const{
        return (this->_listendPorts);
}

int     ServerConfig::getListenPortsSize() const{
    std::vector<int>::size_type t;
    t = this->_listendPorts.size();
    int size = static_cast<int>(t);
    return size;
}
 
const in_addr_t	&ServerConfig::getHost() const{
	return (this->_host);
}

const std::string &ServerConfig::getServerName() const{
	return (this->_serverName);
}

const std::string &ServerConfig::getDocRoot() const{
	return (this->_docRoot);
}

unsigned int ServerConfig::getClientMaxBodySize() const{
	return (this->_clientMaxBodySize);
}
	
const std::string &ServerConfig::getIndex() const{
	return (this->_index);
}

const std::string &ServerConfig::getUploadEnableStrValue() const{
	return (this->_upload_enable);
}

bool ServerConfig::getUploadEnableBool() const{
        if(this->getUploadEnableStrValue().compare("on") == 0)
                return(true);
        return(false);
}

const std::string &ServerConfig::getAutoIndexStrValue() const{
	return (this->_autoindex);
}

bool ServerConfig::getAutoIndexBool() const{
        if(this->getAutoIndexStrValue().compare("on") == 0)
                return(true);
        return(false);
}

const std::map<int, std::string> &ServerConfig::getErrorPageMap() const{
	return (this->_errorPageMap);
}

const std::vector<LocationConfig> &ServerConfig::getLocations() const{
	return (this->_locations);
}

bool ServerConfig::isErrorMap() const{
        if(this->_errorPageMap.empty())
                return false;
        return true;
}

bool ServerConfig::isErrorInMap(int error) const{
        if(this->getErrorPageMap().find(error) != this->getErrorPageMap().end())
                return true;
	return false; 
}

bool ServerConfig::isValidPath(const std::string path) const{
        std::ifstream ifs(path.c_str());

        if (ifs.is_open()){
                ifs.close();
	return true;
        }
        return false;
}

const std::string ServerConfig::getPath(int error) const{
        if(this->isErrorMap() and this->isErrorInMap(error))
                return(this->getErrorPageMap().find(error)->second);
        return("");
}

const std::string ServerConfig::get400Content() const {
    return this->getContent(400);
}

const std::string ServerConfig::get404Content() const {
    return this->getContent(404);
}

const std::string ServerConfig::get405Content() const {
    return this->getContent(405);
}

const std::string ServerConfig::get413Content() const {
    return this->getContent(413);
}

const std::string ServerConfig::get500Content() const {
    return this->getContent(500);
}

const std::string ServerConfig::get504Content() const {
    return this->getContent(504);
}

const std::string ServerConfig::getContent(int error) const{
       if(this->isValidPath(this->getPath(error))){
        std::ifstream file(this->getPath(error).c_str());
        std::string content;
        std::string line;

        while (std::getline(file, line))
                content += line;
        file.close();

        return content; 
       }
       return ("");
}
