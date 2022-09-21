/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <migarcia@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:40:16 by migarcia          #+#    #+#             */
/*   Updated: 2022/09/17 18:42:47 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H
# include <iostream>

class Fixed{
	private:
		int _fix;
		static const int _frac = 8;
	
	public:
		Fixed();
		Fixed(const Fixed &copy);
		Fixed(const int integer);
		Fixed(const float fraction);
		~Fixed();
		// Sobrecarga del operador
		//	Sintaxis: tipo  operator + (lista de parámetros);

		//	tipo se refiere al tipo regresado por el operador
		//	operator es una palabra reservada y debe aparecer en toda declaración de sobrecarga de operadores
		//	el simbolo + está en representación de cualquier operador
		//	lista de parámetros indica los argumentos sobre los que operarará la función de sobrecarga
		Fixed &operator=(const Fixed &fixOb);
		bool operator>(const Fixed &fixOb);
		bool operator<(const Fixed &fixOb);
		bool operator>=(const Fixed &fixOb);
		bool operator<=(const Fixed &fixOb);
		bool operator==(const Fixed &fixOb);
		bool operator!=(const Fixed &fixOb);

		Fixed operator+(const Fixed &fixOb);
		Fixed operator-(const Fixed &fixOb);
		Fixed operator*(const Fixed &fixOb);
		Fixed operator/(const Fixed &fixOb);

		Fixed &operator++();       // Preincrement operator.
		Fixed operator++( int n );       // Postincrement operator.
		Fixed &operator--();       // Predecrement operator.
		Fixed operator--( int n );       // Postdecrement operator.
		
		static const Fixed &min(const Fixed &a, const Fixed &b);
		static const Fixed &max(const Fixed &a, const Fixed &b);

		int getRawBits( void ) const;
		void setRawBits( int const fix );
		float toFloat( void ) const;
		int toInt( void ) const;
};

std::ostream &operator<<(std::ostream &o, const Fixed &fixOb);

#endif
