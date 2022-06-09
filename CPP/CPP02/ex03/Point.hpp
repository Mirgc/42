/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <migarcia@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 10:50:59 by migarcia          #+#    #+#             */
/*   Updated: 2022/06/08 14:57:10 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_H
# define POINT_H
# include "Fixed.hpp"

class Point{
	private:
		Fixed _x;
		Fixed _y;
	public:
		Point();
		Point(const Point &copy);
		Point(const float x, const float y);
		~Point();
		Point &operator=(const Point &obj);
//		Point operator-(const Point &Obj) const;
		Fixed getX() const;
		Fixed getY() const;
		float getXflo() const;
		float getYflo() const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);
std::ostream &operator<<(std::ostream &o, const Point &point);

#endif
