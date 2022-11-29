/* ************************************************************************** */
/*                                                                            */
/*                                                        :::.     ::::::::   */
/*   Cast.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <migarcia@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:44:40 by migarcia          #+#    #+#             */
/*   Updated: 2022/11/29 14:26:31 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cast.hpp"

Cast::Cast(void): _char(0), _int(0), _float(0.0f), _double(0.0), _str(""), _type(INVALID), _isWrong(false){
}

Cast::Cast(const char *argv): _char(0), _int(0), _float(0.0f), _double(0.0), _str(""), _type(INVALID), _isWrong(false){
	this->_str = argv;
	void (Cast::*function[4])(const char *) = {&Cast::castChar, &Cast::castInt, &Cast::castFloat, &Cast::castDouble};

	std::string _limits[4] = {"inf", "+inf", "-inf", "nan"};
	for (int i = 0; i < 4; i++){
		if (!_str.compare(_limits[i]) || !_str.compare(_limits[i] + 'f')){
			//print char
			std::cout << "char: impossible" << std::endl;
			//print int
			std::cout << "int: impossible" << std::endl;
			//print float
			std::string toPrint;
			toPrint = _limits[i] + 'f';
			std::cout << "float: " << toPrint << std::endl;
			//print double
			toPrint = _limits[i];
			std::cout << "double: " << toPrint << std::endl;
			return ;
		}
	}
	checkType(argv);
	if (_type == INVALID)
		_isWrong = true;
	else
		(this->*(function[_type]))(argv);
}

Cast::Cast(const Cast &copy){
	*this = copy;
}

Cast::~Cast(void){
}

Cast &Cast::operator=(const Cast &obj){
	(void)obj;
	return *this;
}

std::ostream		&operator<<(std::ostream &o, const Cast &bureaucrat)
{
	(void)bureaucrat;
//	o << bureaucrat.getName() << ", grade " << bureaucrat.getGrade();
	return (o);
}

int Cast::getType() const{
	return this->_type;
}

void Cast::setType(int type){
	this->_type = type;
}

void Cast::checkType(const char *val){
	int	i = 0;
	int _dot = 0;
	int _f = 0;
	int _num = 0;

	while (val[i]){
		if ((val[i] == '-' || val[i] == '+') && val == 0)
			_num = 1;
		else if (std::isdigit(val[i]))
			_num = 1;
		else if (val[i] == '.')
			_dot = 1;
		else if (val[i] == 'f' && (int)std::strlen(val) - 1  == i)
			_f = 1;
		i++;
	}
	if (i == 1)
		this->setType(CHAR);
	else if (_num == 1 && _dot == 1 && _f == 1)
		this->setType(FLOAT);
	else if (_num == 1 && _dot == 1 && _f == 0)
		this->setType(DOUBLE);
	else if (_num == 1 && _dot == 0 && _f == 0)
		this->setType(INT);
	else
		this->setType(INVALID);
}

void	Cast::print(){
	printChar();
	printInt();
	printFloat();
	printDouble();
}

void	Cast::printChar() const{
	std::cout << "char: ";
	if (this->_char >= 32 && this->_char <= 126)
		std::cout << this->_char << std::endl;
	else
		std::cout << "Non displayable." << std::endl;
}

void	Cast::printInt() const{
	std::cout << "int: ";
	if (this->_type == INVALID)
		std::cout << "impossible" << std::endl;
	else if (this->_isWrong == true)
		std::cout << "overflow" << std::endl;
	else if (std::stol(this->_str) < INT_MIN || std::stol(this->_str) > INT_MAX)
		std::cout << "overflow" << std::endl;
	else
		std::cout << this->_int << std::endl;
}

void	Cast::printFloat() const{
	std::cout << "float: ";
 	if (this->_type == INVALID)
		std::cout << "impossible" << std::endl;
	else if (std::stol(this->_str) >= INT_MIN && std::stol(this->_str) <= INT_MAX)
		std::cout << std::fixed << std::setprecision(1) << this->_float << "f" << std::endl;
	else
		std::cout << this->_str << "f" << std::endl;
}

void	Cast::printDouble() const{
	std::cout << "double: ";
	if (this->_type == INVALID)
		std::cout << "impossible" << std::endl;
	else if (std::stol(this->_str) >= INT_MIN && std::stol(this->_str) <= INT_MAX)
		std::cout << std::fixed << std::setprecision(1) << this->_double << std::endl;
	else
		std::cout << this->_str << std::endl;
}

void	Cast::castChar(const char *argv){
	this->_char = argv[0];
	this->_int = static_cast<int>(this->_char);
	this->_float = static_cast<float>(this->_char);
	this->_double = static_cast<double>(this->_char);
}

void	Cast::castInt(const char *argv){
	if (std::stol(this->_str) >= INT_MIN && std::stol(this->_str) <= INT_MAX){
		this->_int = std::stoi(argv);
		this->_char = static_cast<char>(this->_int);
		this->_float = static_cast<float>(this->_int);
		this->_double = static_cast<double>(this->_int);
	}
	else
		this->_isWrong = true;
}

void	Cast::castFloat(const char *argv){
	this->_float = std::stof(argv);
	this->_char = static_cast<char>(this->_float);
	this->_int = static_cast<int>(this->_float);
	this->_double = static_cast<double>(this->_float);
}

void	Cast::castDouble(const char *argv){
	this->_double = std::stod(argv);
	this->_char = static_cast<char>(this->_double);
	this->_int = static_cast<int>(this->_double);
	this->_float = static_cast<float>(this->_double);
}

