/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <migarcia@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 18:08:37 by migarcia          #+#    #+#             */
/*   Updated: 2022/09/12 10:58:44 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;

	std::cout << "Cat say: ";
	i->makeSound(); //will output the cat sound!
	std::cout << "Dog say: ";
	j->makeSound();
	std::cout << "Animal say: ";
	meta->makeSound();

	const WrongAnimal* x = new WrongAnimal();
        const WrongAnimal* y = new WrongCat();

	std::cout << "Wrong animal say: ";
        x->makeSound();
	std::cout << "Wrong cat say: ";
        y->makeSound();

	delete meta;
	delete j;
	delete i;
	delete x;
	delete y;
	return 0;
}
