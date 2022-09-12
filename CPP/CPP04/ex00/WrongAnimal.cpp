/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <migarcia@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:44:40 by migarcia          #+#    #+#             */
/*   Updated: 2022/09/12 10:53:39 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void){
//	std::cout << "Default wrong animal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type):_type(type) {
//	std::cout << "Type wrong animal constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal(void){
//	std::cout << "Wrong animal destructor called" << std::endl;
}

std::string	WrongAnimal::getType(void) const{
	return this->_type;
}

void	WrongAnimal::makeSound(void) const{
	std::cout << "Wrong animaaaal...." << std::endl;
}
