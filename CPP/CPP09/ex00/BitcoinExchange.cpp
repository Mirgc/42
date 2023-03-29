#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){
    std::ifstream file;
    file.open("data.csv");
    if (!file) { 
        std::cout << "Error, could not open file." << std::endl; 
    }
    else {
        std::string date;
        float value;
        while(file >> date >> value){
            _data[date] = value;
        }
        file.close();
        for(std::map<std::string, float>::const_iterator it = _data.begin(); it != _data.end(); it++)
        {
            std::cout << it->first << " " << it->second << "\n";
        }
    }
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy){
	*this = copy;
}

BitcoinExchange::~BitcoinExchange(void){
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &obj){
	if (this != &obj){
		this->_data = obj._data;
	}		
	return *this;
}