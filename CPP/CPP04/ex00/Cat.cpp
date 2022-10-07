/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <migarcia@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:44:40 by migarcia          #+#    #+#             */
/*   Updated: 2022/10/07 08:09:04 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void):Animal("Cat") {
//	std::cout << "Default cat constructor called" << std::endl;
}

Cat::Cat(std::string type):Animal(type) {
//	std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat &copy){
	*this= copy;
	return ;
}

Cat::~Cat(void){
//	std::cout << "Cat destructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &obj){
	if (this != &obj)
		this->_type = obj._type;
	return *this;
}

void	Cat::makeSound(void) const{
	std::cout << "Miau" << std::endl;
}
