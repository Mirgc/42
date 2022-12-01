/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <migarcia@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:44:40 by migarcia          #+#    #+#             */
/*   Updated: 2022/12/01 08:49:25 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data(void){
}

Data::Data(std::string name):_name(name){
}

Data::Data(const Data &copy):_name(copy._name){
}

Data::~Data(void){
}

Data &Data::operator=(const Data &obj){
	if (this != &obj)
		this->_name = obj._name;
	return *this;
}

const std::string	Data::getName(void){
	return this->_name;
}

void				Data::setName(std::string name){
	this->_name = name;
	return ;
}
