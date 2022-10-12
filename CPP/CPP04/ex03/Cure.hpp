/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <migarcia@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 13:06:23 by migarcia          #+#    #+#             */
/*   Updated: 2022/10/12 08:30:08 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_H
#define CURE_H
# include <iostream>
# include "AMateria.hpp"

class Cure: public AMateria
{
	public:
		Cure();
		Cure(const Cure &copy);
		virtual ~Cure();
		Cure &operator=(const Cure &obj);

		std::string const & getType() const; //Returns the materia type
		virtual AMateria* clone() const;
		virtual void use(ICharacter& target);
};

#endif
