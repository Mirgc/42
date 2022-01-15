#include "phonebook.hpp"

Phonebook::Phonebook(void):pos(0){
	cout << "### PHONEBOOK ###" << endl;
}

Phonebook::~Phonebook():{
	cout << "### See you soon! ###" << endl;
}

void Phonebook::get_action(string &str){
	return(this->first); 
}

void Phonebook::add(){
	return(this->last); 
}

string Contact::get_nickname(){
	return(this->nickname); 
}

string Contact::get_phone(){
	return(this->phone); 
}

string Contact::get_secret(){
	return(this->secret); 
}

string Contact::set_first(string str){
	this->first = str; 
}

string Contact::set_last(string str){
	this->last = str;
}

string Contact::set_nickname(string str){
	this->nickname = str;
}

string Contact::set_phone(string str){
	this->phone = str; 
}

string Contact::set_secret(string str){
	this->secret = str; 
}
