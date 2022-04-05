/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikgarci <mikgarci@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 17:39:54 by mikgarci          #+#    #+#             */
/*   Updated: 2022/03/25 19:55:57 by mikgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algft.h"
#include <math.h>
#include <stdlib.h>

typedef struct s_bi {
	float	a;
	float	b;
	float	c;
	float	disc;
}	t_bi;

t_cylinder	ft_cylinder(void)
{
	t_cylinder	c;

	c.min = 1.0;
	c.max = 2.0;
	c.transform = ft_iden_matrix(4, 4);
	c.org = ft_point(0, 0, 0);
	c.r = 1.0;
	c.mat = ft_materials();
	c.closed = true;
	return (c);
}

t_inter	ft_intersection_cylinder(float a, t_cylinder c)
{
	t_inter	b;

	b.t = a;
	b.obj.cy = c;
	b.obj.c = 'c';
	return (b);
}

static	bool	check_cap(t_ray r, float t)
{
	float	x;
	float	z;

	x = r.org.x + (t * r.dir.x);
	z = r.org.z + (t * r.dir.z);
	if ((powf(x, 2.0) + powf(z, 2.0)) <= 1)
		return (true);
	return (false);
}

static t_arr_inter	intersect_caps(t_cylinder cy, t_ray r, t_arr_inter x)
{
	float	t;

	if (!cy.closed || fabs(r.dir.y) < EPSILON)
		return (x);
	t = (cy.min - r.org.y) / r.dir.y;
	if (check_cap(r, t))
	{
		x.a[x.count] = ft_intersection_cylinder(t, cy);
		x.count++;
	}
	t = (cy.max - r.org.y) / r.dir.y;
	if (check_cap(r, t))
	{
		x.a[x.count] = ft_intersection_cylinder(t, cy);
		x.count++;
	}
	return (x);
}

static t_arr_inter	cylinder(t_bi w, t_cylinder cy, t_arr_inter x, t_ray r)
{
	float	i;
	float	j;
	float	ii;
	float	jj;
	
	(void) r;
	i = ((-1 * w.b) + sqrtf(w.disc)) / (2 * w.a);
	ii = r.org.y + (i * r.dir.y);
	if (cy.min < ii && ii < cy.max)
	{
		x.a[x.count] = ft_intersection_cylinder(i, cy);
		x.count++;
	}
	j = ((-1 * w.b) - sqrtf(w.disc)) / (2 * w.a);
	jj = r.org.y + (j * r.dir.y);
	if (cy.min < jj && jj < cy.max)
	{
		x.a[x.count] = ft_intersection_cylinder(j, cy);
		x.count++;
	}
	x = intersect_caps(cy, r, x);
	if (!x.count)
		free(x.a);
	return (x);
}

//Deberia estar la intersect_caps despues, pero no funciona sino//
t_arr_inter	ft_cylinder_inter(t_ray r, t_cylinder cy)
{
	t_bi		w;
	t_arr_inter	x;
	
	r = ft_transform(r, ft_inver_matrix(cy.transform));
	w.a = (powf(r.dir.x, 2.0)) + (powf(r.dir.z, 2.0));
	w.b = (2 * r.org.x * r.dir.x) + (2 * r.org.z * r.dir.z);
	w.c = powf(r.org.x, 2.0) + powf(r.org.z, 2.0) - 1;
	w.disc = powf(w.b, 2.0) - (4.0 * w.a * w.c);
	x.count = 0;
	x.a = NULL;
	x.a = malloc(sizeof(t_inter) * 2);
	if (w.disc < 0 || fabs(w.a) < EPSILON)
	{
		x = intersect_caps(cy, r, x);
		if (!x.count)
			free(x.a);
		return (x);
	}
	return (cylinder(w, cy, x, r));
}

t_tuple	ft_normal_at_cylinder(t_cylinder c, t_tuple p)
{
	(void) c;
	(void) p;
	float	dist;

	dist = powf(p.x, 2.0) + powf(p.z, 2.0);
	if (dist < 1 && (p.y >= (c.max - EPSILON)))
		return (ft_vector(0, 1, 0));
	if (dist < 1 && (p.y <= (c.min + EPSILON)))
		return (ft_vector(0, -1, 0));
	return (ft_vector(p.x, 0, p.z));
}
