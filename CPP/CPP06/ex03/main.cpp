/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <migarcia@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 18:08:37 by migarcia          #+#    #+#             */
/*   Updated: 2022/11/21 15:16:24 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	Intern		Antonio;
	Form		*form[4];
	Bureaucrat	corr1("Pepe", 5);

	form[0] = Antonio.makeForm("shrubbery creation", "kk0");
	form[1] = Antonio.makeForm("robotomy request", "kk1");
	form[2] = Antonio.makeForm("presidential pardon", "kk2");
	form[3] = Antonio.makeForm("pipipipi", "kk3");
	std::cout << std::endl;
	std::cout << corr1 << std::endl;
	for (int i=0; i < 4; i++){
		if (form[i]){
			corr1.signForm(*(form[i]));
			std::cout << *(form[i]) << std::endl;
			corr1.executeForm(*(form[i]));
			std::cout << std::endl;
		}
	}
	for (int i=0; i < 4; i++)
		delete form[i];

	return 0;
}
