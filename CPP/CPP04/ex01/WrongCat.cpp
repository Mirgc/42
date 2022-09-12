/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <migarcia@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:44:40 by migarcia          #+#    #+#             */
/*   Updated: 2022/09/12 10:53:54 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void):WrongAnimal("WrongCat") {
//	std::cout << "Default wrong cat constructor called" << std::endl;
}

WrongCat::WrongCat(std::string type):WrongAnimal(type) {
//	std::cout << "Wrong cat constructor called" << std::endl;
}

WrongCat::~WrongCat(void){
//	std::cout << "Wrong cat destructor called" << std::endl;
}

void	WrongCat::makeSound(void) const{
	std::cout << "Muuuuuuu" << std::endl;
}
