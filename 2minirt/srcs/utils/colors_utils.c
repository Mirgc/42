/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_utils.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osurcouf <.@student.42lisboa.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 01:30:19 by osurcouf          #+#    #+#             */
/*   Updated: 2021/06/09 01:30:21 by osurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** 🦕
**
** function : Color additionnal utilities
**
** Various operations to save space in your code.
**	1. Set color (r, g, b to t_color)
**	2. Convert to max
**		to cover when the light brightness calculations
**		get your light color over 255 - thus resulting
**		in very weird results looking like zebras and
**		other distorsions. Or just black.
**
** 🦕
*/

t_color	set(int r, int g, int b)
{
	t_color	c;

	c.r = r;
	c.g = g;
	c.b = b;
	c.t = 0;
	return (c);
}

t_color	convert_to_max(t_color color)
{
	if (color.r > 255)
		color.r = 255;
	if (color.g > 255)
		color.g = 255;
	if (color.b > 255)
		color.b = 255;
	color.t = 0;
	return (color);
}
