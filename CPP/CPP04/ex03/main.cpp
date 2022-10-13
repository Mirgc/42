/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <migarcia@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 18:08:37 by migarcia          #+#    #+#             */
/*   Updated: 2022/10/12 18:37:18 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"

void subject()
{
	std::cout << "##### SUBJECT #####" << std::endl;
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;
}

void mine()
{
	std::cout << "##### MINE #####" << std::endl;
	ICharacter	*mir = new Character("Mir");
        AMateria	*ice = new Ice();

        mir->equip(new Ice());
        mir->equip(ice);
        mir->equip(new Cure());
        mir->equip(new Cure);
        mir->equip(new Ice());
        mir->unequip(1);
        mir->equip(new Cure());

        delete mir;
        delete ice;
}

int main()
{
	subject();
	mine();
	return  0;
}
