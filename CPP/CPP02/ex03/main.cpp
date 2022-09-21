/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <migarcia@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 18:08:37 by migarcia          #+#    #+#             */
/*   Updated: 2022/09/18 16:15:11 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

void	check_bsp(bool res)
{
	if (res)
		std::cout << "Success" << std::endl;
	else
		std::cout << "Failed" << std::endl;
	std::cout << std::endl;
}

int main(void)
{
	Point	a(4, 5);
	Point	b(6, 2);
	Point	c(-1.9, -2);

	std::cout << "Point a" << a << std::endl;
	std::cout << "Point b" << b << std::endl;
	std::cout << "Point c" << c << std::endl << std::endl; 
	std::cout << "Test 1:" << std::endl << "Point " << a << std::endl;
	check_bsp(bsp(a, b, c, a));
	std::cout << "Test 2:" << std::endl << "Point " << b << std::endl;
	check_bsp(bsp(a, b, c, b));
	std::cout << "Test 3:" << std::endl << "Point " << c << std::endl;
	check_bsp(bsp(a, b, c, c));
	std::cout << "Test 4:" << std::endl << "Point " << Point(4, 3) << std::endl;
	check_bsp(bsp(a, b, c, Point(4, 3)));
	std::cout << "Test 5:" << std::endl << "Point " << Point(5.9, 2.1) << std::endl;
	check_bsp(bsp(a, b, c, Point(5.9, 2.1)));
	std::cout << "Test 6:" << std::endl << "Point " << Point(1.9, 2.2) << std::endl;
	check_bsp(bsp(a, b, c, Point(1.9, 2.2)));
	std::cout << "Test 7:" << std::endl << "Point " << Point(-1.9, -2.2) << std::endl;
	check_bsp(bsp(a, b, c, Point(-1.9, -2.2)));
	return (0);
}
