#include "contact.hpp"

//Constructor, nos sirve para inicializar los atributos
Contact::Contact(void)
{
	return ;
}

//Destructor
Contact::~Contact()
{
	return ;
}

string Contact::get_first(){
	return(this->first); 
}

string Contact::get_last(){
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

void Contact::set_first(string str){
	this->first = str; 
}

void Contact::set_last(string str){
	this->last = str;
}

void Contact::set_nickname(string str){
	this->nickname = str;
}

void Contact::set_phone(string str){
	this->phone = str; 
}

void Contact::set_secret(string str){
	this->secret = str; 
}
