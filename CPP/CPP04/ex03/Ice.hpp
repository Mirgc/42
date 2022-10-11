/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <migarcia@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 13:06:23 by migarcia          #+#    #+#             */
/*   Updated: 2022/10/10 19:52:44 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_H
#define ICE_H
# include <iostream>
# include "AMateria.hpp"

class Ice: public AMateria
{
	public:
		Ice();
		Ice(const Ice &copy);
		virtual ~Ice();
		Ice &operator=(const Ice &obj);

		std::string const & getType() const; //Returns the materia type
		virtual AMateria* clone() const;
		//virtual void use(ICharacter& target);
};

#endif
