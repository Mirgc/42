/* ************************************************************************** */
/*                                                                            */
/*                                                        :::.     ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <migarcia@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 18:08:37 by migarcia          #+#    #+#             */
/*   Updated: 2022/12/02 14:24:47 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "easyfind.hpp"

int main( void ) {
	std::ostream_iterator<int> outStream(std::cout, " ");
	std::vector<int>	vec;
	int					num;
	
	for (int i = 0; i < 10; i++)
		vec.push_back(i);
	
	std::cout << "Vector = ";
	std::copy(vec.begin(), vec.end(), outStream);
	std::cout << std::endl;

	try {
		num = 8;
		easyfind(vec, num);
		std::cout << num << " found!" << std::endl;
		num = 20;
		easyfind(vec, num);
		std::cout << num << " found!" << std::endl;
	}
	catch (std::exception const &e){
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
