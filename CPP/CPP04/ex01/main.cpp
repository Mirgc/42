/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <migarcia@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 18:08:37 by migarcia          #+#    #+#             */
/*   Updated: 2022/09/12 15:36:27 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	int	i;
	int	j;

	std::cout << "Insert how many animals do yo want: ";
	std::cin >> i;
	if (i <= 0)
		std::cout << "ERROR. Try Again!" << std::endl;
	else {
		const Animal* meta[i];
		j = -1;
		while (i > ++j) {
			if (i % 2)
				meta[j] = new Dog();
			else
				meta[j] = new Cat();
		}
		j = -1;
		while (i > ++j) 
			std::cout << "Animal: " << meta[i]->getType() << std::endl;
		j = -1;
		while (i > ++j) 
			delete meta[i];
		
	}
	return 0;
}
