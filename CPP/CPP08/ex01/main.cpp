/* ************************************************************************** */
/*                                                                            */
/*                                                        :::.     ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <migarcia@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 18:08:37 by migarcia          #+#    #+#             */
/*   Updated: 2022/12/02 19:46:27 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

int main()
{
	{
		std::cout << "## SUBJECT ##" << std::endl;
		Span sp = Span(5);
		sp.addNumber(5);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		sp.Print();
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	}

	{
		std::cout << "## MORE THAN 10000 ##" << std::endl;
		try{
			Span sp = Span(10050);
			sp.addNumber(90);
			sp.addNumber(10);
			sp.addNumber(15);
			sp.addNumber(50);
			sp.addNumber(51);
			for (int i = 5; i < 10050; i++){
				sp.addNumber(10);
			}
			sp.Print();
			std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
			std::cout << "Longest span: " << sp.longestSpan() << std::endl;
		}
		catch (const std::exception &e){
			std::cerr << e.what() << std::endl;
		}
	}

	{
		std::cout << "## EXCEPTIONS ##" << std::endl;
		Span sp = Span(2);
		sp.addNumber(90);
		sp.Print();
		try{
			std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		}
		catch (const std::exception &e){
			std::cerr << e.what() << std::endl;
		}
		try{
			std::cout << "Longest span: " << sp.longestSpan() << std::endl;
		}
		catch (const std::exception &e){
			std::cerr << e.what() << std::endl;
		}
		try{
			sp.addNumber(80);
			sp.Print();
			sp.addNumber(70);
		}
		catch (const std::exception &e){
			std::cerr << e.what() << std::endl;
		}
	}

	return 0;
}
