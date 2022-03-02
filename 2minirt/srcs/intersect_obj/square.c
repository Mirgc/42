/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osurcouf <.@student.42lisboa.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 05:45:03 by osurcouf          #+#    #+#             */
/*   Updated: 2021/06/30 16:51:43 by osurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** 🦕
**
** function : Square intersection
**
**	1. Squares basically are planes that are finite.
**		So we first get the plane intersection and then
**		only accept it as a valid intersection if it's
**		within the boundaries of the square.
**		Note : At one point, do cubes out of squares.
**				Should be pretty easy.
**
** 🦕
*/

float	square(t_ray *ray, t_rec *curr)
{
	t_square	*square;
	float		result;
	t_vec		center_to_hit;
	t_vec		hit_point;

	square = &curr->obj.shape.sq;
	result = plane(ray, curr, square->point, square->orient);
	if (result > 0.0f)
	{
		hit_point = add(ray->origin, multiply(ray->dir, result));
		center_to_hit = substract(hit_point, square->point);
		if (result < 0.0f)
			return (0.0);
		else if (fabs(center_to_hit.x) > square->side / 2
			|| fabs(center_to_hit.y) > square->side / 2
			|| fabs(center_to_hit.z) > square->side / 2)
			return (0.0);
		return (result);
	}
	return (0.0);
}
