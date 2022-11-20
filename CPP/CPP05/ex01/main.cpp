/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <migarcia@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 18:08:37 by migarcia          #+#    #+#             */
/*   Updated: 2022/11/20 13:42:49 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try {
		std::cout << "## PEPE - FORMULARIO 50 ##" << std::endl;
		Bureaucrat pepe = Bureaucrat("Pepe", 1);
		Form fo = Form("Formulario 50", 50, 30);
	
		std::cout << pepe << std::endl;
		std::cout << fo << std::endl;
		pepe.signForm(fo);
		std::cout << fo << std::endl;

	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	
	try {
		std::cout << "## PAQUI - FORMULARIO 149 ##" << std::endl;
		Bureaucrat paqui = Bureaucrat("Paqui", 150);
		Form fo = Form("Formulario 149", 149, 30);
	
		std::cout << paqui << std::endl;
		std::cout << fo << std::endl;
		paqui.signForm(fo);
		paqui.incrementGrade();
		std::cout << paqui << std::endl;
		paqui.signForm(fo);
		std::cout << fo << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	try {
		std::cout << "## MANOLI - FORMULARIO 0##" << std::endl;
		Bureaucrat manoli = Bureaucrat("Manoli", 150);
		std::cout << manoli << std::endl;
		Form fo = Form("Formulario 0", 0, 3); //This print exception
	
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	return 0;
}
