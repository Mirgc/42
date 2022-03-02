/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osurcouf <.@student.42lisboa.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 06:41:37 by osurcouf          #+#    #+#             */
/*   Updated: 2021/06/28 17:35:57 by osurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** 🦕
**
** function : Triangle
**
**		Sadly, does not work at the moment. (At all)
**
** 🦕
*/

void	triangle_normal(t_rec *curr)
{
	t_vec		point1_to_point2;
	t_vec		point1_to_point3;
	t_vec		plane_orientation;
	t_triangle	*triangle;

	triangle = &curr->obj.shape.tr;
	point1_to_point2 = substract(triangle->point2, triangle->point1);
	point1_to_point3 = substract(triangle->point3, triangle->point1);
	plane_orientation = cross_product(point1_to_point2, point1_to_point3);
	curr->hit.normal = normalize(plane_orientation);
}

bool	check_edges(t_rec *curr, t_vec	point1, t_vec point2,
	t_vec plane_orientation)
{
	t_vec	edge;
	t_vec	distance;
	t_vec	edge_orientation;

	edge = substract(point2, point1);
	distance = substract(curr->hit.point, point1);
	edge_orientation = cross_product(edge, distance);
	if (dot_product(edge_orientation, plane_orientation) < 0)
		return (false);
	return (true);
}

float	triangle(t_ray *ray, t_rec *curr)
{
	t_triangle	*triangle;
	t_vec		point1_to_point2;
	t_vec		point1_to_point3;
	t_vec		plane_orient;
	float		angle;

	triangle = &curr->obj.shape.tr;
	point1_to_point2 = substract(triangle->point2, triangle->point1);
	point1_to_point3 = substract(triangle->point3, triangle->point1);
	plane_orient = cross_product(point1_to_point2, point1_to_point3);
	angle = dot_product(plane_orient, ray->dir);
	if (fabs(angle) < 0.0)
		return (0.0);
	curr->hit.t = dot_product(plane_orient,
			substract(triangle->point1, ray->origin)) / angle;
	if (curr->hit.t < 0)
		return (0.0);
	curr->hit.point = add(ray->origin, multiply(ray->dir, curr->hit.t));
	if (check_edges(curr, triangle->point1, triangle->point2, plane_orient)
		|| check_edges(curr, triangle->point2, triangle->point3, plane_orient)
		|| check_edges(curr, triangle->point3, triangle->point1, plane_orient))
		return (curr->hit.t);
	else
		return (0.0);
}
