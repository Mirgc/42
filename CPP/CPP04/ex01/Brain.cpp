/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <migarcia@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:44:40 by migarcia          #+#    #+#             */
/*   Updated: 2022/09/21 20:00:06 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void){
}

Brain::Brain(std::string brain[100]):_brain(brain){
}

Brain::~Brain(void){
}

Brain &Brain::operator=(const Brain &obj){
	if (this != &obj)
		this->_brain = obj._brain;
	return *this;
}
