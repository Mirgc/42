/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <migarcia@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:44:40 by migarcia          #+#    #+#             */
/*   Updated: 2022/05/11 18:31:11 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie( std::string name ):_name(name){
	return ;
}

Zombie::~Zombie(void){
	std::cout << Zombie::_name << " DiiiiiiieeeddD..." << std::endl;
	return ;
}

void Zombie::announce(void){
	std::cout << Zombie::_name << " BraiiiiiiinnnzzzZ..." << std::endl;
}
