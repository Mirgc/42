/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <migarcia@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 18:08:37 by migarcia          #+#    #+#             */
/*   Updated: 2022/11/20 18:46:16 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
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
	delete tree;

	return 0;
}
