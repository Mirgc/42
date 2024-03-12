#ifndef LOCATION_PARSE_HPP
# define LOCATION_PARSE_HPP

#include <algorithm>
#include <iostream>
#include <limits.h>
#include <vector>
#include <map>
#include "ConfigFileParser.hpp"
#include "LocationConfig.hpp"
#include "ServerConfig.hpp"
#include "StringTools.hpp"

class Parse: public ConfigFileParser{

	protected:
		std::string   		     		_ServerName;
		std::vector<std::string>    	_ProcesingLocation;
		std::vector<LocationConfig>  	_ParsedLocations;
		std::vector<ServerConfig>  		_ParsedCfgs;
		std::vector<unsigned int>		 _PortPool;
		std::vector<std::string>    	_ServernamePool;

	public:
		Parse(void);
		Parse(Parse const & src);
		~Parse(void);

		Parse & operator=(Parse const & rhs);

		std::string const & getServerName(void) const;
		std::vector<std::string>  const & getProcesingLocation(void) const;

		// get full vector
		std::vector<LocationConfig>  const & getParsedLocations(void) const;
		const LocationConfig & getParsedLocationAt(const unsigned int pos) const;
		const std::vector<ServerConfig> & getParsedCfgs(void) const;
		const ServerConfig & getParsedCfgAt(const unsigned int pos) const;
		const std::vector<unsigned int> & getPortPool(void) const;
		const std::vector<std::string> & getSevernamePool(void) const;

		void setServerName(std::string const &ServerName);
		void setProcesingLocations(std::vector<std::string> const & ProcesingLocation);
		void setParsedLocations(std::vector<LocationConfig>  const & ParsedLocation);
		void setServerCfg(std::vector<std::string> const & serverCfg);

		// All cfg inizialitation secuence
		void setFullCfg(std::string const & configFile);
		
		// add one to vector
		void addProcesingLocations(std::string const & ProcesingLocation);
		void addParsedLocations(LocationConfig const & ParsedLocation);
		void addPortToPool(unsigned int const &NewPort);
		void addServerNameToPool(std::string const &NewServerName);

		// Get all server config to process it
		void getNextServer(void);
		// Process RAW data vector and add a copy from LocationConfig filled instance 
		void ParseLocations(ServerConfig srvCfg);
		

		// check if specific string is in vector
		bool isStrInVector(const std::string &s, std::vector<std::string> const & vector);
		bool isPartialStrInVector(const std::string &s, std::vector<std::string> &vector);

		// check if specific string is in vector
		bool isIntInVector(const int &s, std::vector<unsigned int> const & v);

		// is a valid url format?
		bool isUrlFormat(const std::string str);

		// is a valid path?
		bool isValidPath(const std::string str);
		bool isPyCgi(std::string path);
		std::string relativizePath(std::string path);

		// String ports to int vector ports
		std::vector<unsigned int> splitPorts(const std::string &s);
		unsigned int toValidPort(const std::string &s);

		// transform ip string into in_addr_t
		in_addr_t strToIp(const std::string ipString);

		// check if a string has only digits
		bool isDigitStr(std::string str);

		// Locations values validation
		void valueValidation(std::string key, std::string value);

};

#endif
