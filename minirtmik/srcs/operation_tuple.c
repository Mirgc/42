/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_tuple.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikgarci <mikgarci@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 19:50:51 by mikgarci          #+#    #+#             */
/*   Updated: 2022/03/03 17:40:04 by mikgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algft.h"

t_tuple	ft_add_tup(t_tuple a, t_tuple b)
{
	t_tuple	z;

	z.x = a.x + b.x;
	z.y = a.y + b.y;
	z.z = a.z + b.z;
	z.w = a.w + b.w;
	if (a.w == 1 && b.w == 1)
		ft_error("You can't add two points", 1);
	return (z);
}

t_tuple	ft_sub_tup(t_tuple a, t_tuple b)
{
	t_tuple	z;

	z.x = a.x - b.x;
	z.y = a.y - b.y;
	z.z = a.z - b.z;
	z.w = a.w - b.w;
	return (z);
}

t_tuple ft_neg_tup(t_tuple a)
{
	a.x *= -1;
	a.y *= -1;
	a.z *= -1;
	a.w *= -1;
	return (a);
}

t_tuple ft_mult_tup(t_tuple a, float m)
{
	a.x *= m;
	a.y *= m;
	a.z *= m;
	a.w *= m;
	return (a);
}

t_tuple ft_div_tup(t_tuple a, float d)
{
	a.x /= d;
	a.y /= d;
	a.z /= d;
	a.w /= d;
	return (a);
}
