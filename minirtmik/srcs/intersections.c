/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikgarci <mikgarci@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 23:29:02 by mikgarci          #+#    #+#             */
/*   Updated: 2022/03/25 18:16:32 by mikgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algft.h"

t_comps	ft_prep_comps(t_inter i, t_ray r)
{
	t_comps	comps;

	comps.t = i.t;
	comps.obj = i.obj;
	comps.p = ft_pos_ray(r, comps.t);
	comps.eye = ft_neg_tup(r.dir);
	if (comps.obj.c == 's')
		comps.norm = ft_normal_at(comps.obj.s, comps.p);
	if (comps.obj.c == 'p')
		comps.norm = ft_normal_at_plane(comps.obj.p, comps.p);
	if (comps.obj.c == 'c')
		comps.norm = ft_normal_at_cylinder(comps.obj.cy, comps.p);
	comps.op = ft_add_tup(comps.p, ft_mult_tup(comps.norm, EPSILON));
	if (ft_dot_prod(comps.norm, comps.eye) < 0)
	{
		comps.inside = true;
		comps.norm = ft_neg_tup(comps.norm);
	}
	else
		comps.inside = false;
	comps.reflectv = ft_reflect(r.dir, comps.norm);
	return (comps);
}
