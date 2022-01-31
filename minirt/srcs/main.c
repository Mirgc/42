/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <migarcia@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 18:15:04 by migarcia          #+#    #+#             */
/*   Updated: 2022/01/29 12:36:52 by migarcia         ###   ########.fr       */
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
	t_proj	p;
	t_env	e;

	p.pos = v_create(0, 1, 0, 0);
	p.vel = v_multi(v_normalize(v_create(1, 1.8, 0, 1)), 11.25);
	e.grav = v_create(0, -0.1, 0, 1);
	e.wind = v_create(-0.01, 0, 0, 1);

	map->mlx.img = mlx_new_image(map->mlx.init, P_WIDTH, P_HEIGHT);
        map->image.data = mlx_get_data_addr(map->mlx.img, &map->image.bpp, \
                        &map->image.size, &map->image.endian);
//	while(p.pos.y > 0)
//	{
//		p = tick(e, p);
//		printf("pos.x: %f, pos.y: %f, pos.z: %f\n", p.pos.x, p.pos.y, p.pos.z);
//	}
        h = 0;
        while (h < P_WIDTH)
        {
                w = 0;
                while (w < P_HEIGHT)
                {
			if (w == (int)p.pos.y && h == (int)p.pos.x )
			{
				p = tick(e, p);
//                        	map->image.data[h * P_WIDTH + w] = 0xFF;
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

/*void makeppm(char *ppm, int wd, int ht){
   FILE *fd;
   fd = fopen("a.ppm", "w");

   //print the ppm file header
   fprintf(fd, "P6 %d %d %d\n",  wd, ht, 255);

   // from data ppm[] holds, 3 (size of pixel element),
   //size of ppm[], to fp (the file pointer) 
   fwrite(ppm, 3, wd*ht, fd);

   //close the file
   fclose(fd);
 }


int	map_draw(t_map *map)
{
	//char *file = "a.ppm";
	//int fd;
	t_proj  p;
        t_env   e;
	int	h;
	int	w;

	int wid = 640;
	int hgt = 480;
	char ppm[3*wid*hgt];
	
	//fd = open(file, O_WRONLY);
	//write(fd, "P3\n", 3);
	//write(fd, "900 550\n", 8);
	//write(fd, "255\n", 4);
	
	map->color.r = 0.1;
	map->color.g = 0.3;
	map->color.b = 0.5;
	p.pos = v_create(0, 1, 0, 0);
        p.vel = v_multi(v_normalize(v_create(1, 1.8, 0, 1)), 11.25);
        e.grav = v_create(0, -0.1, 0, 1);
        e.wind = v_create(-0.01, 0, 0, 1);
	h = 0;
	while (h < hgt)
        {
                w = 0;
                while (w < wid)
                {
                        if (w == (int)p.pos.y && h == (int)p.pos.x )
                        {
				ppm[(w + h*wid)*3 + 0] = (unsigned char)(map->color.r*255.0);
        	                ppm[(w + h*wid)*3 + 1] = (unsigned char)(map->color.g*255.0);
	                        ppm[(w + h*wid)*3 + 2] = (unsigned char)(map->color.b*255.0);
                                p = tick(e, p);
//                              map->image.data[h * P_WIDTH + w] = 0xFF;
                        }
                        w++;
                }
                h++;
        }

	printf("%s\n", ppm);
//	close(fd);
	makeppm(ppm, wid, hgt);
	return (0);
}
*/
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
