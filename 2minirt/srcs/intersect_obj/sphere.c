/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osurcouf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 14:21:15 by osurcouf          #+#    #+#             */
/*   Updated: 2021/06/28 17:17:21 by osurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** 🦕
**
** function : Sphere intersection
**
**	1. We calculate the sphere intersection point.
**		It's a good idea to start with that one to
**		figure out how miniRT works.
**
**		Good ressource to understand the equation
**			https://www.youtube.com/watch?v=HFPlKQGChpE
**
** 🦕
*/

void	sphere_normal(t_rec *curr)
{
	t_vec	hit_to_center;

	hit_to_center = substract(curr->hit.point, curr->obj.shape.sp.point);
	curr->hit.normal = divide(hit_to_center, curr->obj.shape.sp.radius);
}

float	sphere(t_ray *ray, t_rec *curr)
{
	t_sphere	*sp;
	t_vec		center_origin;
	t_params	param;

	sp = &curr->obj.shape.sp;
	center_origin = substract(ray->origin, sp->point);
	param.a = length(ray->dir);
	param.b = dot_product(center_origin, ray->dir);
	param.c = length(center_origin)
		- sp->radius * sp->radius;
	if (solve_quadratic(param, &curr->t0, &curr->t1))
	{
		if (curr->t0 > 0)
			return (curr->t0);
		if (curr->t1 > 0)
			return (curr->t1);
	}
	return (0.0);
}
