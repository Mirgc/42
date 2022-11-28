/* ************************************************************************** */
/*                                                                            */
/*                                                        :::.     ::::::::   */
/*   Cast.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <migarcia@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:44:40 by migarcia          #+#    #+#             */
/*   Updated: 2022/11/28 12:08:07 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cast.hpp"

Cast::Cast(void){
}

Cast::Cast(std::string name, int grade):_name(name), _grade(grade){
	checkGrade();
}

Cast::Cast(const Cast &copy):_name(copy._name), _grade(copy._grade){
}

Cast::~Cast(void){
//	std::cout << "Cast destructor called" << std::endl;
}

Cast &Cast::operator=(const Cast &obj){
	if (this != &obj)
		this->_grade = obj._grade;
	return *this;
}

std::ostream		&operator<<(std::ostream &o, const Cast &bureaucrat)
{
	o << bureaucrat.getName() << ", grade " << bureaucrat.getGrade();
	return (o);
}

const std::string	Cast::getName(void) const{
	return this->_name;
}

int			Cast::getGrade(void) const{
	return this->_grade;
}

void			Cast::checkGrade(void){
	if (_grade < 1)
		throw (gradeTooHighException());
	if (_grade > 150)
		throw (gradeTooLowException());
}

void			Cast::incrementGrade(void){
	_grade--;
	checkGrade();
}
	
void			Cast::decrementGrade(void){
	_grade++;
	checkGrade();
}

const char *Cast::gradeTooHighException::what() const throw()
{
	return "ERROR: Grade too high";
}

const char *Cast::gradeTooLowException::what() const throw()
{
	return "ERROR: Grade too low";
}
