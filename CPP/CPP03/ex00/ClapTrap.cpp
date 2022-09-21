/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <migarcia@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:44:40 by migarcia          #+#    #+#             */
/*   Updated: 2022/09/19 13:56:02 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name):_name(name),_hitpoints(10), _energypoints(10), _attackdamage(0) {
	std::cout << "Default constructor called" << std::endl;
	return ;
}

ClapTrap::ClapTrap(const ClapTrap &copy){
	std::cout << "Copy constructor called" << std::endl,
	*this = copy; //llamamos al operador que hemos declarado.
	return ;
}

ClapTrap::~ClapTrap(void){
	std::cout << "Destructor called" << std::endl;
	return ;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &obj){
	std::cout << "Assignation operator called" << std::endl;
	if (this != &obj){ //Comprueba que no se esté intentando igualar un objeto a sí mismo
		this->_hitpoints = obj.getHitPoints();
		this->_energypoints = obj.getEnergyPoints();
		this->_attackdamage = obj.getAttackDamage();
	}
	return *this;
}


void ClapTrap::attack(std::string const &target){
	if (this->_energypoints != 0 && this->_hitpoints != 0) {
		std::cout << "ClapTrap " << this->_name << " attack " << target << ", causing " << _attackdamage << " points of damage!" << std::endl;
		this->_energypoints -= 1;
	} else {
		std::cout << "ClapTrap " << this->_name << " haven't got energy." << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount){
	std::cout << "ClapTrap " << this->_name << " takes " << amount << " points of damage!" << std::endl;
	this->_hitpoints -= amount;
}

void ClapTrap::beRepaired(unsigned int amount){
	if (this->_energypoints != 0) {
		std::cout << "ClapTrap " << this->_name << " recharge " << amount << " points of hitpoint." << std::endl;
		this->_energypoints -= 1;
		this->_hitpoints += amount;
	} else {
		std::cout << "ClapTrap " << this->_name << " haven't got energy." << std::endl;
	}	
}

unsigned int	ClapTrap::getHitPoints(void) const{
	return this->_hitpoints;
}

void    ClapTrap::setHitPoints(int hp){
	this->_hitpoints = hp;
}

unsigned int	ClapTrap::getEnergyPoints(void) const{
	return this->_energypoints;
}

void	ClapTrap::setEnergyPoints(int ep){
	this->_energypoints = ep;
}

unsigned int	ClapTrap::getAttackDamage(void) const{
	return this->_attackdamage;
}

void	ClapTrap::setAttackDamage(int ad){
	this->_attackdamage = ad;
}
