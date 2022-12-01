/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <migarcia@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 18:08:37 by migarcia          #+#    #+#             */
/*   Updated: 2022/12/01 09:28:39 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include <iostream>

uintptr_t serialize(Data *ptr){
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data *deserialize(uintptr_t raw){
	return (reinterpret_cast<Data *>(raw));
}

int main()
{
	try {
		Data dat("abc");
		Data *seri_dat;
		uintptr_t intdat;

		std::cout << "Data name: " << dat.getName() << ", in address: " << &dat << "." << std::endl;
		intdat = serialize(&dat);
		std::cout << "Casted " << dat.getName() << " to uintptr_t: " << std::hex << intdat << std::endl;
		seri_dat = deserialize(intdat);
		std::cout << "Casting " << intdat<< " to Data:" << std::endl;
		std::cout << "Data name: " << seri_dat->getName() << ", in address: " << &seri_dat << "." << std::endl;

	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
		std::cout << "ERROR: Can't convert because of the reason above." << std::endl;
	}
	std::cout << std::endl;
	
	return 0;
}
