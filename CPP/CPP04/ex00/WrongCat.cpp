/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <migarcia@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:44:40 by migarcia          #+#    #+#             */
/*   Updated: 2022/10/07 08:16:15 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void):WrongAnimal("WrongCat") {
//	std::cout << "Default wrong cat constructor called" << std::endl;
}

WrongCat::WrongCat(std::string type):WrongAnimal(type) {
//	std::cout << "Wrong cat constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &copy){
	*this= copy;
	return ;
}

WrongCat::~WrongCat(void){
//	std::cout << "Wrong cat destructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &obj){
	if (this != &obj)
		this->_type = obj._type;
	return *this;
}

void	WrongCat::makeSound(void) const{
	std::cout << "Muuuuuuu" << std::endl;
}
