#include "LocationConfig.hpp"

// Constructors
LocationConfig::LocationConfig(void){

}


LocationConfig::LocationConfig(LocationConfig const & src){
	*this = src;
}

LocationConfig::~LocationConfig(void){

}

LocationConfig& LocationConfig::operator=(const LocationConfig &rhs){
	this->_LocationName = rhs.getLocationName();
	this->_UploadCfg = rhs.getUploadCfg();
	return (*this);
}

// get location Upload Path
const std::string & LocationConfig::getLocationName(void) const{
	return(this->_LocationName);
}

bool LocationConfig::isPyCgi() const {
	if(this->getLocationName().compare(".py") == 0)
		return true;
	return false;
}

// get all cfg vector<pair> key.first value.second
const std::vector<std::pair<std::string, std::string> > & LocationConfig::getUploadCfg(void) const{
	return(this->_UploadCfg);
}

// get specific cfg value by name 
const std::string & LocationConfig::getCfgValueFrom(std::string const & Key) const{
	for(std::vector<std::pair<std::string, std::string> >::const_iterator it = this->getUploadCfg().begin();
		it != this->getUploadCfg().end(); ++it){
		if ((*it).first == Key)
			return ((*it).second);
	}
	return (Key);
}

// specific string getters
const std::string LocationConfig::getUploadPath() const{
	if(this->isKeyInLocation("upload_path")){
		return(this->getCfgValueFrom("upload_path"));
	}
	return("");
}

const std::string LocationConfig::getProxyPass() const{
	if(this->isKeyInLocation("proxy_pass")){
		return(this->getCfgValueFrom("proxy_pass"));
	}
	return("");
}

const std::string LocationConfig::getRedirection() const{
	if(this->isKeyInLocation("redirection")){
		return(this->getCfgValueFrom("redirection"));
	}
	return("");
}

const std::string LocationConfig::getDocroot() const{
	if(this->isKeyInLocation("docroot")){
		return(this->getCfgValueFrom("docroot"));
	}
	return("");
}

const std::string LocationConfig::getIndex() const{
	if(this->isKeyInLocation("index")){
		return(this->getCfgValueFrom("index"));
	}
	return("");
}

// bool getters
bool LocationConfig::getMethodGetBool() const{
	return(this->isMethodInLocation("GET"));
}

bool LocationConfig::getMethodPostBool() const{
	return(this->isMethodInLocation("POST"));
}

bool LocationConfig::getMethodDeleteBool() const{
	return(this->isMethodInLocation("DELETE"));
}

bool LocationConfig::getUploadEnableBool() const{
        if(this->getCfgValueFrom("upload_enable").compare("on") == 0)
                return(true);
        return(false);
}

bool LocationConfig::getAutoIndexBool() const{
        if(this->getCfgValueFrom("autoindex").compare("on") == 0)
                return(true);
        return(false);
}

// check if specific key is in location
bool LocationConfig::isKeyInLocation(std::string const & Key) const{
	for(std::vector<std::pair<std::string, std::string> >::const_iterator it = this->getUploadCfg().begin();
		it != this->getUploadCfg().end(); ++it){
			if ((*it).first == Key)
				return true;
		}
	return false;
}

// setters
void LocationConfig::setLocationName(std::string const &LocationName){
	this->_LocationName = LocationName;
}

void LocationConfig::setUploadCfg(std::pair<std::string, std::string> const &pair){
	this->_UploadCfg.push_back(pair);
}

// print all cfg vector<pair> key.first value.second if needed to debug
std::ostream & operator<<(std::ostream & o, LocationConfig const & rhs){
	std::cout << "Location" << " : " << rhs.getLocationName() << std::endl;
	std::cout << "KEY" << " : " << "VALUE" << std::endl;
	for(std::vector<std::pair<std::string, std::string> >::const_iterator it = rhs.getUploadCfg().begin();
	it != rhs.getUploadCfg().end(); ++it)
		std::cout << (*it).first << " : " << (*it).second << std::endl;
	return (o);
}

// specific method validation
bool LocationConfig::isMethodInLocation(std::string verb) const{
	for(std::vector<std::pair<std::string, std::string> >::const_iterator it = this->getUploadCfg().begin();
		it != this->getUploadCfg().end(); ++it){
			if ((*it).first == "method" and (*it).second == verb)
				return true;
		}
	return false;
}
