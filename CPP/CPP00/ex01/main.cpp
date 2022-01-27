/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <migarcia@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 18:51:12 by migarcia          #+#    #+#             */
/*   Updated: 2022/01/27 13:14:10 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "contact.hpp"
#include "phonebook.hpp"

int main(){

	Phonebook phonebook;
	std::string action;
	
	while(1){
		system("clear");
		action.clear();
		std::cout << "### PHONEBOOK ###" << std::endl;
		std::cout << std::endl;
		std::cout << "Choose an action:" << std::endl;
		std::cout << "[ADD/SEARCH/EXIT]" << std::endl;
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
			std::cout << "¡¡Invalid option!!" << std::endl;
			sleep(1);
		}
	}

	return 0;
}
