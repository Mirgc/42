#ifndef BITCOINEXCHANGE_H
# define BITCOINEXCHANGE_H
# include <iostream>
# include <map>
# include <fstream>
# include <sstream>
# include <cstring>
# include <cstdlib>
# include <iomanip>

class BitcoinExchange{
	private:
        std::map<std::string, float> _data;
	
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &copy);
		~BitcoinExchange();

		BitcoinExchange		&operator=(const BitcoinExchange &obj);
		std::string			check_date(std::string date);
		float    			check_value(std::string value);
		void    			print_info(std::string date, float value);
		void				run(char *input);

};

#endif