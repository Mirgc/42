#include "phonebook.hpp"
#include <cstdio>

Phonebook::Phonebook(void):pos(0), contacts(0){
	return ;
}

Phonebook::~Phonebook(){
	cout << "### See you soon! ###" << endl;
}

void Phonebook::get_action(string &str){
	getline(cin, str);
	if (cin.bad())
	{
		cin.clear();
		cout << "Invalid input! Closing App..." << endl;
		exit(1);
	}
}

void Phonebook::add(){
	string str;

	if (this->pos == 8)
		this->pos = 0;
	cout << "Insert first name: ";
	getline(cin, str);
	list[pos].set_first(str);
	cout << "Insert last name: ";
	getline(cin, str);
	list[pos].set_last(str);
	cout << "Insert nickname: ";
	getline(cin, str);
	list[pos].set_nickname(str);
	cout << "Insert phone: ";
	getline(cin, str);
	list[pos].set_phone(str);
	cout << "Insert darkest secret: ";
	getline(cin, str);
	list[pos].set_secret(str);
	cout << endl;
	if (contacts < 8)
		contacts++;
	this->pos++;
}

void Phonebook::print_in_col(string str){
	string tmp;

	cout << setw(10);
	if (str.length() <= 10)
		cout << str;
	else{
		tmp = str.substr(0, 9);
		tmp += ".";
		cout << tmp;
	}		
}

void Phonebook::print_table(){
	int i = 0;
	
	while (i < contacts){
		cout << "|";
		cout << setw(10);
		cout << setiosflags(ios::right);
		cout << i + 1;
		cout << "|";
		Phonebook::print_in_col(list[i].get_first());
		cout << "|";
		Phonebook::print_in_col(list[i].get_last());
		cout << "|";
		Phonebook::print_in_col(list[i].get_nickname());
		cout << "|" << endl;
		i++;
	}
}

void Phonebook::print_contact(int num){
	string	str;
	
	if (num < 1 || num > contacts)
		cout << "Invalid Index!!" << endl;
	else{
		cout << endl;
		cout << "First name	: "; cout << list[num - 1].get_first() << endl;
		cout << "Last name	: "; cout << list[num - 1].get_last() << endl;
		cout << "Nickname	: "; cout << list[num - 1].get_nickname() << endl;
		cout << "Phone number	: "; cout << list[num - 1].get_phone() << endl;
		cout << "Darkest secret	: "; cout << list[num - 1].get_secret() << endl;
		cout << "Press a key to main menu.....";
		getline(cin, str);
	}
}

void Phonebook::search(){
	string	str;
	int	num;

	if (contacts == 0)
		cout << "No contacts to search!!" << endl;
	else{
		cout << endl;
		cout << setiosflags(ios::right); 
		cout << "|";
		Phonebook::print_in_col("index");
		cout << "|";
		Phonebook::print_in_col("first name");
		cout << "|";
		Phonebook::print_in_col("last name");
		cout << "|";
		Phonebook::print_in_col("nickname");
		cout << "|" << endl;
		Phonebook::print_table();
		cout << "Select index: ";
		getline(cin, str);
            	if (str.length() == 1)
            	{
                	num = str[0] - '0';
			Phonebook::print_contact(num);
		}
		else
                	cout <<"Invalid Index!!" << endl;
		//else {
	        //	cout << "Invalid Index!!";
		//}
	}
}
