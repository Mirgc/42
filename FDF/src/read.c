#include "../includes/fdf.h"

void    ft_error(char *str)
{
    ft_putstr_fd(str, 2);
    exit(0);
}

void	mix_color(t_map *map)
{
	map->color.r = (rand() % 0x7f);
	map->color.g = (rand() % 0x7f);
	map->color.b = (rand() % 0x7f);
}

long    isisnum(char *str)
{
    long num;

    num = ft_atoi(str);
    if (str[0] == 48)
        return (1);
    else if ((str[0] == 43 || str[0] == 45) && str[1] == 48)
        return (1);
    else if (str[0] == '\n')
        return (1);
    else if (num <= 2148473647 && num >= -2148473648)
       return (num);
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
        map->zoom = (P_WIDTH / map->width) + MAGNIFY;
    else
		map->zoom = (P_HEIGHT / map->height) + MAGNIFY;
	map->isometric = 1;
	map->color.r = 0x4F;
	map->color.g = 0x4F;
	map->color.b = 0x4F;
}

void	fill_matrix(t_map *map, int x, int y, char *line)
{
	int		i;
	char	**tab;

	if ((tab = ft_split(line, ' ')))
	{
		i = 0;
		while (tab[i] && (x != map->width))
		{
			map->matrix[y][x] = ft_atoi(tab[i++]);
			x++;
		}
		free(tab);
	}
}
