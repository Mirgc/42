/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuples.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <migarcia@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 16:01:00 by migarcia          #+#    #+#             */
/*   Updated: 2022/02/11 18:16:09 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuples.h"
#include <unistd.h>
#include <math.h>

t_tup	v_create(double x, double y, double z, int w)
{
	t_tup	tuple;

	tuple.x = x;
	tuple.y = y;
	tuple.z = z;
	tuple.w = w;

	return (tuple);
}

t_tup 	v_add(t_tup a, t_tup b)
{
	t_tup	tmp;
	
	tmp.x = a.x + b.x;
	tmp.y = a.y + b.y;
	tmp.z = a.z + b.z;
	tmp.w = a.w + b.w;
	return (tmp);
}

t_tup	v_substract(t_tup a, t_tup b)
{
	t_tup	tmp;

	tmp.x = a.x - b.x;
	tmp.y = a.y - b.y;
	tmp.z = a.z - b.z;
	tmp.w = a.w - b.w;
	return (tmp);
}

t_tup	v_negate(t_tup a)
{
	t_tup	tmp;

	tmp.x = 0 - a.x;
	tmp.y = 0 - a.y;
	tmp.z = 0 - a.z;
	tmp.w = 0 - a.w;

	return (tmp);
}

t_tup	v_multi(t_tup a, double nb)
{
	t_tup	tmp;

	tmp.x = a.x * nb;
	tmp.y = a.y * nb;
	tmp.z = a.z * nb;
	tmp.w = a.w * nb;

	return (tmp);
}

double	v_magnitude(t_tup vec)
{
    double res;
	
	res = sqrt(pow(vec.x,2) + pow(vec.y,2) + pow(vec.z,2));
    return (res);
}

t_tup	v_normalize(t_tup a)
{
	t_tup	tmp;
	double	mag;

	mag = v_magnitude(a);
	tmp.x = a.x / mag;
	tmp.y = a.y / mag;
	tmp.z = a.z / mag;
	tmp.w = a.w / mag;
	return (tmp);
}

double	v_dot(t_tup	a, t_tup b)
{
	return((a.x * b.x) + (a.y * b.y) + (a.z * b.z));
}

t_tup	v_cross(t_tup a, t_tup b)
{
	t_tup	tmp;

	tmp.x = a.y * b.z - a.z * b.y;
	tmp.y = a.z * b.x - a.x * b.z;
	tmp.z = a.x * b.y - a.y * b.x;
	tmp.w = 0;
	return (tmp);
}

t_proj	tick(t_env env, t_proj proj)
{
	t_proj	tmp;

	tmp.pos = v_add(proj.pos, proj.vel);
	tmp.vel = v_add(v_add(proj.vel, env.grav), env.wind);
	return (tmp);
}

int equal(float a, float b)
{
	if ((a - b) < 0.00001)
		return (1);
	return (0);
}
