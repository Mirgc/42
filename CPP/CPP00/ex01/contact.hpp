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
		void set_first();	
		void set_last();	
		void set_nickname();	
		void set_phone();	
		void set_secret();	
		void get_first();	
		void get_last();	
		void get_nickname();	
		void get_phone();	
		void get_secret();	
};
#endif
