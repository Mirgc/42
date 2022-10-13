/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <migarcia@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 14:37:26 by migarcia          #+#    #+#             */
/*   Updated: 2022/10/12 12:53:33 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_H
#define CHARACTER_H
#include "ICharacter.hpp"

class Character : public ICharacter
{
	protected:
		AMateria	*_mat[4];
		std::string	_name;
	public:
		Character();
		Character(std::string name);
		Character(const Character &copy);
		~Character();
		Character &operator=(const Character &obj);

		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};
#endif
