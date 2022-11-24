/* ************************************************************************** */
/*                                                                            */
/*                                                        :::.     ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <migarcia@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 18:08:37 by migarcia          #+#    #+#             */
/*   Updated: 2022/11/20 12:32:14 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	try {
		std::cout << "## PEPE ##" << std::endl;
		Bureaucrat pepe = Bureaucrat("Pepe", 1);
	
		std::cout << pepe << std::endl;
		pepe.decrementGrade();
		std::cout << pepe << std::endl;
		pepe.incrementGrade();
		std::cout << pepe << std::endl;
		pepe.incrementGrade(); // This print exception
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	
	try {
		std::cout << "## PAQUI ##" << std::endl;
		Bureaucrat paqui = Bureaucrat("Paqui", 151); //This print exception
	
		std::cout << paqui << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	try {
		std::cout << "## MANOLI ##" << std::endl;
		Bureaucrat manoli = Bureaucrat("Manoli", 150);
	
		std::cout << manoli << std::endl;
		manoli.incrementGrade();
		std::cout << manoli << std::endl;
		manoli.decrementGrade();
		std::cout << manoli << std::endl;
		manoli.decrementGrade(); //This print exception
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	try {
		std::cout << "## PACO ##" << std::endl;
		Bureaucrat paco = Bureaucrat("Paco", 44);
	
		std::cout << paco << std::endl;
		paco.incrementGrade();
		std::cout << paco << std::endl;
		paco.decrementGrade();
		std::cout << paco << std::endl;
		paco.decrementGrade(); 
		std::cout << paco << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	return 0;
}
