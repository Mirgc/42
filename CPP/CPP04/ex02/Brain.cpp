/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <migarcia@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:44:40 by migarcia          #+#    #+#             */
/*   Updated: 2022/10/07 08:44:19 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void){
}

Brain::Brain(const Brain &copy){
	*this = copy;
	return ;
}

Brain::~Brain(void){
}

Brain &Brain::operator=(const Brain &obj){
	if (this != &obj)
		*this = obj;
	return *this;
}
