/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <migarcia@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 14:18:53 by migarcia          #+#    #+#             */
/*   Updated: 2022/09/21 14:05:37 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(){
	std::cout << "Default DiamondTrap constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name), _name(name){
	ClapTrap::_name = (name + "_clap_name");
	std::cout << "DiamondTrap name constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy){
	std::cout << "DiamondTrap copy constructor called" << std::endl,
	*this = copy; //llamamos al operador que hemos declarado.
	return ;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap destructor called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &obj)
{
	this->_name = obj._name;
	this->_hitpoints = obj._hitpoints;
	this->_energypoints = obj._energypoints;
	this->_attackdamage = obj._attackdamage;
	return (*this);
}

void DiamondTrap::attack(std::string const &target){
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI(){
	std::cout << "DiamondTrap " << this->_name << " has Claptrap name " << ClapTrap::_name << std::endl;
}
