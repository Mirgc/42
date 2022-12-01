/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <migarcia@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 18:08:37 by migarcia          #+#    #+#             */
/*   Updated: 2022/12/01 10:13:51 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void){
	int random;

	random = rand() % 3 + 1;
	if (random == 1)
		return (new A());
	if (random == 2)
		return (new B());
	return (new C());
}

void identify(Base *p){
	if (dynamic_cast<A *>(p) != 0){
		std::cout << "Type A" << std::endl;
		return ;
	}
	if (dynamic_cast<B *>(p) != 0){
		std::cout << "Type B" << std::endl;
		return ;
	}
	if (dynamic_cast<C *>(p) != 0){
		std::cout << "Type C" << std::endl;
		return ;
	}
}

void check(Base &p){
	try{
		(void)dynamic_cast<A &>(p);
		std::cout << "Base is Type A" << std::endl;
	}
	catch(const std::exception& e) {
		std::cout << "Base is not type A." << std::endl;
	}
	try{
		(void)dynamic_cast<B &>(p);
		std::cout << "Base is Type B" << std::endl;
	}
	catch(const std::exception& e) {
		std::cout << "Base is not type B." << std::endl;
	}
	try{
		(void)dynamic_cast<C &>(p);
		std::cout << "Base is Type C" << std::endl;
	}
	catch(const std::exception& e) {
		std::cout << "Base is not type C." << std::endl;
	}
}

int main()
{
	srand(time(NULL));
	Base *base;
	
	std::cout << "Generating new Base..." << std::endl;
	base = generate();
	std::cout << "Identify type via pointer:" << std::endl;
	identify(base);
	std::cout << "Identify type via reference:" << std::endl;
	check(*base);
	delete base;

	return 0;
}
