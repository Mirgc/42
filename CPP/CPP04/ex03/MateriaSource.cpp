/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <migarcia@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 12:08:59 by migarcia          #+#    #+#             */
/*   Updated: 2022/10/12 17:48:54 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(){
	for (int i = 0; i < 4; i++)
		this->_mat[i] = NULL;
	return ;
}

MateriaSource::MateriaSource(const MateriaSource &obj){
	*this = obj;
	return ;
}

MateriaSource::~MateriaSource(){
	for (int i = 0; i < 4; i++){
		if (this->_mat[i])
			delete this->_mat[i];
	}
	return ;
}
		
MateriaSource &MateriaSource::operator=(const MateriaSource &obj){
	if (this != &obj){
		for (int i = 0; i < 4; i++){
			if (this->_mat[i])
				delete this->_mat[i];
			this->_mat[i] = obj._mat[i];
		}
	}
	return *this;
}
		
void	MateriaSource::learnMateria(AMateria *m){
	for (int i = 0; i < 4; i++){
		if (!this->_mat[i])
		{
			std::cout << "Learning materia " << m->getType() << std::endl;
			this->_mat[i] = m;
			return ;
		}
	}
	std::cout << "Inventory full, the materia is going to delete." << std::endl;
	delete m;
}

AMateria *MateriaSource::createMateria(const std::string &type){
	for (int i = 0; i < 4; i++){
		if (this->_mat[i] != NULL && this->_mat[i]->getType() == type)
			return (this->_mat[i]->clone());
	}
	std::cout << "ERROR creating... The materia " << type << " not learned." << std::endl;
	return (NULL);
}
