#ifndef CONTACT_H
# define CONTACT_H
#include <iostream>
#include <string>

using namespace std;

class Contact{
	private://Atributos privados
		string first;
		string last;
		string nickname;
		string phone;
		string secret;

	public://Metodos publicos
		Contact(void); //Constructor
		~Contact(); //Destructor
		void set_first(string str);	
		void set_last(string str);	
		void set_nickname(string str);	
		void set_phone(string str);	
		void set_secret(string str);	
		string get_first();	
		string get_last();	
		string get_nickname();	
		string get_phone();	
		string get_secret();	
};
#endif
