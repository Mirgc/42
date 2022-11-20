/* ************************************************************************** */
/*                                                                            */
/*                                                        :::.     ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <migarcia@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 17:46:02 by migarcia          #+#    #+#             */
/*   Updated: 2022/11/20 18:38:23 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void): Form("Shrubbery creation", 145, 137), _target("none"){
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target): Form("Shrubbery creation", 145, 137), _target(target){
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy): Form("Shrubbery creation", 145, 137), _target(copy._target){
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &obj){
	(void)obj;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(void){
}

std::string ShrubberyCreationForm::getTarget() const
{
    return this->_target;
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const{
	checkExecute(executor);

	std::ofstream _file;
	_file.open((_target + "_shrubbery").c_str());
	if (!_file.is_open())
		throw openFile();
	_file << "┈┈╱╲┈┈┈╱╲┈┈┈╱╲┈┈" << std::endl;
	_file << "┈╱╯╰╲┈┈╳╳┈┈╱╯╰╲┈" << std::endl;
	_file << "╱╯╯╰╰╲╱╮╰╲╱╯╯╰╰╲" << std::endl;
	_file << "╱╯╯╰╰╱╰╯╭╮╲╯╯╰╰╰" << std::endl;
	_file << "╱╯╯╰╱╯╭╮╰╯╭╲╯╰╰╰" << std::endl;
	_file << "╱▔▋╱╭╮╰╯╭╮╰╯╲▋▔▔" << std::endl;
	_file << "╱┈╱╮╰╯╭╮╰╯╭╮╰╲┈┈" << std::endl;
	_file << "╱┈▔▔▔▔▔▔▋▔▔▔▔▔┈┈" << std::endl;
	_file.close();
}
