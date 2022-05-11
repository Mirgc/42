/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <migarcia@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 18:08:37 by migarcia          #+#    #+#             */
/*   Updated: 2022/05/11 18:20:24 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	//Se crea un zombie dinamico, por que lo declaramos dentro de la funcion newZombie, pero la llamada la hacemos aqui mismo
	Zombie *zom = newZombie("ZombieHeap");
	zom->announce();

	//Decladamos el zombie dentro de random, por lo que lo hacemos de manera estatica porque solo lo necesitamos en esa funcion, al terminar la funcion, destruye el zombie con el destructor.
	randomChump("ZombieStack");
	//Destruimos el zombie dinamico. Si no hacemos el delete no entra el destructor.
	delete zom;
	return (0);
}
