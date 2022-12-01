/* ************************************************************************** */
/*                                                                            */
/*                                                        :::.     ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <migarcia@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 18:08:37 by migarcia          #+#    #+#             */
/*   Updated: 2022/12/01 15:01:32 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main( void ) {
	// INT
	std::cout << "## INT ##" << std::endl;
	int size = 10;
	int a[size];

	for (int i = 0; i < size; i++)
		a[i] = i + 1;
	
	::iter(a, size, Print);
	std::cout << std::endl;

	//CHAR
	std::cout << "## CHAR ##" << std::endl;
	char c[10];

	for (int i = 0; i < size; i++)
		c[i] = static_cast<char>(97 + i);
	
	::iter(c, size, Print);
	std::cout << std::endl;

	//STRING
	std::cout << "## STRING ##" << std::endl;
	std::string str[10] = {"ka", "ke", "ki", "ko", "ku"};
	::iter(str, 5, Print);
	return 0;
}
