/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <migarcia@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 18:12:48 by migarcia          #+#    #+#             */
/*   Updated: 2021/10/23 10:15:19 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include "../mlx/mlx.h"

void	print_menu(t_map *map)
{
	int		y;
	void	*mlx;
	void	*win;

	y = 0;
	mlx = map->mlx.init;
	win = map->mlx.win;
	mlx_string_put(mlx, win, 1115, y += 20, TEXT_COLOR, "How to Use");
	mlx_string_put(mlx, win, 1095, y += 30, TEXT_COLOR, "Zoom:        q/a");
	mlx_string_put(mlx, win, 1095, y += 30, TEXT_COLOR, "Profundity:  w/s");
	mlx_string_put(mlx, win, 1095, y += 30, TEXT_COLOR, "Rotate:      e/d");
	mlx_string_put(mlx, win, 1095, y += 30, TEXT_COLOR, "Move:        Arrows");
}

void	rotate_x(t_map *map)
{
	static int	i;
	static int	j;

	if (i <= 50 && j == 0)
	{
		map->angle_x -= 0.02;
		i++;
		if (i == 50)
			j = 1;
	}
	else
	{
		map->angle_x += 0.02;
		j++;
		if (j == 51)
		{
			j = 0;
			i = 0;
		}
	}
}

void	rotate_y(t_map *map)
{
	static int	i;
	static int	j;

	if (i <= 25 && j == 0)
	{
		map->angle_y -= 0.02;
		i++;
		if (i == 50)
			j = 1;
	}
	else
	{
		map->angle_y += 0.02;
		j++;
		if (j == 26)
		{
			j = 0;
			i = 0;
		}
	}
}
