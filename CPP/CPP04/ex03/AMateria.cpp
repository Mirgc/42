/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <migarcia@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 13:16:26 by migarcia          #+#    #+#             */
/*   Updated: 2022/10/10 19:26:00 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(){
}

AMateria::AMateria(std::string const & type){
	this->_type = type;
}

AMateria::AMateria(const AMateria &copy){
	*this = copy;
	return ;
}

AMateria::~AMateria(){
}

std::string const &AMateria::getType() const{ 
	return this->_type;
}
