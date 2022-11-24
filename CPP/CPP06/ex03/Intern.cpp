/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <migarcia@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:44:40 by migarcia          #+#    #+#             */
/*   Updated: 2022/11/21 15:15:03 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void){
}

Intern::Intern(const Intern &copy){
	*this = copy;
}

Intern::~Intern(void){
//	std::cout << "Intern destructor called" << std::endl;
}

Intern &Intern::operator=(const Intern &obj){
	(void)obj;
	return *this;
}

Form	*Intern::makeForm(std::string formName, std::string target){
	Form *formptr = NULL;
	const std::string form_ref[3] = { "shrubbery creation", "robotomy request", "presidential pardon" };
        Form* (Intern::*function[3])(std::string) = { &Intern::Shrubbery, &Intern::Robotomy, &Intern::Presidential };

        for (int i = 0; i < 3; i++)
        {
                if (!formName.compare(form_ref[i]))
                        formptr = (this->*function[i])(target);
        }
	try {
		if (!formptr)
                	throw createFormException();
		else
			std::cout << "   " << formName << " was created whith target:  " << target << std::endl;
        }
        catch (const std::exception &e) {
                std::cout << e.what() << ". " << formName << " doesn't exist." << std::endl;
        }
	return formptr;
}


Form	*Intern::Shrubbery(const std::string target){
	return (new ShrubberyCreationForm(target)); 
}

Form	*Intern::Robotomy(const std::string target){
	return (new RobotomyRequestForm(target)); 
}

Form	*Intern::Presidential(const std::string target){
	return (new PresidentialPardonForm(target)); 
}

const char *Intern::createFormException::what() const throw()
{
        return "ERROR: cann't create Form.";
}


