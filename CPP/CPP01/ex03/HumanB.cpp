/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <migarcia@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:44:40 by migarcia          #+#    #+#             */
/*   Updated: 2022/05/18 11:46:14 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB( std::string name ):_name(name){
	this->_weapon = NULL;
	return ;
}

HumanB::~HumanB(void){
	return ;
}

void HumanB::attack( void ){
	std::cout << _name << " attacks with " << _weapon->getType() << std::endl;
}

void HumanB::setWeapon( Weapon &weapon ){
	this->_weapon = &weapon;
}
