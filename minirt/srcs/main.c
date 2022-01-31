/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <migarcia@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 18:15:04 by migarcia          #+#    #+#             */
/*   Updated: 2022/01/31 21:08:46 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

static void     draw(t_map *map, int x, int y)
{
        int             point;

        if ((x > 0 && y > 0) && (x < P_WIDTH && y < P_HEIGHT))
        {
                point = (x * 4) + (y * P_WIDTH * 4);
                map->image.data[point] = 0xFF;
                map->image.data[point + 1] = 0xFF;
                map->image.data[point + 2] = 0xFF;
                map->image.data[point + 3] = 0xFF;
        }
}

int	map_draw(t_map *map)
{
	int	w;
	int	h;

	map->mlx.img = mlx_new_image(map->mlx.init, P_WIDTH, P_HEIGHT);
	map->image.data = mlx_get_data_addr(map->mlx.img, &map->image.bpp, \
                        &map->image.size, &map->image.endian);
	h = 0;
	while (h < P_WIDTH)
	{
		w = 0;
		while (w < P_HEIGHT)
		{
			if (w == (int)p.pos.y && h == (int)p.pos.x )
			{
				p = tick(e, p);
				draw(map, h, 550 - w);
			}
			w++;
		}
		h++;
	}
	mlx_put_image_to_window(map->mlx.init, map->mlx.win, map->mlx.img, 0, 0);
	mlx_destroy_image(map->mlx.init, map->mlx.img);
	return (0);
}

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;

	t_map   map;

//        if (argc == 2)
	map.mlx.init = mlx_init();
	map.mlx.win = mlx_new_window(map.mlx.init, P_WIDTH, P_HEIGHT, "MINIRT");
//            mlx_hook(map->mlx.win, 2, 3, map_keys, map);
	mlx_loop_hook(map.mlx.init, map_draw, &map);
	mlx_loop(map.mlx.init);

//        }
//        else
//                ft_putstr_fd("##ERROR## Usage: ./minirt <filename>\n", 1);
        return (0);

}
