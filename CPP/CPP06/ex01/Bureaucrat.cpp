/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <migarcia@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:44:40 by migarcia          #+#    #+#             */
/*   Updated: 2022/11/20 13:39:05 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void){
}

Bureaucrat::Bureaucrat(std::string name, int grade):_name(name), _grade(grade){
	checkGrade();
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy):_name(copy._name), _grade(copy._grade){
}

Bureaucrat::~Bureaucrat(void){
//	std::cout << "Bureaucrat destructor called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &obj){
	if (this != &obj)
		this->_grade = obj._grade;
	return *this;
}

std::ostream		&operator<<(std::ostream &o, const Bureaucrat &bureaucrat)
{
	o << "   " << bureaucrat.getName() << ", grade " << bureaucrat.getGrade();
	return (o);
}

const std::string	Bureaucrat::getName(void) const{
	return this->_name;
}

int			Bureaucrat::getGrade(void) const{
	return this->_grade;
}

void			Bureaucrat::checkGrade(void){
	if (_grade < 1)
		throw (gradeTooHighException());
	if (_grade > 150)
		throw (gradeTooLowException());
}

void			Bureaucrat::incrementGrade(void){
	_grade--;
	checkGrade();
}
	
void			Bureaucrat::decrementGrade(void){
	_grade++;
	checkGrade();
}

void			Bureaucrat::signForm(Form &form) const{
	try {
		form.beSigned(*this);
		std::cout << "   " << _name << " signs " << form.getName() << std::endl;
	}
	catch (const std::exception &e) {
		std::cout << e.what() << ". " << _name << " couldn't sign " << form.getName() << std::endl;
	}
}

const char *Bureaucrat::gradeTooHighException::what() const throw()
{
	return "ERROR: Grade too high";
}

const char *Bureaucrat::gradeTooLowException::what() const throw()
{
	return "ERROR: Grade too low";
}
