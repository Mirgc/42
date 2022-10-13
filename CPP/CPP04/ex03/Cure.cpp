/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <migarcia@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 13:16:26 by migarcia          #+#    #+#             */
/*   Updated: 2022/10/12 16:56:32 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(): AMateria("cure"){
}

Cure::Cure(const Cure &copy){
	*this = copy;
	return ;
}

Cure::~Cure(){
}

Cure &Cure::operator=(const Cure &obj){
	if(this != &obj)
		this->_type = obj._type;
	return *this;
}

std::string const &Cure::getType() const{ 
	return this->_type;
}

AMateria *Cure::clone() const{
	return (new Cure(*this));
}

void Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
