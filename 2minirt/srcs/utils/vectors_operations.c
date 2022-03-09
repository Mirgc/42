/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_operations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osurcouf <.@student.42lisboa.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 17:03:10 by osurcouf          #+#    #+#             */
/*   Updated: 2021/04/26 17:03:11 by osurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** 🦕
**
** function : Vector operations utilities
**
** Various operations to save space in your code.
**	1. Create vector
**	2. Add vectors
**	3. Substract vectors
**	4. Multiply vector (by a float)
**	5. Divide vector (by a float)
**
** 🦕
*/

t_vec	create_vec(float a, float b, float c)
{
	t_vec	v;

	v.x = a;
	v.y = b;
	v.z = c;
	return (v);
}

t_vec	add(t_vec v1, t_vec v2)
{
	t_vec	v;

	v.x = v1.x + v2.x;
	v.y = v1.y + v2.y;
	v.z = v1.z + v2.z;
	return (v);
}

t_vec	substract(t_vec v1, t_vec v2)
{
	t_vec	v;

	v.x = v1.x - v2.x;
	v.y = v1.y - v2.y;
	v.z = v1.z - v2.z;
	return (v);
}

t_vec	multiply(t_vec v1, float m)
{
	t_vec	v;

	v.x = v1.x * m;
	v.y = v1.y * m;
	v.z = v1.z * m;
	return (v);
}

t_vec	divide(t_vec v1, float d)
{
	t_vec	v;

	v.x = v1.x / d;
	v.y = v1.y / d;
	v.z = v1.z / d;
	return (v);
}
