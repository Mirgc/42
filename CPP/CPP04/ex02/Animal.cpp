/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <migarcia@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:44:40 by migarcia          #+#    #+#             */
/*   Updated: 2022/09/22 11:49:25 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void){
//	std::cout << "Default animal constructor called" << std::endl;
}

Animal::Animal(std::string type):_type(type) {
//	std::cout << "Type animal constructor called" << std::endl;
}

Animal::Animal(const Animal &copy){
	*this= copy;
	return ;
}

Animal::~Animal(void){
//	std::cout << "Animal destructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &obj){
	if (this != &obj)
		this->_type = obj._type;
	return *this;
}

std::string	Animal::getType(void) const{
	return this->_type;
}

void	Animal::makeSound(void) const{
	std::cout << "Blaaaa blaaa blaa bla" << std::endl;
}
