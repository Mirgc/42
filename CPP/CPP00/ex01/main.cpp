#include <string.h>
#include "contact.hpp"

void get_action(string &action){
	cout << "añadido" << endl;
}

int main(){

	Contact people[7];
	string action;
	
	cout << "### PHONEBOOK ###" << endl;
	while(1){
		cout << "Choose an action:" << endl;
		cout << "[ADD/SEARCH/EXIT]" << endl;
		get_action(action);
	
		if (action.compare("ADD") == 0){
				Phonebook.add();
		}
		else{
			cout << "Choose an action:" << endl;
			cout << "ADD / SEARCH / EXIT" << endl;
		}
	}

	return 0;
}
