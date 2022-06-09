/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <migarcia@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 10:55:27 by migarcia          #+#    #+#             */
/*   Updated: 2022/06/08 14:51:40 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point():_x(0), _y(0){
	return ;
}

Point::Point(const Point &copy){
	*this = copy;
	return ;
}

Point::Point(const float x, const float y):_x(Fixed(x)), _y(Fixed(y)){
	return ;
}

Point::~Point(){
	return ;
}

Point &Point::operator=(const Point &Obj){
	if (this != &Obj){ //Comprueba que no se esté intentando igualar un objeto a sí mismo
		this->_x = Obj.getX();
		this->_y = Obj.getY();
	}
	return *this;
}

Fixed Point::getX() const{
	return this->_x;
}

Fixed Point::getY() const{
	return this->_y;
}

float Point::getXflo() const{
	return this->_x.toFloat();
}

float Point::getYflo() const{
	return this->_y.toFloat();
}

std::ostream &operator<<(std::ostream &o, const Point &point)
{
	o << "(" << point.getX() << "," << point.getY() << ")";
	return (o);
}
