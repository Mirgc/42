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
			draw(map, h, 550 - w);
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

/*	t_map   map;

//        if (argc == 2)
	map.mlx.init = mlx_init();
	map.mlx.win = mlx_new_window(map.mlx.init, P_WIDTH, P_HEIGHT, "MINIRT");
//            mlx_hook(map->mlx.win, 2, 3, map_keys, map);
	mlx_loop_hook(map.mlx.init, map_draw, &map);
	mlx_loop(map.mlx.init);

//        }
//        else
//                ft_putstr_fd("##ERROR## Usage: ./minirt <filename>\n", 1);
*/
	t_matrix a;
//	t_matrix b;
//	float **tmp;

	a.m[0][0] = 1;
	a.m[0][1] = 7;
	a.m[0][2] = 14;
	a.m[0][3] = 0;
	a.m[1][0] = 9;
	a.m[1][1] = 4;
	a.m[1][2] = 18;
	a.m[1][3] = 18;
	a.m[2][0] = 2;
	a.m[2][1] = 4;
	a.m[2][2] = 5;
	a.m[2][3] = 5;
	a.m[3][0] = 1;
	a.m[3][1] = 7;
	a.m[3][2] = 1;
	a.m[3][3] = 11;

/*	b.m[0][0] = -2;
	b.m[0][1] = 1;
	b.m[0][2] = 2;
	b.m[0][3] = 3;
	b.m[1][0] = 3;
	b.m[1][1] = 2;
	b.m[1][2] = 1;
	b.m[1][3] = -1;
	b.m[2][0] = 4;
	b.m[2][1] = 3;
	b.m[2][2] = 6;
	b.m[2][3] = 5;
	b.m[3][0] = 1;
	b.m[3][1] = 2;
	b.m[3][2] = 7;
	b.m[3][3] = 8;
*/
//	t_tup tup;
//	tup = v_create(1, 2, 3, 1);
//	tup = m_multi_tup(a, tup);
//	printf("%f %f %f %d\n", tup.x, tup.y, tup.z, tup.w);
//	tmp = m_multi(a, b);
//	b = m_identity();
/*	int w, h;
	w = 0;
        while (w < 4)
        {
                h = 0;
                while (h < 4)
		{
			printf("%f ", a.m[w][h]);
			h++;
		}
		printf("\n");
		w++;
	}
	printf("\n");*/
	printf("%f\n", m_det(a, 4));
	//free_mat(tmp);
        return (0);

}
