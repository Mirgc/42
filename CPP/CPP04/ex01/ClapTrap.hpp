/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <migarcia@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:40:16 by migarcia          #+#    #+#             */
/*   Updated: 2022/08/01 15:26:21 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_H
# define CLAPTRAP_H
# include <string>
# include <iostream>

/* https://es.wikibooks.org/wiki/Programaci%C3%B3n_en_C%2B%2B/Herencia */

class ClapTrap{
	protected:
		std::string _name;
		unsigned int _hitpoints;
		unsigned int _energypoints;
		unsigned int _attackdamage;
	
	public:
		ClapTrap();
		ClapTrap(std::string name);
		~ClapTrap();
		void		attack(std::string const &target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);
		unsigned int	getHitPoints(void);
		void    	setHitPoints(int hp);
		unsigned int	getEnergyPoints(void);
		void		setEnergyPoints(int ep);
		unsigned int	getAttackDamage(void);
		void		setAttackDamage(int ad);
};

#endif
