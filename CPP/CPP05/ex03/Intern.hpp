/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <migarcia@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:40:16 by migarcia          #+#    #+#             */
/*   Updated: 2022/11/21 15:01:34 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_H
# define INTERN_H
# include <string>
# include <iostream>
# include "Form.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern{
	private:
		Form	*decideForm(std::string form, std::string target);
		Form	*Shrubbery(const std::string target);
		Form	*Robotomy(const std::string target);
		Form	*Presidential(const std::string target);
	public:
		Intern();
		Intern(const Intern &copy);
		~Intern();

		Intern		&operator=(const Intern &obj);
		Form		*makeForm(const std::string formName, const std::string target);
		
		class createFormException: public std::exception {
                        public:
                                const char * what() const throw();
                };
};

#endif
