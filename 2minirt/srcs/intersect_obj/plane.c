/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osurcouf <.@student.42lisboa.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 00:58:46 by osurcouf          #+#    #+#             */
/*   Updated: 2021/05/30 00:58:49 by osurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** 🦕
**
** function : Plane intersection
**
**	Easiest shape of all !
**	We just calculate the the intersection point
**	from the angle between the cam_ray to pixel
**	and cam_ray to the center of the plane.
**	It's an infinite plane so we don't check for
**	size limits. It just has to hit where the plane
**	surface is.
**
**	Note : Since the normal is super simple
**			(normalize the position of the hit point),
**			it's in Intersect_object.
**
** 🦕
*/

float	plane(t_ray *ray, t_rec *curr, t_vec point, t_vec orient)
{
	t_vec	ray_to_center;
	float	perpendicular;

	perpendicular = dot_product(ray->dir, orient);
	if (!perpendicular)
		return (0.0);
	ray_to_center = substract(point, ray->origin);
	curr->hit.t = dot_product(ray_to_center, orient) / perpendicular;
	return (curr->hit.t);
}
