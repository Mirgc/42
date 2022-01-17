#include "phonebook.hpp"

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
	cout << "pos" << pos << endl;
	cout  << "Insert first name:" << endl;
	getline(cin, str);
	list[pos].set_first(str);
	cout  << "Insert last name:" << endl;
	getline(cin, str);
	list[pos].set_last(str);
	cout  << "Insert nickname:" << endl;
	getline(cin, str);
	list[pos].set_nickname(str);
	cout  << "Insert phone:" << endl;
	getline(cin, str);
	list[pos].set_phone(str);
	cout  << "Insert darkest secret:" << endl;
	getline(cin, str);
	list[pos].set_secret(str);
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
	
	while (i < pos){
		cout << setw(10);
		cout << setiosflags(ios::left);
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

void Phonebook::search(){
	string str;

	if (contacts == 0)
		cout << "No contacts to search!!" << endl;
	else{
		cout << setiosflags(ios::left);
		Phonebook::print_in_col("index");
		cout << "|";
		Phonebook::print_in_col("first name");
		cout << "|";
		Phonebook::print_in_col("last name");
		cout << "|";
		Phonebook::print_in_col("nickname");
		cout << "|" << endl;
		Phonebook::print_table();
		getline(cin, str);
	}
}
