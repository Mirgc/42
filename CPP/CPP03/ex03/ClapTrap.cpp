/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <migarcia@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:44:40 by migarcia          #+#    #+#             */
/*   Updated: 2022/07/08 08:55:08 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap():_hitpoints(10), _energypoints(10), _attackdamage(0) {
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name):_name(name),_hitpoints(10), _energypoints(10), _attackdamage(0) {
	std::cout << "ClapTrap name constructor called" << std::endl;
}

ClapTrap::~ClapTrap(void){
	std::cout << "Destructor called" << std::endl;
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

unsigned int	ClapTrap::getHitPoints(void){
	return this->_hitpoints;
}

void    ClapTrap::setHitPoints(int hp){
	this->_hitpoints = hp;
}

unsigned int	ClapTrap::getEnergyPoints(void){
	return this->_energypoints;
}

void	ClapTrap::setEnergyPoints(int ep){
	this->_energypoints = ep;
}

unsigned int	ClapTrap::getAttackDamage(void){
	return this->_attackdamage;
}

void	ClapTrap::setAttackDamage(int ad){
	this->_attackdamage = ad;
}
