#ifndef BITCOINEXCHANGE_H
# define BITCOINEXCHANGE_H
# include <iostream>
# include <map>
# include <fstream>

class BitcoinExchange{
	private:
        std::map<std::string, float> _data;
	
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &copy);
		~BitcoinExchange();

		BitcoinExchange		&operator=(const BitcoinExchange &obj);

};

#endif