/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikgarci <mikgarci@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 01:11:38 by mikgarci          #+#    #+#             */
/*   Updated: 2022/03/25 18:32:00 by mikgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algft.h"
#include <stdio.h>

t_color	ft_color_at(t_world w, t_ray r, int rem)
{
	t_arr_inter	x;
	float		hit;
	t_comps		comps;
	t_color		col;
	int		pos;

	x = ft_inter_world(w, r);
	hit = ft_hit(x);
	if (!hit)
		return (ft_color(0, 0, 0));
	comps = ft_prep_comps(x.a[0], r);
	pos = -1;
	while (++pos < x.count)
	{
		if (hit == x.a[pos].t)
			break;
	}
	comps = ft_prep_comps(x.a[pos], r);
	col = ft_shade_hit(w, comps, rem);
	return (col);
}
