/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <migarcia@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 18:08:37 by migarcia          #+#    #+#             */
/*   Updated: 2022/07/08 08:57:21 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	ScavTrap a("Mir");
	ClapTrap b("Pao");

	a.setAttackDamage(5);
	b.setAttackDamage(6);

	a.attack("pao");
	b.takeDamage(a.getAttackDamage());
	b.beRepaired(2);
	b.attack("mir");
	a.takeDamage(b.getAttackDamage());
	a.guardGate();

	std::cout << "Mir has " << a.getEnergyPoints() << " energy points and " << a.getHitPoints() << " hit points." << std::endl; 
	std::cout << "Pao has " << b.getEnergyPoints() << " energy points and " << b.getHitPoints() << " hit points." << std::endl; 
	return 0;
}
