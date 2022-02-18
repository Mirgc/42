/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <migarcia@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 18:15:04 by migarcia          #+#    #+#             */
/*   Updated: 2022/02/17 20:45:04 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "tuples.h"
#include "matrix.h"
#include "ray.h"
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
	int	vs_y;
	float	world_x;
	float	world_y;
	int color = 0;
	float wall_z;
	float wall_size;
	float canvas_pixel;
	float pixel_size;
	float half;
	t_tup	p;
	t_ray	ray;
	t_sphere	sp;
	t_arr_inter		inter;
	(void)w;
	(void)h;
	(void)vs_x;
	(void)vs_y;
	(void)color;

	sp = r_create_sphere();
	ray.ori = v_create(0, 0, -5, 1);
	wall_z = 10;
	canvas_pixel = 100;
	wall_size = 7;
	pixel_size = wall_size / canvas_pixel;
	half = wall_size / 2;
	color = get_trgb(255, 0, 0);

	map->mlx.img = mlx_new_image(map->mlx.init, P_WIDTH, P_HEIGHT);
	map->image.data = mlx_get_data_addr(map->mlx.img, &map->image.bpp, &map->image.size, &map->image.endian);

	vs_y = 0;
	while (vs_y < canvas_pixel -1)
	{
		world_y = half - (pixel_size * vs_y);
		vs_x = 0;
		while (vs_x < canvas_pixel -1)
		{
			world_x = -half + (pixel_size * vs_x);
			p = v_create(world_x, world_y, wall_z, 1);
			ray.dir = v_normalize(v_substract(p, ray.ori));
			inter = r_intersect(sp, ray);
			if (r_hit(inter))
				draw(map, 50 - vs_x, 50 - vs_y, color);
			vs_x++;
		}
		vs_y++;
	}

//	color = get_trgb(255, 0, 0);
//	draw(map, 450 - p.x, 225 - p.z, color);
//	p = m_multi_tup(m_multi(m_translation(10, 5, 7), m_rotationy(30)), p);
//	while ((int)p.x != 0)
//	{
//		p = m_multi_tup(m_multi(m_translation(10, 5, 7), m_rotationy(30)), p);
//		draw(map, 450 - p.x, 225 - p.z, color);
//	}
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
	b.cols = 4;
	t_arr_inter arr;
	(void)arr;
	t_ray ray;
//	t_matrix m;
	ray.ori = v_create(0,0,-5,1);
	ray.dir = v_create(0,0,1,0);
//	t_ray ray2;
//	ray2 = r_transform(ray, m);
	t_sphere s;
	s = r_create_sphere();
	s.transform = m_translation(5, 0, 0);
//	set_transform(&s, m);
	arr = r_intersect(s, ray);
//	tup = m_multi_tup(a, tup);
//	printf("%f, %f, %f,\n",ray2.dir.x, ray2.dir.y, ray2.dir.z);
//	printf("%f, %f, %f,\n",ray2.ori.x, ray2.ori.y, ray2.ori.z);
//	tmp = m_multi(a, b);
//	b = m_identity();
//	b = m_init(4, 4);
//	b = m_submatrix(a, 0, 2);
//	printf("%f\n", m_minor(b, 1, 2));
//	printf("inver:%i\n", m_invertible(b));
//	printf("%f\n", m_det(b, b.cols));
//	printf("%i, %i\n", b.cols, b.rows);
	c = m_multi(a, b);
	d = m_multi(c, m_invertible(b));
	t_tup	p1, p2;
	p1 = v_create(1, 0, 1, 1);
	p2 = m_multi_tup(m_multi(m_translation(10, 5, 7), m_multi(m_scaling(5, 5, 5), m_rotationx(90))), p1);

	//printf("%f\n", m_det(a, 4));
	//free_mat(tmp);*/
        return (0);

}
