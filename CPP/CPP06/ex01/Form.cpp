/* ************************************************************************** */
/*                                                                            */
/*                                                        :::.     ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <migarcia@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:44:40 by migarcia          #+#    #+#             */
/*   Updated: 2022/11/20 13:35:37 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void):_name("none"), _gradeSign(150), _gradeExec(150), _signed(false){
}

Form::Form(std::string name, int gradeSign, int gradeExec):_name(name), _gradeSign(gradeSign), _gradeExec(gradeExec), _signed(false){
	checkGrade();
}

Form::Form(const Form &copy):_name(copy._name), _gradeSign(copy._gradeSign), _gradeExec(copy._gradeExec), _signed(false){
}

Form::~Form(void){
//	std::cout << "Form destructor called" << std::endl;
}

Form &Form::operator=(const Form &obj){
	if (this != &obj){
		this->_signed = obj._signed;
	}
	return *this;
}

std::ostream		&operator<<(std::ostream &o, const Form &forms)
{
	o << "   [" << forms.getName() << "]" << std::endl;
	o << "   Grade need to sign: " << forms.getGradeSign() << std::endl;
	o << "   Grade need to execute: " << forms.getGradeExec() << std::endl;
	o << "   Signed: " << forms.getSigned() << std::endl;
	return (o);
}

const std::string	Form::getName(void) const{
	return this->_name;
}

bool			Form::getSigned(void) const{
	return this->_signed;
}

int			Form::getGradeSign(void) const{
	return this->_gradeSign;
}

int			Form::getGradeExec(void) const{
	return this->_gradeExec;
}

void			Form::checkGrade(void){
	if (_gradeSign < 1 || _gradeExec < 1)
		throw (gradeTooHighException());
	if (_gradeSign > 150 || _gradeExec > 150)
		throw (gradeTooLowException());
}

void			Form::beSigned(const Bureaucrat &bureaucrat){
	if (bureaucrat.getGrade() > _gradeSign)
		throw (gradeTooLowException());
	_signed = true;
}

const char *Form::gradeTooHighException::what() const throw()
{
	return "ERROR: Grade too high";
}

const char *Form::gradeTooLowException::what() const throw()
{
	return "ERROR: Grade too low";
}
