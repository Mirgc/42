/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikgarci <mikgarci@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 20:48:46 by mikgarci          #+#    #+#             */
/*   Updated: 2022/03/25 20:17:42 by mikgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algft.h"
#include <math.h>
#include <stdio.h>

t_camera	ft_camera(int hsize, int vsize, float fov)
{
	t_camera	a;
	float		hv;
	float		asp;

	a.hsize = hsize;
	a.vsize = vsize;
	a.fov = fov;
	a.trans = ft_iden_matrix(4, 4);
	hv = tanf(fov / 2);
	asp = (float) hsize / (float)vsize;
	if (asp >= 1)
	{
		a.hw = hv;
		a.hh = hv / asp;
	}
	else
	{
		a.hw = hv * asp;
		a.hh = hv;
	}
	a.ps = (a.hw * 2) / (float) a.hsize;
	return (a);
}

t_ray	ft_ray_for_pixel(t_camera c, float px, float py)
{
	float	xo;
	float	yo;
	t_tuple	p;
	t_tuple	o;
	t_tuple	d;

	xo = (px + 0.5) * c.ps;
	yo = (py + 0.5) * c.ps;
	p = ft_mult_matrix_tup(ft_inver_matrix(c.trans), ft_point(c.hw - xo, c.hh - yo, -1));
	o = ft_mult_matrix_tup(ft_inver_matrix(c.trans), ft_point(0, 0, 0));
	d = ft_norm_vec(ft_sub_tup(p, o));
	return (ft_ray(o, d));
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst =color;
}

void	ft_scale(int	x, int y, t_generic *g, t_color c)
{
	int	a;
	int	b;
	int value;

	value = 0;
	if (c.r > 1)
		value = value + 255 * 256 * 256;
	else if (c.r > 0)
		value = value + ((int)(c.r * 255)) * 256 * 256;
	if (c.g > 1)
		value = value + 255 * 256;
	else if (c.g > 0)
		value = value + ((int)(c.g * 255)) * 256;
	if (c.b > 1)
		value = value + 255;
	else if (c.b > 0)
		value = value + ((int)(c.b * 255));

	a = x;
	b = y;
	my_mlx_pixel_put(&g->img, a, b, value);
}

void	ft_render(t_scene s)
{
	int		y;
	int		x;
	t_ray	r;
	t_color	col;

	y = 0;
	while (y < s.cam.vsize - 1)
	{
		x = 0;
		while (x < s.cam.hsize - 1)
		{
			r = ft_ray_for_pixel(s.cam, x, y);
			col = ft_color_at(s.world, r, 4);
		//	ft_print_color(col);
			col = ft_mult_color(col, s.amb.color);
			ft_scale(x, y, &s.g, col);
			x++;
		}
		y++;
	}
}
