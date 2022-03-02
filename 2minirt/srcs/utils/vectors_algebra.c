/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils.c	                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osurcouf <.@student.42lisboa.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 18:45:46 by osurcouf          #+#    #+#             */
/*   Updated: 2021/04/26 18:45:48 by osurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** 🦕
**
** function : Algebra utilities.
**		I'll write what I think I understood. Last time I
**		did maths was 10 years ago though. Don't take it
**		too seriously.
**
**	3. length
**		gives the length of a vector by doing a dot_product of (vec1, vec1).
**	2. Dot_product
**		usually gets you an angle (vec1, vec2) or a length (vec1, vec1).
**	3. Cross_product
**		will calculate the angle between two vectors and calculate
**		the orientation of the infinite plane in between them.
**		That is why you will use it mostly for squares or triangles
**		which are basically finite planes with a specific shape.
**	4. Normalize
**		super important calculation that will take a vector and resize it
**		so that its length is 1, thus making it a unit vector.
**		Note : don't forget to normalize. And don't forget not to normalize.
**				Think of that first when you debug.
**
** 🦕
*/

float	length(t_vec v)
{
	return (v.x * v.x + v.y * v.y + v.z * v.z);
}

float	dot_product(t_vec v1, t_vec v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

t_vec	cross_product(t_vec v1, t_vec v2)
{
	t_vec	v;

	v.x = v1.y * v2.z - v1.z * v2.y;
	v.y = v1.z * v2.x - v1.x * v2.z;
	v.z = v1.x * v2.y - v1.y * v2.x;
	return (v);
}

t_vec	normalize(t_vec v)
{
	t_vec	unit_vector;
	float	len;

	len = sqrt(length(v));
	if (len == 0)
		len = 1;
	unit_vector.x = v.x / len;
	unit_vector.y = v.y / len;
	unit_vector.z = v.z / len;
	return (unit_vector);
}
