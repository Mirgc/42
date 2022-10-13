/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <migarcia@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 13:16:26 by migarcia          #+#    #+#             */
/*   Updated: 2022/10/12 13:15:52 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(){
}

AMateria::AMateria(const std::string &type){
	this->_type = type;
}

AMateria::AMateria(const AMateria &copy){
	*this = copy;
	return ;
}

AMateria::~AMateria(){
}

AMateria &AMateria::operator=(const AMateria &obj){
	if (this != &obj)
		this->_type = obj._type;
	return *this;
}

std::string const &AMateria::getType() const{ 
	return this->_type;
}
