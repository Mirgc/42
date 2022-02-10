/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <migarcia@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 18:15:04 by migarcia          #+#    #+#             */
/*   Updated: 2022/02/10 20:39:56 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/*static void     draw(t_map *map, int x, int y)
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
}*/

void    draw(t_map *map, int x, int y, int color)
{
        char    *dst;

        dst = map->image.data + (y * map->image.size + x * (map->image.bpp / 8));
        *(unsigned int*)dst = color;
}

int     get_trgb(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | (b));
}


int	map_draw(t_map *map)
{
	int	w;
	int	h;
	int	vs_x;
		int     vs_y;
	int color = 0;
	t_tup		p;
	(void)w;
	(void)h;
	(void)vs_x;
	(void)vs_y;
	(void)color;

	p = v_create(0, 0, 1, 1);
	printf("%f, %f, %f\n", p.x, p.y, p.z);
	p = m_multi_tup(m_scaling(0,0,5), p);
	printf("%f, %f, %f\n", p.x, p.y, p.z);
	//p = m_multi_tup(m_multi(m_translation(10, 5, 7), m_multi(m_scaling(5, 5, 5), m_rotationx(30))), p);
	map->mlx.img = mlx_new_image(map->mlx.init, P_WIDTH, P_HEIGHT);
	map->image.data = mlx_get_data_addr(map->mlx.img, &map->image.bpp, \
                        &map->image.size, &map->image.endian);
	color = get_trgb(255, 200, 200);
/*	p = m_multi_tup(m_multi(m_translation(10, 5, 7), m_rotationy(30)), p);
	draw(map, 450 - p.x, 225 - p.z, color);
			printf("%f, %f\n", p.x, p.y);
	p = m_multi_tup(m_multi(m_translation(10, 5, 7), m_rotationy(30)), p);
	draw(map, 450 - p.x, 225 - p.z, color);
			printf("%f, %f\n", p.x, p.y);
	p = m_multi_tup(m_multi(m_translation(10, 5, 7), m_rotationy(30)), p);
	draw(map, 450 - p.x, 225 - p.z, color);
			printf("%f, %f\n", p.x, p.y);
	p = m_multi_tup(m_multi(m_translation(10, 5, 7), m_rotationy(30)), p);
	draw(map, 450 - p.x, 225 - p.z, color);
			printf("%f, %f\n", p.x, p.y);
	p = m_multi_tup(m_multi(m_translation(10, 5, 7), m_rotationy(30)), p);
	draw(map, 450 - p.x, 225 - p.z, color);
			printf("%f, %f\n", p.x, p.y);
	p = m_multi_tup(m_multi(m_translation(10, 5, 7), m_rotationy(30)), p);
	draw(map, 450 - p.x, 225 - p.z, color);
			printf("%f, %f\n", p.x, p.y);
	p = m_multi_tup(m_multi(m_translation(10, 5, 7), m_rotationy(30)), p);
	draw(map, 450 - p.x, 225 - p.z, color);
			printf("%f, %f\n", p.x, p.y);
	p = m_multi_tup(m_multi(m_translation(10, 5, 7), m_rotationy(30)), p);
	draw(map, 450 - p.x, 225 - p.z, color);
			printf("%f, %f\n", p.x, p.y);
	p = m_multi_tup(m_multi(m_translation(10, 5, 7), m_rotationy(30)), p);
	draw(map, 450 - p.x, 225 - p.z, color);
			printf("%f, %f\n", p.x, p.y);
	p = m_multi_tup(m_multi(m_translation(10, 5, 7), m_rotationy(30)), p);
	draw(map, 450 - p.x, 225 - p.z, color);
			printf("%f, %f\n", p.x, p.y);
	p = m_multi_tup(m_multi(m_translation(10, 5, 7), m_rotationy(30)), p);
	draw(map, 450 - p.x, 225 - p.z, color);
			printf("%f, %f\n", p.x, p.y);
	p = m_multi_tup(m_multi(m_translation(10, 5, 7), m_rotationy(30)), p);
	draw(map, 450 - p.x, 225 - p.z, color);
			printf("%f, %f\n", p.x, p.y);*/
	draw(map, 450 - p.x, 225 - p.z, color);
	p = m_multi_tup(m_multi(m_translation(10, 5, 7), m_rotationy(30)), p);
	while ((int)p.x != 0)
	{
		p = m_multi_tup(m_multi(m_translation(10, 5, 7), m_rotationy(30)), p);
		draw(map, 450 - p.x, 225 - p.z, color);
	}
//	double d;
/*	h = 0;
	while (h < P_WIDTH)
	{
//                vs_y = h - P_WIDTH / 2;
		w = 0;
		while (w < P_HEIGHT)
		{
			vs_x = (h - P_WIDTH / 2) - p.x;
		        vs_y = (w - P_HEIGHT / 2) - p.y;
//                        vs_x = w - P_HEIGHT / 2;
//			if (((int)p.x == h && (int)p.z == w) || ((int)p.x == 450 - h && (int)p.z == 225 - w))	
//			{
			if (((int)p.x == (h - 450) && (int)p.z == (w - 225)))	
			//if (d > 0)
			{
				printf("%f, %i : %f, %i\n", p.x, h-450 , p.z, w-225);
				color = get_trgb(200, 200, 200);
				//draw(map, 450 - h, 225 - w);
                        	draw(map, h, w, color);
				p = m_multi_tup(m_multi(m_translation(10, 5, 7), m_rotationy(30)), p);
			}
			w++;
		}
		h++;
	}*/
	mlx_put_image_to_window(map->mlx.init, map->mlx.win, map->mlx.img, 0, 0);
	mlx_destroy_image(map->mlx.init, map->mlx.img);
	return (0);
}

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
/*
	t_map   map;

//        if (argc == 2)
	map.mlx.init = mlx_init();
	map.mlx.win = mlx_new_window(map.mlx.init, P_WIDTH, P_HEIGHT, "MINIRT");
	map_draw(&map);
//            mlx_hook(map->mlx.win, 2, 3, map_keys, map);
//            mlx_hook(map.mlx.win, 2, 3, map_draw, &map);
//	mlx_loop_hook(map.mlx.init, map_draw, &map);
	mlx_loop(map.mlx.init);

//        }
//        else
//                ft_putstr_fd("##ERROR## Usage: ./minirt <filename>\n", 1);
*/
	/*t_matrix a;
	t_matrix b;
	t_matrix c;
	t_matrix d;
//	float **tmp;

	a.m[0][0] = 3;
	a.m[0][1] = -9;
	a.m[0][2] = 7;
	a.m[0][3] = 3;
	a.m[1][0] = 3;
	a.m[1][1] = -8;
	a.m[1][2] = 2;
	a.m[1][3] = -9;
	a.m[2][0] = -4;
	a.m[2][1] = 4;
	a.m[2][2] = 4;
	a.m[2][3] = 1;
	a.m[3][0] = -6;
	a.m[3][1] = 5;
	a.m[3][2] = -1;
	a.m[3][3] = 1;
	a.rows = 4;
	a.cols = 4;

	b.m[0][0] = 8;
	b.m[0][1] = 2;
	b.m[0][2] = 2;
	b.m[0][3] = 2;
	b.m[1][0] = 3;
	b.m[1][1] = -1;
	b.m[1][2] = 7;
	b.m[1][3] = 0;
	b.m[2][0] = 7;
	b.m[2][1] = 0;
	b.m[2][2] = 5;
	b.m[2][3] = 4;
	b.m[3][0] = 6;
	b.m[3][1] = -2;
	b.m[3][2] = 0;
	b.m[3][3] = 5;
	b.rows = 4;
	b.cols = 4;*/
	t_tup	tup1;
	t_tup	tup2;
	t_tup	tup;
	t_ray	a;
	tup1 = v_create(2, 3, 4, 1);
	tup2 = v_create(1, 0, 0, 1);
	a.ori = tup1;
	a.dst = tup2;
	tup = r_position(a, 2.5);
//	tup = m_multi_tup(a, tup);
	printf("%f %f %f %d\n", tup.x, tup.y, tup.z, tup.w);
//	tmp = m_multi(a, b);
//	b = m_identity();
//	b = m_init(4, 4);
//	b = m_submatrix(a, 0, 2);
//	printf("%f\n", m_minor(b, 1, 2));
//	printf("inver:%i\n", m_invertible(b));
//	printf("%f\n", m_det(b, b.cols));
//	printf("%i, %i\n", b.cols, b.rows);
/*	c = m_multi(a, b);
	d = m_multi(c, m_invertible(b));
	t_tup	p1, p2;
	p1 = v_create(1, 0, 1, 1);
	p2 = m_multi_tup(m_multi(m_translation(10, 5, 7), m_multi(m_scaling(5, 5, 5), m_rotationx(90))), p1);
	printf("%f, %f, %f \n", p2.x, p2.y, p2.z);
	int w, h;
	w = 0;
	while (w < b.rows)
	{
                h = 0;
                while (h < b.cols)
		{
			printf("%0.5f ", a.m[w][h]);
			h++;
		}
		printf("\n");
		w++;
	}
	printf("\n");
	w = 0;
	while (w < a.rows)
	{
		h = 0;
        	while (h < a.cols)
		{
			printf("%0.5f ", d.m[w][h]);
			h++;
		}
		printf("\n");
		w++;
	}
	printf("\n");
*/
	//printf("%f\n", m_det(a, 4));
	//free_mat(tmp);
        return (0);

}
