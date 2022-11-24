/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <migarcia@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 18:08:37 by migarcia          #+#    #+#             */
/*   Updated: 2022/11/21 11:29:14 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	// ShrubberyCreationForm
	std::cout << "## ShrubberyCreationForm ##" << std::endl;
	Form		*tree = new ShrubberyCreationForm("Tree");
	Bureaucrat	corr1("Pepe", 137);
	Bureaucrat	corr2("Juan", 140);
	Bureaucrat	corr3("Maria", 148);

	std::cout << corr1 << std::endl;
	std::cout << corr2 << std::endl;
	std::cout << corr3 << std::endl;
	corr3.executeForm(*tree);
	corr3.signForm(*tree);
	corr2.signForm(*tree);
	std::cout << *tree << std::endl;
	corr1.executeForm(*tree);
	corr2.executeForm(*tree);
	corr3.executeForm(*tree);
	std::cout << std::endl;
	delete tree;

	// RobotomyRequestForm
	std::cout << "## RobotomyRequestForm ##" << std::endl;
	Form		*robot = new RobotomyRequestForm("Robot");

	corr1 = Bureaucrat("Pepe", 35);
	corr2 = Bureaucrat("Juan", 47);
	corr3 = Bureaucrat("Maria", 85);
	std::cout << corr1 << std::endl;
	std::cout << corr2 << std::endl;
	std::cout << corr3 << std::endl;
	corr3.executeForm(*robot);
	corr3.signForm(*robot);
	corr2.signForm(*robot);
	std::cout << *robot << std::endl;
	corr1.executeForm(*robot);
	corr2.executeForm(*robot);
	corr3.executeForm(*robot);
	std::cout << std::endl;
	delete robot;

	// PresidentialPardonForm
	std::cout << "## PresidentialPardonForm ##" << std::endl;
	Form		*pardon = new PresidentialPardonForm("Thief");

	corr1 = Bureaucrat("Pepe", 5);
	corr2 = Bureaucrat("Juan", 7);
	corr3 = Bureaucrat("Maria", 28);
	std::cout << corr1 << std::endl;
	std::cout << corr2 << std::endl;
	std::cout << corr3 << std::endl;
	corr3.executeForm(*pardon);
	corr3.signForm(*pardon);
	corr2.signForm(*pardon);
	std::cout << *pardon << std::endl;
	corr1.executeForm(*pardon);
	corr2.executeForm(*pardon);
	corr3.executeForm(*pardon);
	std::cout << std::endl;
	delete pardon;

	return 0;
}
