/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <migarcia@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:44:40 by migarcia          #+#    #+#             */
/*   Updated: 2022/09/12 10:53:23 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void):Animal("Cat") {
//	std::cout << "Default cat constructor called" << std::endl;
}

Cat::Cat(std::string type):Animal(type) {
//	std::cout << "Cat constructor called" << std::endl;
}

Cat::~Cat(void){
//	std::cout << "Cat destructor called" << std::endl;
}

void	Cat::makeSound(void) const{
	std::cout << "Miau" << std::endl;
}
