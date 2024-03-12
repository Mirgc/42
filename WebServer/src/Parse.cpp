#include "Parse.hpp"

// Constructors
Parse::Parse(void){

}


Parse::Parse(Parse const & src){
	*this = src;
}

Parse::~Parse(void){

}

Parse& Parse::operator=(const Parse &rhs){
	this->_ServerName = rhs.getServerName();
	this->_ProcesingLocation = rhs.getProcesingLocation();
	this->_ParsedLocations = rhs.getParsedLocations();
	this->_ParsedCfgs = rhs.getParsedCfgs();
	this->_PortPool = rhs.getPortPool();
	this->_ServernamePool = rhs.getSevernamePool();
	return (*this);
}

// Getters
const std::string & Parse::getServerName(void) const{
	return(this->_ServerName);
}

const std::vector<std::string> & Parse::getProcesingLocation(void) const{
	return(this->_ProcesingLocation);
}

const std::vector<LocationConfig>  & Parse::getParsedLocations(void) const{
	return(this->_ParsedLocations);
}

const LocationConfig & Parse::getParsedLocationAt(const unsigned int pos) const{
	return(this->_ParsedLocations.at(pos));
}

const std::vector<ServerConfig> & Parse::getParsedCfgs(void) const{
	return(this->_ParsedCfgs);
}

const ServerConfig & Parse::getParsedCfgAt(const unsigned int pos) const{
	return(this->_ParsedCfgs.at(pos));
}

const std::vector<unsigned int> & Parse::getPortPool(void) const{
	return(this->_PortPool);
}

const std::vector<std::string> & Parse::getSevernamePool(void) const{
	return(this->_ServernamePool);
}

// Setters
void Parse::setServerName(std::string const &ServerName){
 	this->_ServerName = ServerName;
}

void Parse::setProcesingLocations(std::vector<std::string> const &_ProcesingLocation){
 	this->_ProcesingLocation = _ProcesingLocation;
}

void Parse::setParsedLocations(std::vector<LocationConfig> const &ParsedLocations){
 	this->_ParsedLocations = ParsedLocations;
}

void Parse::addProcesingLocations(std::string const &ProcesingLocation){
 	this->_ProcesingLocation.push_back(ProcesingLocation);
}

void Parse::addParsedLocations(LocationConfig const &ParsedLocation){
 	this->_ParsedLocations.push_back(ParsedLocation);
}

void Parse::addPortToPool(unsigned int const &NewPort){
 	this->_PortPool.push_back(NewPort);
}

void Parse::addServerNameToPool(std::string const &NewServerName){
 	this->_ServernamePool.push_back(NewServerName);
}

void Parse::setServerCfg(std::vector<std::string> const & serverCfg){
 	this->_serverConfig = serverCfg;	
}

// Class Methods
// Get all locations form ConfigFileParser class _serverConfig to process it
void Parse::getNextServer(void){
	std::map<int, std::vector<std::string> >::iterator init;
	std::map<int, std::vector<std::string> >::iterator final;
	std::vector<std::string>::iterator start;
	std::vector<std::string>::iterator end;
	std::vector<std::string>::iterator it;
	std::vector<std::string>::iterator itend;
	int scope = 0;
	
	final = this->_eachServer.end();

	for(init =	this->_eachServer.begin(); init != final; init++){
		// Init a cleared ServerConfig instance from each server config scope
		this->_ProcesingLocation.clear();
		ServerConfig srvCfg = ServerConfig();
		
		end = (*init).second.end();
		for(start = (*init).second.begin(); start != end; start++){
			// Listened Ports
			if((*start).find("listen") != std::string::npos){
				srvCfg.setListenedPorts(this->splitPorts(StringTools::trim((*start).substr((*start).find("listen")+6, std::string::npos))));
			}
			
			// ServerConfig Host IP
			if((*start).find("host") != std::string::npos and (*start).find("server_name") == std::string::npos){
				std::string tmp;
				tmp = StringTools::trim((*start).substr((*start).find("host")+4, std::string::npos));
				if (tmp.compare("localhost") == 0)
					srvCfg.setHost(this->strToIp("127.0.0.1"));
				else{
					srvCfg.setHost(this->strToIp(tmp));
				}
			}

			// ServerName Parse to identify instance and possible ServerName exceptions
			if((*start).find("server_name") != std::string::npos){
				const std::string WHITESPACE = " \n\r\t\f\v";
				this->_ServerName = StringTools::trim((*start).substr((*start).find("server_name")+11, std::string::npos));
				if (this->_ServerName.empty() or this->_ServerName.find_first_of(WHITESPACE) != std::string::npos or this->isStrInVector(this->_ServerName, this->getSevernamePool()))
						throw ParseException("Invalid Server Name");
				srvCfg.setServerName(this->_ServerName);
				this->addServerNameToPool(this->_ServerName);
			}

			// ErrorPage Parse and some exceptions
			if((*start).find("error_page") != std::string::npos){
				std::string tmp;
				std::string keyStr;
				std::string value;
				const std::string WHITESPACE = " \n\r\t\f\v";
				tmp = StringTools::trim((*start).substr((*start).find("error_page")+10, std::string::npos));
				keyStr = tmp.substr(StringTools::trim(tmp).find_first_not_of(WHITESPACE), StringTools::trim(tmp).find_first_of(WHITESPACE));
				value = StringTools::trim(tmp.substr(StringTools::trim(tmp).find_last_of(WHITESPACE), StringTools::trim(tmp).find_last_not_of(WHITESPACE)));
				if (!isDigitStr(keyStr) or !isValidPath(value))
					throw ParseException("Invalid error page path");
				srvCfg.setErrorPageMap(atoi(keyStr.c_str()), value);
			}

			// ClientMaxBodySize Parse and possible exceptions SET MAX????? WHICH MAX????
			if((*start).find("client_max_body_size") != std::string::npos){
				srvCfg.setClientMaxBodySize(atoi(StringTools::trim((*start).substr((*start).find("client_max_body_size")+20, std::string::npos)).c_str())*1024);
				if (srvCfg.getClientMaxBodySize() > INT_MAX)
						throw ParseException("Invalid client_max_body_size value");
			}

			// docroot Parse and possible exceptions SET MAX?????
			if((*start).find("docroot") != std::string::npos){
				std::string tmp;
				tmp = StringTools::trim((*start).substr((*start).find("docroot")+7, std::string::npos));
				if (tmp.empty())
					throw ParseException("Invalid docroot path");
				srvCfg.setDocRoot(tmp);
			}

			// index Parse and possible exceptions SET MAX?????
			if((*start).find("index") != std::string::npos){
				std::string tmp;
				std::string root;
				tmp = StringTools::trim((*start).substr((*start).find("index")+5, std::string::npos));
				root = srvCfg.getDocRoot();
				if(isValidPath(srvCfg.getDocRoot()+"index.html") or isValidPath(srvCfg.getDocRoot()+tmp)){
					if (tmp.empty())
						srvCfg.setIndex("index.html");
					else{
						srvCfg.setIndex(tmp);
					}
				}
			}

			// Extract location scopes from ConfigFileParser class to processing vector
			if((*start).find("location") != std::string::npos){
				// Location and scopes basic verification
				if((*start).find("{") != std::string::npos){
					scope++;
				}
				itend = std::find(start, end, "}");
				if (start != itend){
					while(start != itend){
						this->_ProcesingLocation.push_back(*start);
						start++;
					}
					// Check if docroot and index do not exist in the location and add the global ones 
					// and if they do not exist, the default ones are kept.
					if(!this->isPartialStrInVector("docroot ", this->_ProcesingLocation))
						this->_ProcesingLocation.push_back("docroot " + srvCfg.getDocRoot());
					if(!this->isPartialStrInVector("index ", this->_ProcesingLocation))
						this->_ProcesingLocation.push_back("index " + srvCfg.getIndex());
					if(!this->isPartialStrInVector("upload_enable ", this->_ProcesingLocation))
						this->_ProcesingLocation.push_back("upload_enable " + srvCfg.getUploadEnableStrValue());
					if(!this->isPartialStrInVector("autoindex ", this->_ProcesingLocation))
						this->_ProcesingLocation.push_back("autoindex " + srvCfg.getAutoIndexStrValue());
					this->_ProcesingLocation.push_back("}");
					scope--;
				}
			}
		}

		// Check if mandatory listen exists at cfg
		if (srvCfg.getListenPorts().empty())
				throw ParseException("No listened ports at config file");
		// And if location exists and well "scoped" 
		else if (this->_ProcesingLocation.empty() or scope != 0)
				throw ParseException("No locations at file or bad scopes");
		else{
			this->ParseLocations(srvCfg);
		}
	}
}

// Process RAW data vector and return a new vector of pointers to LocationConfig instances
void Parse::ParseLocations(ServerConfig srvCfg){
	std::vector<std::string>::iterator start;
	std::vector<std::string>::iterator end;
	std::vector<std::string>::iterator it;
	std::vector<std::string>::iterator itend;

	std::string key;
	std::string value;
	std::string tmp;

	start =	this->_ProcesingLocation.begin();
	end = this->_ProcesingLocation.end();

	// make pair key/value and insert in a location config instance
	const std::string WHITESPACE = " }\n\r\t\f\v{";
	while (start != end)
	{
		// This list of valid CFG keys may increase as needed and we should discuss a possible value list.
		// restarted for each location
		std::string  Keys[] = { "proxy_pass", "method", "upload_enable", "upload_path",
								"redirection", "docroot", "autoindex", "index" };
		std::vector<std::string>  filledKeys(Keys, Keys + sizeof(Keys)/sizeof(Keys[0]));

		// Only one of each method is accepted per location
		std::string  Methods[] = { "GET", "POST", "DELETE"};
		std::vector<std::string>  filledMethods(Methods, Methods + sizeof(Methods)/sizeof(Methods[0]));

		LocationConfig loc = LocationConfig();
		loc.setLocationName(StringTools::trim((*start).substr((*start).find("location")+8, std::string::npos)));
		if(loc.getLocationName().at(0) != '/' and !this->isPyCgi(loc.getLocationName()))
			throw ParseException("Invalid location format => " + (loc.getLocationName()));
		start++;
		itend = std::find(start, end, "}");
		while (start != itend){
			key = (*start).substr(StringTools::trim(*start).find_first_not_of(WHITESPACE), StringTools::trim(*start).find_first_of(WHITESPACE));
			value = StringTools::trim((*start).substr(StringTools::trim(*start).find_last_of(WHITESPACE), StringTools::trim(*start).find_last_not_of(WHITESPACE)));
			if(isStrInVector(key, filledKeys)){
				valueValidation(key, value);
				// if the location has a default doocroot path and the upload path is not a cgi path, 
				// docroot will be set to the location's upload path name
					if(key == "docroot" and value == "/" and !this->isPyCgi(loc.getLocationName()))
						// When global docroot does not exist, the Upload Paths are changed as relative paths before configuring it as docroot 
						// and it is checked if it is a valid path
						this->isValidPath(value = this->relativizePath(loc.getLocationName()));
				loc.setUploadCfg(std::make_pair(key, value));
				// when a key, except methods, is once in a location, it cannot appear more times in the same location
				// if is method only one per value is allowed
				if(key != "method")
					filledKeys.erase(std::find(filledKeys.begin(), filledKeys.end(), key));
				else if(isStrInVector(value, filledMethods))
					filledMethods.erase(std::find(filledMethods.begin(), filledMethods.end(), value));
				else
					throw ParseException("Syntax error near " + key + " duplicated " + value);
			}
			else
				throw ParseException("Syntax error near " + key);
			start++;
		}
		// insert each well parsed LocationConfig instance in a vector of instances
		this->addParsedLocations(loc);
		start++;
	}
	// include locations in ServerConfig instance and clear from next server
	if(!this->_ParsedLocations.empty()){ 
		srvCfg.setLocation(this->_ParsedLocations);
		this->_ParsedLocations.clear();
	}
	// Add ServerConfig instance to ServerConfig vector
	this->_ParsedCfgs.push_back(srvCfg);
}

// All cfg inizialitation secuence
void Parse::setFullCfg(std::string const & configFile){
	this->checkFile(configFile);
	this->getNextServer();
	this->getParsedLocations();
}

// Is str in vector??
bool Parse::isStrInVector(const std::string &s, std::vector<std::string> const & v){
	
	if(std::find(v.begin(), v.end(), s) != v.end())
		return (true);
	return false;
}

// Is int in vector??
bool Parse::isIntInVector(const int &s, std::vector<unsigned int> const & v){
	
	if(std::find(v.begin(), v.end(), s) != v.end())
		return (true);
	return false;
}

// looks for a partial match in a string within a vector
bool Parse::isPartialStrInVector(const std::string &s, std::vector<std::string> &v){
	
	std::vector<std::string>::iterator start;
	std::vector<std::string>::iterator begin;
	std::vector<std::string>::reverse_iterator iter;
	
	begin = v.begin();
	// only from the end of the previous location onwards
	if((iter = std::find(v.rbegin(), v.rend(), "}")) != v.rend())
		begin = iter.base();

	for(start = begin; start != v.end(); start++)
		if((*start).find(s) != std::string::npos)
			return (true);
	return false;
}

bool Parse::isPyCgi(std::string path){

	if(path.compare(".py") == 0)
		return true;
	return false;
}

std::string Parse::relativizePath(std::string path){

	if(path.at(0) == '.')
		path.erase(0,1);
	if(path.at(0) != '/')
		path.insert(0, "/");
	if(path.at(0) != '.')
		path.insert(0, ".");
	
	return path;
}

// is a valid url format?? STILL UNUSED!!!
bool Parse::isUrlFormat(const std::string str){
	if (!str.empty()){
		std::string http = "http://";
		std::string https = "https://";
		size_t pos;
		
		pos = 0;
		if((pos = str.find_first_not_of(http)) == 7 or
		   (pos = str.find_first_not_of(https)) == 8){
			for(size_t it=0; it<pos; it++)
				if((pos == 7 and str[it] != http[it]) or
				   (pos == 8 and str[it] != https[it]))
					return false;
			for(size_t it=pos; isprint(str[it]) and !isspace(str[it]); it++)
				if (it == (str.length()-1))
					return true;
		}
	}
	return false;
}

//test path
bool Parse::isValidPath(const std::string str){
  std::ifstream ifs(str.c_str());

  if (ifs.is_open()){
	ifs.close();
	return true;
  }

	throw ParseException("Invalid path " + str);
	return false;
}

// BAD METHOD !!!!!!!!?????? STILL UNUSED!!!
std::vector<std::string> splitWords(const std::string &s){
    std::stringstream ss(s);
    std::vector<std::string> phrase;
    std::string word;

    while (ss >> word)
        phrase.push_back(word);

    return phrase;
}

// String ports to int vector ports
std::vector<unsigned int> Parse::splitPorts(const std::string &s){
    std::stringstream ss(s);
    std::vector<unsigned int> listenedPorts;
    unsigned int port;

    while (ss >> port)
		// Should we exclude "non-bindable" reserved ports??? DISCUSSS!!!!
		// Reserved ports are only bindable with super user privileges
		// Option: Accept all ports and let the binding fail and throw an exception,
		// having to know and justify the reason for the failure.
		// Or maybe print that phrase here instead of throwing an exception 
		// to complete the explanation by breaking the bind?
		if(port > 1023 and port < 65535 and !isIntInVector(port, listenedPorts) and !isIntInVector(port, this->getPortPool()) and port != 1025){
			this->addPortToPool(port);
			listenedPorts.push_back(port);
		}
		else if ((port > 0 and port < 1024) or port == 1025){
            std::ostringstream oss;
            oss << port;
            std::string sport = oss.str();
			throw ParseException("Reserved Port => " + sport);
		}
		else{
			throw ParseException("Invalid port number");
		}
    return listenedPorts;
}

unsigned int Parse::toValidPort(const std::string &s){
	if(!this->isDigitStr(s))
		throw ParseException("Redirection Port is Not a valid Port => " + s);

    std::stringstream ss(s);
    unsigned int port;

    while (ss >> port)
		if(!isIntInVector(port, this->getPortPool())){
            std::ostringstream oss;
            oss << port;
            std::string sport = oss.str();
			throw ParseException("Redirection Port is Not a listened Port => " + sport);
		}
    return port;
}

// NOT AUTHORIZED FUNCTION !!!!!!!! STILL UNUSED!!!
// in_addr_t Parse::strToIp(const std::string ipString){ 
//     in_addr_t ipAddress = inet_addr(ipString.c_str());

//     if (ipAddress == INADDR_NONE)
// 		throw ParseException("Error: La dirección IP no es válida.");
// 	return ipAddress;
// }

// String to ip (in_addr_t) only Big-Endian 
in_addr_t Parse::strToIp(const std::string ipString){
    in_addr_t ipAddr = 0;
    int shift = 24;

    std::istringstream iss(ipString);
    std::string token;

    int validTokens = 0;

    while (std::getline(iss, token, '.')){
        // strTok to intTok
        int intTok;
        std::istringstream(token) >> intTok;

        // Valid token??
        if (intTok < 0 || intTok > 255)
			throw ParseException("Error: Not valid IP address.");

        // Add token to address
        ipAddr |= (static_cast<in_addr_t>(intTok) << shift);
		// same as:
		// ipAddr = (ipAddr << shift) | static_cast<in_addr_t>(intTok);

        // Move to next byte
        shift -= 8;
        validTokens++;
    }

    // Check valid tokens
    if (validTokens != 4)
		throw ParseException("Error: Not valid IP address.");

    return ipAddr;
}

// String to ip (in_addr_t) only Litte-Endian - STILL UNUSED!!! 
// in_addr_t Parse::strToIp(const std::string ipString){
//     in_addr_t ipAddr = 0;

//     std::istringstream iss(ipString);
//     std::string token;

//     int validTokens = 0;

//     while (std::getline(iss, token, '.')){
//         // strTok to intTok
//         int intTok;
//         std::istringstream(token) >> intTok;

//         // Valid token??
//         if (intTok < 0 || intTok > 255)
// 			throw ParseException("Error: Not valid IP address.");

//         // Add token to address
//         ipAddr = (ipAddr >> 8) | (static_cast<in_addr_t>(intTok) << 24);

//         // Move to next byte
//         validTokens++;
//     }

//     // Check valid tokens
//     if (validTokens != 4)
// 		throw ParseException("Error: Not valid IP address.");


//     return ipAddr;
// }

// check if a string has only digits
bool Parse::isDigitStr(std::string str){

	std::string::const_iterator it;
	for(it = str.begin(); it!= str.end() && std::isdigit(*it); ++it);
	if(it != str.end())
		return false;
	return true;
}

// Locations values validation
// If the path or file does not exist, we throw an error or create it - DISCUSSSS!!!!!
void Parse::valueValidation(std::string key, std::string value){
	struct stat sb;

	if (key == "proxy_pass" or key == "redirection")
		if(!this->isUrlFormat(value))
			throw ParseException("Error: Not Valid Location URL format => " + value);
	if (key == "method")
		if (value != "GET" and value != "POST" and value!="DELETE")
			throw ParseException("Error: Not Valid Location Method => " + value);
	if (key == "upload_enable" or key == "autoindex")
		if (value != "on" and value != "off")
			throw ParseException("Error: Not Valid "+ key +" => " + value);
	if (key == "upload_path" or key == "docroot")
		if (stat(value.c_str(), &sb) != 0)
			throw ParseException("Error: Not Valid "+ key +" => " + value);
}
