/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <migarcia@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 18:15:04 by migarcia          #+#    #+#             */
/*   Updated: 2022/02/22 16:17:14 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "tuples.h"
#include "matrix.h"
#include "ray.h"
#include "canvas.h"
#include "light.h"
#include "world.h"
#include "camera.h"
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

t_color	check_color(t_color col)
{
	t_color tmp;

	tmp = col;
	if (col.r > 1)
		tmp.r = 1;
	if (col.g > 1)
		tmp.g = 1;
	if (col.b > 1)
		tmp.b = 1;
	return (tmp);
}

void    render(t_map *map, t_world world)
{
        int     x;
        int     y;
        t_ray   ray;
        t_color c_col;
	int	color;

        y = -1;
        while (++y < map->cam.vsize -1)
        {
                x = -1;
                while (++x < map->cam.hsize -1)
                {
                        ray = ray_for_pixel(map->cam, x, y);
                        c_col = color_at(world, ray);
			c_col = check_color(c_col);
			c_col = multicolor(c_col, 255);
			color = get_trgb(c_col.r, c_col.g, c_col.b);
			draw(map, x, y, color);
                }
        }
}


int	map_draw(t_map *map)
{
	
	t_world world;
	t_ray ray;

	world = default_world(4);
	world.sh[0].pl.transform = m_scaling(10, 0.01, 10);
        world.sh[0].pl.material.color = set_color(1, 0.9, 0.9);
        world.sh[0].pl.material.specular = 0;

//	world.sh[1].sp.transform = m_multi(m_multi(m_translation(0, 0, 5), m_rotationy(-M_PI_2 / 2)), m_multi(m_rotationx(M_PI_2), m_scaling(10, 0.01, 10)));
//      world.sh[1].sp.material = world.sh[0].sp.material;

//	world.sh[2].sp.transform = m_multi(m_multi(m_translation(0, 0, 5), m_rotationy(M_PI_2 / 2)), m_multi(m_rotationx(M_PI_2), m_scaling(10, 0.01, 10)));
//      world.sh[2].sp.material = world.sh[0].sp.material;

	world.sh[1].sp.transform = m_translation(-0.5, 1.0, 0.5);
	world.sh[1].sp.material.color = set_color(0.1, 1.0, 0.5);
	world.sh[1].sp.material.diffuse = 0.7;
        world.sh[1].sp.material.specular = 0.3;

	world.sh[2].sp.transform = m_multi(m_translation(1.5, 0.5, -0.5), m_scaling(0.5, 0.5, 0.5));
        world.sh[2].sp.material.color = set_color(0.5, 1, 0.1);
        world.sh[4].sp.material.diffuse = 0.7;
        world.sh[2].sp.material.specular = 0.3;

	world.sh[3].sp.transform = m_multi(m_translation(-1.5, 0.33, -0.75), m_scaling(0.33, 0.33, 0.33));
        world.sh[3].sp.material.color = set_color(1, 0.8, 0.1);
        world.sh[3].sp.material.diffuse = 0.7;
        world.sh[3].sp.material.specular = 0.3;

	map->cam = set_camera(P_WIDTH, P_HEIGHT, M_PI/3);
        map->cam.transform = view_transform(v_create(0, 1.5, -5, 1), v_create(0, 1, 0, 1), v_create(0, 1, 0, 0));
	map->mlx.img = mlx_new_image(map->mlx.init, P_WIDTH, P_HEIGHT);
	map->image.data = mlx_get_data_addr(map->mlx.img, &map->image.bpp, &map->image.size, &map->image.endian);
	render(map, world);
	/*int	w;
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
	float hit;
	t_tup	p;
	t_tup	point;
	t_tup	normal;
	t_ray	ray;
	t_world world;
	t_sphere	sp;
	t_arr_inter		inter;
	t_light	li;
	t_color c_col;
	(void)w;
	(void)h;
	(void)vs_x;
	(void)vs_y;
	(void)color;

	world = default_world(1);
	world.sp[0] = r_create_sphere();
	ray.ori = v_create(0, 0, -5, 1);
	wall_z = 10;
	canvas_pixel = 100;
	wall_size = 7;
	pixel_size = wall_size / canvas_pixel;
	half = wall_size / 2;

	world.sp[0].material.color = set_color(1, 1, 0.5);
	li = l_point_light(v_create(-10, 10, -10, 1), set_color(1, 1, 1));
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
			inter = r_intersect_world(world, ray);
			hit = r_hit(inter);
			if (hit != -1)
			{
				point = r_position(ray, hit);
				normal = r_normal_at(world.sp[0], point);
				c_col = lighting(world.sp[0].material, world.li, point, v_negate(ray.dir), normal);
				c_col = check_color(c_col);
				c_col = multicolor(c_col, 255);
				color = get_trgb(c_col.r, c_col.g, c_col.b);
				draw(map, vs_x, vs_y, color);
			}
			vs_x++;
		}
		vs_y++;
	}*/


/*	sp = r_create_sphere();
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
			if (r_hit(inter) != -1)
			{
				draw(map, vs_x, vs_y, color);
			}
			vs_x++;
		}
		vs_y++;
	}*/

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
//	mlx_destroy_image(map->mlx.init, map->mlx.img);
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
	b.cols = 4;*/
/*	t_arr_inter	arr;
	t_world		wo;
	wo = default_world(2);
	wo.sp[0].material.color = set_color(0.8, 1.0, 0.6);
	wo.sp[0].material.diffuse = 0.7;
	wo.sp[0].material.specular = 0.2;
	wo.sp[1].transform = m_scaling(0.5, 0.5, 0.5);
	(void)arr;
	t_ray ray;
//	t_matrix m;
	ray.ori = v_create(0,0,-5,1);
	ray.dir = v_create(0,0,1,0);

	r_intersect(&wo, wo.sp[0], ray);*/
	//arr = r_intersect_world(wo, ray);
//	t_ray ray2;
//	ray2 = r_transform(ray, m);
//	t_tup p;
//	t_tup t;
//	t_tup r;
	//////////////////////////////////////
//	t_color	color;
//	t_material m;
//	t_light li;
//	m = m_create_material();
//	m.color = set_color(1, 0.2, 1);

	/////////////////////////////////////
//	color = lighting(m, li, v_create(0, 0, 0, 1), v_create(0, 0, -1, 0), v_create(0, 0, -1, 0));
//	printf("color:%f, %f, %f\n", color.r, color.b, color.g);
//	p = v_create(0, -1, 0, 0);
//	t = v_create(0.70710678118, 0.70710678118, 0, 0);
//	r = r_reflect(p, t);
//	print_tuple(r);
	
//	s.transform = m_translation(5, 0, 0);
//	set_transform(&s, m);
//	arr = r_intersect(s, ray);
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
//	c = m_multi(a, b);
//	d = m_multi(c, m_invertible(b));
//	t_tup	p1, p2;
//	p1 = v_create(1, 0, 1, 1);
//	p2 = m_multi_tup(m_multi(m_translation(10, 5, 7), m_multi(m_scaling(5, 5, 5), m_rotationx(90))), p1);

	//printf("%f\n", m_det(a, 4));
	//free_mat(tmp);
        return (0);

}
