/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <migarcia@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:44:40 by migarcia          #+#    #+#             */
/*   Updated: 2022/09/12 15:16:52 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Brain.hpp"

Dog::Dog(void):Animal("Dog") {
	this->_brain = new Brain();
//	std::cout << "Default dog constructor called" << std::endl;
}

Dog::Dog(std::string type):Animal(type) {
//	std::cout << "Dog constructor called" << std::endl;
}

Dog::~Dog(void){
	delete this->_brain;
//	std::cout << "Dog destructor called" << std::endl;
}

void	Dog::makeSound(void) const{
	std::cout << "Guau" << std::endl;
}
