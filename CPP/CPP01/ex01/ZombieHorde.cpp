/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <migarcia@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 17:24:52 by migarcia          #+#    #+#             */
/*   Updated: 2022/05/16 07:56:09 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name ){
	Zombie *zom = new Zombie[N];
	
	for (int i = 0; i < N; i++)
		zom[i].set_name(name + std::to_string(i + 1));
	return (zom);
}
