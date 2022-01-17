#include <unistd.h>
#include "contact.hpp"
#include "phonebook.hpp"

int main(){

	Phonebook phonebook;
	string action;
	
	while(1){
		system("clear");
		action.clear();
		cout << "### PHONEBOOK ###" << endl;
		cout << endl;
		cout << "Choose an action:" << endl;
		cout << "[ADD/SEARCH/EXIT]" << endl;
		phonebook.get_action(action);
		if (action.compare("ADD") == 0 || action.compare("add") == 0){
			phonebook.add();
			sleep(1);
		}
		else if (action.compare("SEARCH") == 0 || action.compare("search") == 0){
			phonebook.search();
			sleep(1);
		}
		else if (action.compare("EXIT") == 0 || action.compare("exit") == 0){
			break ;
		}
		else{
			cout << "¡¡Invalid option!!" << endl;
			sleep(1);
		}
	}

	return 0;
}
