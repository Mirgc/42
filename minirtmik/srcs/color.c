/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikgarci <mikgarci@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 17:34:31 by mikgarci          #+#    #+#             */
/*   Updated: 2022/02/23 20:07:22 by mikgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algft.h"

t_color	ft_color(float	r, float g, float b)
{
	t_color	a;

	a.r = r;
	a.g = g;
	a.b = b;
	return (a);
}

t_color	ft_add_color(t_color a, t_color b)
{
	t_color	c;

	c.r = a.r + b.r;
	c.g = a.g + b.g;
	c.b = a.b + b.b;
	return (c);
}

t_color	ft_sub_color(t_color a, t_color b)
{
	t_color	c;

	c.r = a.r - b.r;
	c.g = a.g - b.g;
	c.b = a.b - b.b;
	return (c);
}

t_color	ft_escal_color(t_color a, float b)
{
	t_color	c;

	c.r = a.r * b;
	c.g = a.g * b;
	c.b = a.b * b;
	return (c);
}

t_color	ft_mult_color(t_color a, t_color b)
{
	t_color	c;

	c.r = a.r * b.r;
	c.g = a.g * b.g;
	c.b = a.b * b.b;
	return (c);
}
