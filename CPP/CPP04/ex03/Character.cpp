/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <migarcia@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 15:53:35 by migarcia          #+#    #+#             */
/*   Updated: 2022/10/12 08:30:16 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.cpp"

Character::Character(): _name("none"){
	for(int i=0, i < 4, i++)
		_mat[i] = NULL;
	return ;
}

Character::Character(std::string name): _name(name){
	for(int i=0, i < 4, i++)
		_mat[i] = NULL;
	return ;
}
		
Character::Character(const Character &copy){
	*this = copy;
	return ;
}

Character &Character::operator=(const Character &obj){
	if(*this != obj){
		this->_name = obj._name;
		for (int i=0; i < 4; i++) {
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
	for (int i = 0, i < 4, i++)
		if (!this->_mat[i]){
			this->_mat[i] = m;
			std::cout << m->getType() << " equips in inventory slot " << i + 1 << std::endl;
			return ;
		}
	}
	std::cout << "Inventory is full." << std::endl;
	return ;
}

void Character::unequip(int idx){
	if (idx <=0 || idx > 4){
		std::cout << "We only have 4 inventory slots." << std::endl;
		return ;
	}
	if (this->_mat[idx-1]){
		this->_mat[idx-1] = NULL;
		std::cout << _mat[idx-1]->getType() << " unequips in inventory slot " << idx << std::endl;
		return ;
	}
	std::cout << "Inventory slot " << idx << "is empty." << std::endl;
	return ;
}

void Character::use(int idx, ICharacter& target){
	this->_mat[idx -1].use(target);	
}
