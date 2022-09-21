/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <migarcia@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 07:21:42 by migarcia          #+#    #+#             */
/*   Updated: 2022/09/21 14:05:47 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap(){
	std::cout << "Default FragTrap constructor called" << std::endl;
	_hitpoints = 100;
	_energypoints = 100;
	_attackdamage = 30;
}

FragTrap::FragTrap(std::string name): ClapTrap(name){
	std::cout << "FragTrap name constructor called" << std::endl;
	_hitpoints = 100;
	_energypoints = 100;
	_attackdamage = 30;
}

FragTrap::FragTrap(const FragTrap &copy){
	std::cout << "FragTrap copy constructor called" << std::endl,
	*this = copy; //llamamos al operador que hemos declarado.
	return ;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap destructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &obj)
{
	this->_name = obj._name;
	this->_hitpoints = obj._hitpoints;
	this->_energypoints = obj._energypoints;
	this->_attackdamage = obj._attackdamage;
	return (*this);
}

void FragTrap::highFivesGuys() {
	std::cout << this->_name << ": Nice Job! That’s Awesome!" << std::endl;
}
