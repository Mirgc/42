/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <migarcia@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:40:16 by migarcia          #+#    #+#             */
/*   Updated: 2022/09/19 13:55:40 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_H
# define CLAPTRAP_H
# include <string>
# include <iostream>

class ClapTrap{
	private:
		std::string _name;
		unsigned int _hitpoints;
		unsigned int _energypoints;
		unsigned int _attackdamage;
	
	public:
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &copy);
		~ClapTrap();
		ClapTrap &operator=(const ClapTrap &obj);
		void		attack(std::string const &target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);
		unsigned int	getHitPoints(void) const;
		void    	setHitPoints(int hp);
		unsigned int	getEnergyPoints(void) const;
		void		setEnergyPoints(int ep);
		unsigned int	getAttackDamage(void) const;
		void		setAttackDamage(int ad);
};

#endif
