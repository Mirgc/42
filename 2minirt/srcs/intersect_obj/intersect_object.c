/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_object.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osurcouf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 14:20:33 by osurcouf          #+#    #+#             */
/*   Updated: 2021/06/28 14:53:01 by osurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** 🦕
**
** function : Intersect Objects
**
**	1. First, we check for every pixel if the camera
**	ray hit an object in the scene and we determine which
**	is closest to the camera eye.
**	If it does, we calculate where it intersect
**	- distance (from cam to hit) : hit.t
**	- position : hit.point
**	- orientation : hit.normal
**	If the ray goes to "infinity", it means it hits nothing.
**		Note : we already calculate the hit.point in the
**				square and circle (cylinder caps) function.
**				No need to do it again.
**
**	2. If it hits an object, it need to compute the accurate
**		function.
**
**	3. Same for the hit.normal that is different for every
**		object and will affect how to diffuse the light.
**
** 🦕
*/

static void	get_obj_normal(t_rec *curr)
{
	if (curr->obj.type == PLANE)
		curr->hit.normal = normalize(curr->obj.shape.pl.orient);
	if (curr->obj.type == SPHERE)
		sphere_normal(curr);
	if (curr->obj.type == CYLINDER)
		cylinder_normal(curr);
	if (curr->obj.type == CIRCLE)
		curr->hit.normal = normalize(curr->obj.shape.ci.orient);
	if (curr->obj.type == SQUARE)
		curr->hit.normal = normalize(curr->obj.shape.sq.orient);
}

float	intersect_obj(t_ray *ray, t_rec *curr)
{
	t_plane	plan;

	if (curr->obj.type == PLANE)
	{
		plan = curr->obj.shape.pl;
		return (plane(ray, curr, plan.point, plan.orient));
	}
	if (curr->obj.type == SPHERE)
		return (sphere(ray, curr));
	if (curr->obj.type == CYLINDER)
		return (cylinder(ray, curr));
	if (curr->obj.type == CIRCLE)
		return (circle(ray, curr));
	if (curr->obj.type == SQUARE)
		return (square(ray, curr));
	return (0);
}

void	check_if_it_hits_object(t_rt *rt)
{
	int		k;
	t_rec	temp;
	float	intersect_point;

	k = 0;
	rt->curr.hit.t = INFINITY;
	while (k < rt->infos->nb_objs)
	{
		temp.obj = rt->infos->objs[k];
		intersect_point = intersect_obj(&rt->cam_ray, &temp);
		if (intersect_point > 0.0 && intersect_point < rt->curr.hit.t)
		{
			rt->curr.obj = rt->infos->objs[k];
			rt->curr.hit.t = intersect_point;
		}
		k++;
	}
	if (rt->curr.hit.t != INFINITY)
	{
		rt->curr.hit.point = add(rt->cam_ray.origin,
				multiply(rt->cam_ray.dir, rt->curr.hit.t));
		get_obj_normal(&rt->curr);
	}
}
