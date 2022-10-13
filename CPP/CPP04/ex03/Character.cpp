/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <migarcia@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 15:53:35 by migarcia          #+#    #+#             */
/*   Updated: 2022/10/12 17:49:07 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(): _name("none"){
	for (int i = 0; i < 4; i++)
		this->_mat[i] = NULL;
	return ;
}

Character::Character(std::string name): _name(name){
	std::cout << "Character " << this->_name << " created." << std::endl;
	for (int i = 0; i < 4; i++)
		this->_mat[i] = NULL;
	return ;
}
		
Character::Character(const Character &copy){
	*this = copy;
	return ;
}

Character::~Character(){
	for (int i = 0; i < 4; i++){
		if (this->_mat[i])
			delete this->_mat[i];
	
	}
	return ;
}

Character &Character::operator=(const Character &obj){
	if (this != &obj){
		this->_name = obj._name;
		for (int i = 0; i < 4; i++) {
		        if(this->_mat[i])
		            delete this->_mat[i];
		        this->_mat[i] = obj._mat[i];
    		}
	}
	return *this;	
}

std::string const &Character::getName() const{
	return this->_name;
}
		
void Character::equip(AMateria* m){
	for (int i = 0; i < 4; i++){
		if (!this->_mat[i]){
			this->_mat[i] = m;
			std::cout << m->getType() << " equips in inventory slot " << i << std::endl;
			return ;
		}
	}
	std::cout << "Inventory is full." << std::endl;
	delete m;
	return ;
}

void Character::unequip(int idx){
	if (idx < 0 || idx >= 4){
		std::cout << "We only have 4 inventory slots." << std::endl;
		return ;
	}
	if (this->_mat[idx]){
		std::cout << this->_mat[idx]->getType() << " unequips in inventory slot " << idx << std::endl;
		this->_mat[idx] = NULL;
		return ;
	}
	std::cout << "Inventory slot " << idx << "is empty." << std::endl;
	return ;
}

void Character::use(int idx, ICharacter& target){
	if (idx >= 0 && idx < 4){
		if (this->_mat[idx]){
			this->_mat[idx]->use(target);	
		}
	}
}	
