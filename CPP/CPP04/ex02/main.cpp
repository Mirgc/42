/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <migarcia@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 18:08:37 by migarcia          #+#    #+#             */
/*   Updated: 2022/10/10 09:50:02 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	// NO SE PUEDE HACER meta[x] = new Animal() PORQUE UNA CLASE ABSTRACTA NO SE PUEDE INSTANCIAR
	int	i;
	int	j;

	std::cout << "Insert how many animals do yo want: ";
	std::cin >> i;
	if (i <= 0)
		std::cout << "ERROR. Try Again!" << std::endl;
	else {
		const Animal* meta[i];
		std::cout << i << std::endl;
		j = 0;
		while (j < i) {
			if (j % 2)
				meta[j++] = new Dog();
			else
				meta[j++] = new Cat();
		}
		j = -1;
		while (++j < i) 
			std::cout << "Animal: " << meta[j]->getType() << j << std::endl;
		j = -1;
		while (++j < i) 
			delete meta[j];
	} 
	return 0;
}
