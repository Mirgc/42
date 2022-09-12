/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <migarcia@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 14:18:53 by migarcia          #+#    #+#             */
/*   Updated: 2022/08/01 15:16:54 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(){
	std::cout << "Default DiamondTrap constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name), _name(name){
	ClapTrap::_name = (name + "_clap_name");
	std::cout << "DiamondTrap name constructor called" << std::endl;
//    	this->_hitpoints = FragTrap::_hitpoints;
//	this->_energypoints = ScavTrap::_energypoints;
//	this->_attackdamage = FragTrap::_attackdamage;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap destructor called" << std::endl;
}

void DiamondTrap::attack(std::string const &target){
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI(){
	std::cout << "DiamondTrap " << this->_name << " has Claptrap name " << ClapTrap::_name << std::endl;
}
