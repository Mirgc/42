/* ************************************************************************** */
/*                                                                            */
/*                                                        :::.     ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <migarcia@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 18:08:37 by migarcia          #+#    #+#             */
/*   Updated: 2022/12/02 10:44:46 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "array.hpp"

int main( void ) {
	// STACK 1
	Array<int> stack(10);

	for (int i = 0; i < 10; i++)
        stack[i] = i;

	std::cout << "STACK1 Size: " << stack.size() << std::endl;
	try {
		std::cout << "Stack1[0]: " << stack[0] << std::endl;
	}
	catch (std::exception const & e) {
		std::cout << e.what() << std::endl;
	}


	// STACK 2
	Array<int> stack2(15);

	for (int i = 0; i < 15; i++)
        stack2[i] = i;

	std::cout << std::endl;
	std::cout << "STACK2 Size: " << stack2.size() << std::endl;
	try {
		std::cout << "Stack2[14]: " << stack2[14] << std::endl;
	}
	catch (std::exception const & e) {
		std::cout << e.what() << std::endl;
	}

	stack2 = stack;
	std::cout << "STACK2 = STACK1 " << stack2.size() << std::endl;
	try {
		std::cout << "Stack2[14]: " << stack2[14] << std::endl;
	}
	catch (std::exception const & e) {
		std::cout << e.what() << std::endl;
	}

	// STACK COPY
	Array<int> copy(stack);

	copy[0] = 1000;
	if (stack[0] == copy[0])
		std::cerr << "Copy array changed!." << std::endl;

	std::cout << std::endl;
	std::cout << "STACK Copy Size: " << copy.size() << std::endl;
	try{
		std::cout << "StackCopy[0]: " << copy[0] << std::endl;
	}
	catch (std::exception const & e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}
