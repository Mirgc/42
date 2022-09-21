/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <migarcia@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:44:40 by migarcia          #+#    #+#             */
/*   Updated: 2022/09/17 18:26:56 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed():_fix(0){
	std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::Fixed(const int integer):_fix(integer << _frac){
	std::cout << "Int constructor called" << std::endl;
	return ;
}

//Fixed::Fixed(const float fraction):_fix((int)roundf(fraction * (1 << _frac))){
Fixed::Fixed(const float fraction):_fix(roundf(fraction * (1 << _frac))){
	std::cout << "Float constructor called" << std::endl;
	return ;
}

Fixed::Fixed(const Fixed &copy){
	std::cout << "Copy constructor called" << std::endl,
	*this = copy; //llamamos al operador que hemos declarado.
	return ;
}

Fixed::~Fixed(void){
	std::cout << "Destructor called" << std::endl;
	return ;
}

Fixed &Fixed::operator=(const Fixed &fixOb){
	std::cout << "Assignation operator called" << std::endl;
	if (this != &fixOb) //Comprueba que no se esté intentando igualar un objeto a sí mismo
		this->_fix = fixOb.getRawBits();
	return *this;
}

std::ostream &operator<<(std::ostream &o,const Fixed &fixOb){
	o << fixOb.toFloat();
	return o;
}


int Fixed::getRawBits(void) const{
	return this->_fix;
}

void Fixed::setRawBits( int const fix ){
	this->_fix = fix;
	std::cout << "setRawBits member function called" << std::endl;
}

float Fixed::toFloat( void ) const{
//	float temp = (float)this->_fix / 256;
//	std::cout << std::endl << "float: " << this->_fix << "binario: " << (1 << _frac) << std::endl;
//	return (temp);
	return ((float)this->_fix / (1 << _frac));
}

int Fixed::toInt( void ) const{
	return _fix >> _frac;
	//return ((int)(roundf((float)this->_fix / (1 << _frac))));
}
