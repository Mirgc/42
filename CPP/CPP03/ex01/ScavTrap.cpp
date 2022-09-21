/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <migarcia@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 07:21:42 by migarcia          #+#    #+#             */
/*   Updated: 2022/09/20 10:15:25 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap(){
	std::cout << "Default ScavTrap constructor called" << std::endl;
	_hitpoints = 100;
	_energypoints = 50;
	_attackdamage = 20;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name){
	std::cout << "ScavTrap name constructor called" << std::endl;
	_hitpoints = 100;
	_energypoints = 50;
	_attackdamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &copy){
	std::cout << "ScavTrap copy constructor called" << std::endl,
	*this = copy; //llamamos al operador que hemos declarado.
	return ;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap destructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &obj)
{
	this->_name = obj._name;
	this->_hitpoints = obj._hitpoints;
	this->_energypoints = obj._energypoints;
	this->_attackdamage = obj._attackdamage;
	return (*this);
}

void ScavTrap::guardGate() {
	std::cout << "ScavTrap " << this->_name << " has enterred in Gate Keeper mode." << std::endl;
}
