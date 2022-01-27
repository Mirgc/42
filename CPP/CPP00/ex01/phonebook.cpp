/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <migarcia@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 18:50:55 by migarcia          #+#    #+#             */
/*   Updated: 2022/01/27 13:13:53 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"
#include <cstdio>

Phonebook::Phonebook(void):pos(0), contacts(0){
	return ;
}

Phonebook::~Phonebook(){
	std::cout << "### See you soon! ###" << std::endl;
}

void Phonebook::get_action(std::string &str){
	getline(std::cin, str);
	if (std::cin.bad())
	{
		std::cin.clear();
		std::cout << "Invalid input! Closing App..." << std::endl;
		exit(1);
	}
}

void Phonebook::add(){
	std::string str;

	if (this->pos == 8)
		this->pos = 0;
	std::cout << "Insert first name: ";
	getline(std::cin, str);
	list[pos].set_first(str);
	std::cout << "Insert last name: ";
	getline(std::cin, str);
	list[pos].set_last(str);
	std::cout << "Insert nickname: ";
	getline(std::cin, str);
	list[pos].set_nickname(str);
	std::cout << "Insert phone: ";
	getline(std::cin, str);
	list[pos].set_phone(str);
	std::cout << "Insert darkest secret: ";
	getline(std::cin, str);
	list[pos].set_secret(str);
	std::cout << std::endl;
	if (contacts < 8)
		contacts++;
	this->pos++;
}

void Phonebook::print_in_col(std::string str){
	std::string tmp;

	std::cout << std::setw(10);
	if (str.length() <= 10)
		std::cout << str;
	else{
		tmp = str.substr(0, 9);
		tmp += ".";
		std::cout << tmp;
	}		
}

void Phonebook::print_table(){
	int i = 0;
	
	while (i < contacts){
		std::cout << "|";
		std::cout << std::setw(10);
		std::cout << std::setiosflags(std::ios::right);
		std::cout << i + 1;
		std::cout << "|";
		Phonebook::print_in_col(list[i].get_first());
		std::cout << "|";
		Phonebook::print_in_col(list[i].get_last());
		std::cout << "|";
		Phonebook::print_in_col(list[i].get_nickname());
		std::cout << "|" << std::endl;
		i++;
	}
}

void Phonebook::print_contact(int num){
	std::string	str;
	
	if (num < 1 || num > contacts)
		std::cout << "Invalid Index!!" << std::endl;
	else{
		std::cout << std::endl;
		std::cout << "First name	: "; std::cout << list[num - 1].get_first() << std::endl;
		std::cout << "Last name	: "; std::cout << list[num - 1].get_last() << std::endl;
		std::cout << "Nickname	: "; std::cout << list[num - 1].get_nickname() << std::endl;
		std::cout << "Phone number	: "; std::cout << list[num - 1].get_phone() << std::endl;
		std::cout << "Darkest secret	: "; std::cout << list[num - 1].get_secret() << std::endl;
		std::cout << "Press a key to main menu.....";
		getline(std::cin, str);
	}
}

void Phonebook::search(){
	std::string	str;
	int	num;

	if (contacts == 0)
		std::cout << "No contacts to search!!" << std::endl;
	else{
		std::cout << std::endl;
		std::cout << std::setiosflags(std::ios::right); 
		std::cout << "|";
		Phonebook::print_in_col("index");
		std::cout << "|";
		Phonebook::print_in_col("first name");
		std::cout << "|";
		Phonebook::print_in_col("last name");
		std::cout << "|";
		Phonebook::print_in_col("nickname");
		std::cout << "|" << std::endl;
		Phonebook::print_table();
		std::cout << "Select index: ";
		getline(std::cin, str);
            	if (str.length() == 1)
            	{
                	num = str[0] - '0';
			Phonebook::print_contact(num);
		}
		else
                	std::cout <<"Invalid Index!!" << std::endl;
	}
}
