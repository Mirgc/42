/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <migarcia@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 15:42:41 by migarcia          #+#    #+#             */
/*   Updated: 2022/06/08 14:59:11 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// Referencia: http://www.dma.fi.upm.es/personal/mabellanas/tfcs/kirkpatrick/Aplicacion/algoritmos.htm#puntoInteriorDefinicion

float orient (Point p1, Point p2, Point p3)
{
	float f;

	f = (p1.getXflo() - p3.getXflo()) * (p2.getYflo() - p3.getYflo()) \
		- (p1.getYflo() - p3.getYflo()) * (p2.getXflo() - p3.getXflo());
	return (f);
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{

	float	areaABP = orient(a, b, point);
	float	areaBCP = orient(b, c, point);
	float	areaCAP = orient(c, a, point);

	// Si las tres orientaciones son positivas esta dentro
	bool PosArea = areaABP >= 0 && areaBCP >= 0 && areaCAP >= 0;
	// Si las tres orientaciones son negativas esta dentro
	bool NegArea = areaABP <= 0 && areaBCP <= 0 && areaCAP <= 0;

	return (PosArea || NegArea);
}
