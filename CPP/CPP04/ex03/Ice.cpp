/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <migarcia@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 13:16:26 by migarcia          #+#    #+#             */
/*   Updated: 2022/10/12 13:53:21 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(): AMateria("ice"){
}

Ice::Ice(const Ice &copy){
	*this = copy;
	return ;
}

Ice::~Ice(){
}

Ice &Ice::operator=(const Ice &obj){
	if(this != &obj)
		this->_type = obj._type;
	return *this;
}

std::string const &Ice::getType() const{ 
	return this->_type;
}

AMateria *Ice::clone() const{
	AMateria *Clone;
	Clone = new Ice();
	return Clone;
}

void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;

}
