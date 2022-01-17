#ifndef PHONEBOOK_H
# define PHONEBOOK_H
# include <iostream>
# include <iomanip>
# include <string>
# include "contact.hpp" 

using namespace std;

class Phonebook{
	private:
		int 	pos;
		int	contacts;
		Contact list[8];
	public:
		Phonebook(void);
		~Phonebook();
		void get_action(string &str);
		void add();
		void print_in_col(string str);
		void print_table();
		void search();
};
#endif
