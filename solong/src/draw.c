/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 07:49:27 by migarcia          #+#    #+#             */
/*   Updated: 2021/09/27 20:16:47 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "stdio.h"

void	draw_ho(float x0, float y0, float x1, float y1, t_map *map)
{
	float dx;
	float dy;
	float p;
	float x;
	float y;

	x0 *= 20;
	y0 *= 20;
	x1 *= 20;
	y1 *= 20;
	dx = x1 - x0;
	dy = y1 - y0;
	x = x0;
	y = y0;
	p = 2 * dy - dx;
	while(x < x1 || y < y1)
	{
		mlx_pixel_put(map->mlx_ptr, map->win_ptr, x, y, 0xffffff);
		printf("%f, %f, %f, %f, %f\n", x, x1, y, y1, p);
		if(p >= 0)
		{
			y++; 
			p += 2 * dy - 2 * dx;
		}
		else
			p += 2 * dy;
		x++;
	}
}

void    draw_ver(float x0, float y0, float x1, float y1, t_map *map)
{
    float dx;
    float dy;
    float p;
    float x;
    float y;

    x0 *= 20;
    y0 *= 20;
    x1 *= 20;
    y1 *= 20;
    dx = x1 - x0;
    dy = y1 - y0;
    x = x0;
    y = y0;
    p = 2 * dy - dx;
    while(y < y1)
    {
        mlx_pixel_put(map->mlx_ptr, map->win_ptr, x, y, 0xffffff);
        printf("%f, %f, %f, %f, %f\n", x, x1, y, y1, p);
        if(p >= 0)
        {
            y++;
            p += 2 * dy - 2 * dx;
        }
        else
            p += 2 * dy;
    }
}

void	draw_map(t_map *map)
{
	int x;
	int y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			draw_ho(x, y, x + 1, y, map);
			draw_ver(x, y, x, y + 1, map);
			x++;
		}
		y++;
	}
}
