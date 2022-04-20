/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikgarci <mikgarci@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 17:22:37 by mikgarci          #+#    #+#             */
/*   Updated: 2022/03/22 20:28:56 by mikgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algft.h"
#include <math.h>
#include <stdlib.h>

t_sphere	ft_sphere(t_tuple org, float r)
{
	t_sphere	a;

	a.r = r;
	a.transform = ft_iden_matrix(4, 4);
	a.org = ft_point(org.x, org.y, org.z);
	a.mat = ft_materials();
	return (a);
}	

t_inter	ft_intersection(float a, t_sphere s)
{
	t_inter	b;

	b.t = a;
	b.obj.s = s;
	b.obj.c = 's';
	return (b);
}

static t_arr_inter	sphere(float b, float a, float dis, t_sphere s)
{
	t_arr_inter	x;
	float	i;
	float	j;
	
	x.count = 0;
	x.a = NULL;
	if (dis < 0)
		return (x);
	i = ((-1 * b) + sqrtf(dis)) / (2 * a);
	j = ((-1 * b) - sqrtf(dis)) / (2 * a);
	x.count = 2;
	x.a = malloc(sizeof(t_inter) * 2);
	x.a[0] = ft_intersection(j, s);
	x.a[1] = ft_intersection(i, s);
	return (x);
}

t_arr_inter	ft_sphere_inter(t_ray r, t_sphere s)
{
	float	a;
	float	b;
	float	c;
	float	dis;
	t_tuple	str;
	
	
	r = ft_transform(r, ft_inver_matrix(s.transform));
	str = ft_sub_tup(r.org, s.org);
	a = ft_dot_prod(r.dir, r.dir);
	b = 2 * ft_dot_prod(r.dir, str);
	c = ft_dot_prod(str, str) - 1;
	dis = powf(b, 2.0) - (4 * a * c);
	return (sphere(b, a, dis, s));
}

t_tuple	ft_normal_at(t_sphere s, t_tuple p)
{
	t_tuple a;
	t_tuple	b;
	t_tuple c;

	a = ft_mult_matrix_tup(ft_inver_matrix(s.transform), p);
	b = ft_sub_tup(a, s.org);
	c = ft_mult_matrix_tup(ft_trans_matrix(ft_inver_matrix(s.transform)), b);
	c.w = 0;
	return (ft_norm_vec(c));
}
