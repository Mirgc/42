/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tuple.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikgarci <mikgarci@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 18:27:58 by mikgarci          #+#    #+#             */
/*   Updated: 2022/02/18 22:51:37 by mikgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algft.h"

t_tuple	ft_vector(float x, float y, float z)
{
	t_tuple	vector;

	vector.x = x;
	vector.y = y;
	vector.z = z;
	vector.w = 0;
	return (vector);
}

t_tuple	ft_point(float x, float y, float z)
{
	t_tuple	point;

	point.x = x;
	point.y = y;
	point.z = z;
	point.w = 1;
	return (point);
}
