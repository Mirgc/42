/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikgarci <mikgarci@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 17:08:22 by mikgarci          #+#    #+#             */
/*   Updated: 2022/03/25 20:02:12 by mikgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algft.h"
#include <float.h>

t_ray	ft_ray(t_tuple a, t_tuple b)
{
	t_ray	c;

	c.org = ft_point(a.x, a.y, a.z);
	c.dir = ft_vector(b.x, b.y, b.z);
	return (c);
}

t_tuple	ft_pos_ray(t_ray a, float t)
{
	t_tuple	c;

	c = ft_mult_tup(a.dir, t);
	return(ft_add_tup(c, a.org));
}

float	ft_hit(t_arr_inter x)
{
	int		i;
	float	c;

	if (!x.count)
		return (0);
	i = 0;
	c =	FLT_MAX;
	while (i < x.count)
	{
		if (x.a[i].t < c && x.a[i].t >= 0)
			c = x.a[i].t;
		i++;
	}
	if (c == FLT_MAX)
		return (0);
	return (c);
}

t_ray	ft_transform(t_ray r, t_matrix m)
{
	t_ray p;

	p.org = ft_mult_matrix_tup(m, r.org);
	p.dir = ft_mult_matrix_tup(m, r.dir);
	return (p);	
}
