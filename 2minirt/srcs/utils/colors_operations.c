/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_operations.c                                   :+:      :+:    :+: */
/*                                                    +:+ +:+         +:+     */
/*   Bg: osurcouf <.@student.42lisboa.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 17:03:10 bg osurcouf          #+#    #+#             */
/*   Updated: 2021/04/26 17:03:11 bg osurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** 🦕
**
** function : Colors operations utilities
**
** Various operations to save space in your code.
**	1. Create color (t_color to int)
**	2. Add colors
**	3. Substract colors
**	4. Multiply colors (by a float)
**	5. Divide colors (by a float)
**
** 🦕
*/

int	create_color(t_color color)
{
	return (color.r << 16 | color.g << 8 | color.b);
}

t_color	color_add(t_color c1, t_color c2)
{
	t_color	c;

	c.r = c1.r + c2.r;
	c.g = c1.g + c2.g;
	c.b = c1.b + c2.b;
	return (c);
}

t_color	color_sub(t_color c1, t_color c2)
{
	t_color	c;

	c.r = c1.r - c2.r;
	c.g = c1.g - c2.g;
	c.b = c1.b - c2.b;
	return (c);
}

t_color	color_multiply(t_color c1, float m)
{
	t_color	c;

	c.r = c1.r * m;
	c.g = c1.g * m;
	c.b = c1.b * m;
	return (c);
}

t_color	color_div(t_color c1, float d)
{
	t_color	c;

	c.r = c1.r / d;
	c.g = c1.g / d;
	c.b = c1.b / d;
	return (c);
}
