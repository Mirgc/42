#include "fdf.h"
#include <math.h>

void    draw(t_map *map, int x, int y, int color)
{
    char    *dst;

    dst = map->img.data + (y * map->img.size + x * (map->img.bpp / 8));
    *(unsigned int*)dst = color;
}


static void	draw_pix(t_map *map)
{
	double	x;
	double	y;
	double	dx;
	double	dy;
	double	p;

	x = map->x0;
	y = map->y0;
	dx = map->x1 - map->x0;
	dy = map->y1 - map->y0;
	p = sqrt((pow(dx, 2)) + (pow(dy, 2)));
	dx /= p;
	dy /= p;
	while (p > 0)
	{
		draw(map, x, y, 0xFF0000);
		x += dx;
		y += dy;
		p -= 1;
	}
}

static void	draw_to_xaxis(t_map *map, int x, int y)
{
	int		dx;
	int		dy;

	dx = x - map->width / 2;
	dy = y - map->height / 2;
	map->x0 = map->angle_x * (dx - dy) * map->scalin;
	map->y0 = map->angle_y * (dx + dy) * map->scalin;
	map->y0 -= map->matrix[y][x] * map->z_value;
	map->x1 = map->angle_x * ((dx + 1) - dy) * map->scalin;
	map->y1 = map->angle_y * ((dx + 1) + dy) * map->scalin;
	map->y1 -= map->matrix[y][x + 1] * map->z_value;
	map->x0 += (P_WIDTH / 2) + map->coord_x;
	map->y0 += (P_HEIGHT / 2) + map->coord_y;
	map->x1 += (P_WIDTH / 2) + map->coord_x;
	map->y1 += (P_HEIGHT / 2) + map->coord_y;
	draw_pix(map);
}

static void	draw_to_yaxis(t_map *map, int x, int y)
{
	int		dx;
	int		dy;

	dx = x - map->width / 2;
	dy = y - map->height / 2;
	map->x0 = map->angle_x * (dx - dy) * map->scalin;
	map->y0 = map->angle_y * (dx + dy) * map->scalin;
	map->y0 -= map->matrix[y][x] * map->z_value;
	map->x1 = map->angle_x * (dx - (dy + 1)) * map->scalin;
	map->y1 = map->angle_y * (dx + (dy + 1)) * map->scalin;
	map->y1 -= map->matrix[y + 1][x] * map->z_value;
	map->x0 += (P_WIDTH / 2) + map->coord_x;
	map->y0 += (P_HEIGHT / 2) + map->coord_y;
	map->x1 += (P_WIDTH / 2) + map->coord_x;
	map->y1 += (P_HEIGHT / 2) + map->coord_y;
	draw_pix(map);
}

int			draw_map(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	map->mlx.img = mlx_new_image(map->mlx.init, P_WIDTH, P_HEIGHT);
	map->img.data = mlx_get_data_addr(map->mlx.img, &map->img.bpp, \
			&map->img.size, &map->img.endian);
	while (map->height > y)
	{
		x = 0;
		while (map->width > x)
		{
			map->x0 = x;
			map->y0 = y;
			if (map->width > x + 1)
				draw_to_xaxis(map, x, y);
			if (map->height > y + 1)
				draw_to_yaxis(map, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(map->mlx.init, map->mlx.win, map->mlx.img, 0, 0);
	mlx_destroy_image(map->mlx.init, map->mlx.img);
	return (0);
}
