/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <migarcia@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:40:16 by migarcia          #+#    #+#             */
/*   Updated: 2022/09/12 10:28:42 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_H
# define ANIMAL_H
# include <string>
# include <iostream>

class Animal{
	protected:
		std::string _type;
	
	public:
		Animal();
		Animal(std::string type);
		virtual ~Animal();
		std::string	getType(void) const;
		virtual void	makeSound(void) const;
};

#endif
