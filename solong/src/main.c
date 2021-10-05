/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 14:44:05 by migarcia          #+#    #+#             */
/*   Updated: 2021/09/27 20:16:50 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>
#include <stdio.h>

int	deal_key(int key, t_map *map)
{
	(void)map;
	printf("%i\n", key);
//	if (key == KEY_ESCAPE)
//        exit(0);
	return(0);
}

void    nomalize_map(t_map *map)
{
    map->coord_x = 0;
    map->coord_y = 0;
    map->z_value = 2.00;
    map->angle_x = cos(M_PI / 3);
    map->angle_y = map->angle_x * sin(M_PI / 6);
    map->scalin = ceil((map->width > map->height)) \
        ? (P_WIDTH / map->width) + MAGNIFY \
        : (P_HEIGHT / map->height) + MAGNIFY;
    map->isometric = 1;
    map->color.r = 0x4F;
    map->color.g = 0x4F;
    map->color.b = 0x4F;
}


int	main(int argc, char **argv)
{
	t_map *map;

	if (argc != 2)
	{
		ft_putstr_fd("##ERROR## Usage: ./map <filename>\n", 1);
		return (0);
	}
	map = malloc(sizeof(map));
	if (!map)
		return (0);
	if (read_map(argv[1], map) == 1)
	{
		free(map);
		return(0);
	}
	map->mlx.init = mlx_init();
	map->mlx.win = mlx_new_window(map->mlx.init, 1080, 720, "FDF");
	nomalize_map(map);
	draw_map(map);
	mlx_hook(map->mlx.win, 2, 3, deal_key, map);
	mlx_loop(map->mlx.init);
	system("leaks map");
}
