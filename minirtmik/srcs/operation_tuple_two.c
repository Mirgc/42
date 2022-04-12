/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_tuple_two.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikgarci <mikgarci@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 19:30:44 by mikgarci          #+#    #+#             */
/*   Updated: 2022/03/25 19:18:04 by mikgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "algft.h"

float ft_mag_vec(t_tuple v)
{
	float	m;

	m = sqrtf(powf(v.x, 2.0) + powf(v.y, 2.0) + powf(v.z, 2.0));
	return (m);
}

t_tuple ft_norm_vec(t_tuple v)
{
	float m;

	m = ft_mag_vec(v);
	return (ft_div_tup(v, m));
}

float	ft_dot_prod(t_tuple a, t_tuple b)
{
	return ((a.x * b.x) + (a.y * b.y) + (a.z * b.z));
}

t_tuple	ft_cross_prod(t_tuple a, t_tuple b)
{
	t_tuple z;

	z.x = (a.y * b.z) - (a.z * b.y);
	z.y = (a.z * b.x) - (a.x * b.z);
	z.z = (a.x * b.y) - (a.y * b.x);
	z.w = 0;
	return (z);
}

t_tuple	ft_reflect(t_tuple in, t_tuple nor)
{
	t_tuple	a;
	float	i;

	i = ft_dot_prod(in, nor);
	a = ft_mult_tup(nor, 2.0);
	return (ft_sub_tup(in, ft_mult_tup(a, i)));
}
