#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){
    std::ifstream file("data.csv");
    std::string line;
    if (!file) { 
        std::cout << "Error, could not open file." << std::endl; 
    }
    else {
        std::string date;
        float value = 0;
        while(!file.eof()){
            std::getline(file, line);
            std::stringstream stream;
            stream << line;
            std::getline(stream, date, ',');
            stream >> value;
            //_data[date] = value;
            _data.insert(std::make_pair(date, value));
        }
        file.close();
        /*for(std::map<std::string, float>::const_iterator it = _data.begin(); it != _data.end(); it++)
        {
            std::cout << it->first << " " << it->second << "\n";
        }*/
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

std::string   BitcoinExchange::check_date(std::string date){
        int day, month, year;
        std::stringstream stream;
        stream << date;
        std::string str;
        int i = 0;
        while(std::getline(stream, str, '-')){
            if (i == 0){
                std::istringstream(str) >> year;
                if (year < 2009 || year > 2022)
                    return("ERROR: Wrong year in date.");
            }
            if (i == 1){
                std::istringstream(str) >> month;
                if (month < 01 || month > 12)
                    return("ERROR: Wrong month in date.");
            }
            if (i == 2){
                std::istringstream(str) >> day;
                if (day < 01 || day > 31)
                    return("ERROR: Wrong day in date.");
                if (day > 28 && month == 2)
                    return("ERROR: Wrong day in date.");
                if (day > 31 && (month == 4 || month == 6 || month == 9 || month == 11))
                    return("ERROR: Wrong day in date.");
            }
            i++;
        }
        if (i != 3)
            return("ERROR: Wrong date.");
        return (date);
}

float    BitcoinExchange::check_value(std::string value){
    const char* str = value.c_str();
    bool digit = true;
    for (int i = 0; i < (int)std::strlen(str); i++) {
        if(!isdigit(str[i]) && str[i] != (46))
            digit = false;
    }
    if (!digit)
        return (-1);
    float x = std::atof(str);
    if (x < 0 || x > 1000)
        return (-1);
    return (x);
}

void    BitcoinExchange::print_info(std::string date, float value){
    float bit;
    std::map<std::string, float>::const_iterator it;

    it = _data.find(date);
    if (it != _data.end())
        bit = it->second;
    else {
        it = _data.lower_bound(date);
        bit = it->second;
    }
    std::cout << std::setprecision(3) << date << " => " << value << " = " << bit * value << std::endl;
}

void    BitcoinExchange::run(char *input){
    std::ifstream file(input);
    std::string line;

    if (!file)  
        std::cout << "ERROR: could not open file " << input << "." << std::endl; 
    else {
        std::string date;
        float value;

        std::getline(file, line);
        if(line.compare("date | value"))
            std::cerr << "ERROR: Format is not 'date | value'." << std::endl;
        else{
            while(std::getline(file, line)){
                std::istringstream stream(line); //https://barcelonageeks.com/procesando-strings-usando-std-istringstream/
                std::string str, date, err;
                int i = 0;
                while(std::getline(stream, str, ' ')){
                    if (i == 0)
                        date =  check_date(str);
                    if (i == 1){
                        if (str.compare("|"))
                            i = 4;
                    }
                    if (i == 2)
                        value = check_value(str);
                    i++;
                }
                err = date.substr(0,5);
                if (!err.compare("ERROR"))
                    std::cout << date << std::endl;
                else{
                    if (i != 3)
                        std::cout << "ERROR: Wrong format." << std::endl;
                    else if (value == -1)
                        std::cout << "ERROR: Wrong value." << std::endl;
                    else
                        print_info(date, value);
                }
            }
        }
        file.close();
    }
}