/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <migarcia@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:44:40 by migarcia          #+#    #+#             */
/*   Updated: 2022/06/09 08:37:26 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed():_fix(0){
	return ;
}

Fixed::Fixed(const int integer):_fix(integer << _frac){
	return ;
}

Fixed::Fixed(const float fraction):_fix((int)roundf(fraction * (1 << _frac))){
	return ;
}

Fixed::Fixed(const Fixed &copy){
	*this = copy; //llamamos al operador que hemos declarado.
	return ;
}

Fixed::~Fixed(void){
	return ;
}

Fixed &Fixed::operator=(const Fixed &fixOb){
	if (this != &fixOb) //Comprueba que no se esté intentando igualar un objeto a sí mismo
		this->_fix = fixOb.getRawBits();
	return *this;
}

// COMPARISON OPERATORS //
bool Fixed::operator>(const Fixed &fixOb){
	return this->_fix > fixOb._fix;
}

bool Fixed::operator<(const Fixed &fixOb){
	return this->_fix < fixOb._fix;
}

bool Fixed::operator>=(const Fixed &fixOb){
	return this->_fix >= fixOb._fix;
}

bool Fixed::operator<=(const Fixed &fixOb){
	return this->_fix <= fixOb._fix;
}

bool Fixed::operator==(const Fixed &fixOb){
	return this->_fix == fixOb._fix;
}

bool Fixed::operator!=(const Fixed &fixOb){
	return this->_fix != fixOb._fix;
}

// ARITHMETIC OPERATORS //
Fixed Fixed::operator+(const Fixed &fixOb){
	return (Fixed(this->toFloat() + fixOb.toFloat()));
}

Fixed Fixed::operator-(const Fixed &fixOb){
	return (Fixed(this->toFloat() - fixOb.toFloat()));
}

Fixed Fixed::operator*(const Fixed &fixOb){
	return (Fixed(this->toFloat() * fixOb.toFloat()));
}

Fixed Fixed::operator/(const Fixed &fixOb){
	return (Fixed(this->toFloat() / fixOb.toFloat()));
}

// Define preincrement operator.
Fixed &Fixed::operator++(){
	++_fix;
	return *this;
}

// Define postincrement operator.
Fixed Fixed::operator++(int){
	Fixed temp = *this;
	
	_fix++;
	return temp;
}

// Define predecrement operator.
Fixed &Fixed::operator--(){
	_fix--;
	return *this;
}

// Define postdecrement operator.
Fixed Fixed::operator--(int){
	Fixed temp = *this;
	
	_fix--;
	return temp;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b){
	return a.getRawBits() <= b.getRawBits() ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b){
	return a.getRawBits() >= b.getRawBits() ? a : b;
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
}

float Fixed::toFloat( void ) const{
	return ((float)this->_fix / (1 << _frac));
}

int Fixed::toInt( void ) const{
	return _fix << _frac; 
}
