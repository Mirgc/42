/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 17:45:47 by migarcia          #+#    #+#             */
/*   Updated: 2021/10/23 10:04:47 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include "../libft/libft.h"
#include "../mlx/mlx.h"
#include <math.h>

void	ft_error(char *str)
{
	ft_putstr_fd(str, 2);
	exit(0);
}

int	map_keys(int keycode, t_map *map)
{
	if (keycode == 53)
		exit(0);
	else if (keycode == 126)
		map->coord_y -= 2;
	else if (keycode == 125)
		map->coord_y += 2;
	else if (keycode == 123)
		map->coord_x -= 3;
	else if (keycode == 124)
		map->coord_x += 3;
	else if (keycode == 15)
		nomalize_map(map);
	else if (keycode == 12)
		map->zoom += 1;
	else if (keycode == 0)
		map->zoom -= 1;
	else if (keycode == 13)
		map->z_value += 0.25;
	else if (keycode == 1)
		map->z_value -= 0.25;
	else if (keycode == 14)
		rotate_x(map);
	else if (keycode == 2)
		rotate_y(map);
	return (0);
}

void	nomalize_map(t_map *map)
{
	map->coord_x = 0;
	map->coord_y = 0;
	map->z_value = 1.00;
	map->angle_x = cos(M_PI / 3);
	map->angle_y = map->angle_x * sin(M_PI / 6);
	if (map->width > map->height)
		map->zoom = (P_WIDTH / map->width) + 2;
	else
		map->zoom = (P_HEIGHT / map->height) + 2;
	map->isometric = 1;
	map->color.t = 0x00000000;
	map->color.r = 0x00000000;
	map->color.g = 0x00000000;
	map->color.b = 0x0000006F;
}

int	main(int argc, char **argv)
{
	t_map	*map;

	if (argc == 2)
	{
		map = (t_map *)malloc(sizeof(t_map));
		if (!map)
			ft_error("##ERROR## Memory Allocation failed!\n");
		map_read(argv[1], map);
		nomalize_map(map);
		map->mlx.init = mlx_init();
		map->mlx.win = mlx_new_window(map->mlx.init, P_MENU, P_HEIGHT, "FDF");
		mlx_hook(map->mlx.win, 2, 3, map_keys, map);
		mlx_loop_hook(map->mlx.init, map_draw, map);
		print_menu(map);
		mlx_loop(map->mlx.init);
	}
	else
		ft_putstr_fd("##ERROR## Usage: ./map <filename>\n", 1);
	return (0);
}
