
#include "../includes/fdf.h"

int			map_keys(int keycode, t_map *map)
{
/*	(void)map;
	printf("%i\n", keycode);*/
	if (keycode == 65307)
		exit(0);
    else if (keycode == 65362)
        map->coord_y -= 2;
    else if (keycode == 65364)
        map->coord_y += 2;
    else if (keycode == 65361)
        map->coord_x -= 3;
    else if (keycode == 65363)
        map->coord_x += 3;
	else if (keycode == 114)
        nomalize_map(map);
    else if (keycode == 113)
        map->zoom += 1;
    else if (keycode == 97)
        map->zoom -= 1;
    else if (keycode == 119)
        map->z_value += 0.25;
    else if (keycode == 115)
        map->z_value -= 0.25;
    else if (keycode == 101)
        mix_color(map);
    return (0);
}

int         ft_wdcount(char *line)
{
    int     count;
    char    **tab;

    count = 0;
    tab = ft_split(line, ' ');
    while (tab[count])
        count++;
    return (count);
}

int         line_count(char *argv, t_map *map)
{
    int     rows;
    int     cols;
    int     len;
    int     fd;
    char    *line;

    fd = open(argv, O_RDONLY);
    rows = 0;
    cols = 0;
    while (get_next_line(fd, &line) == 1)
    {
        if (*line == '\0')
            break ;
        len = ft_wdcount(line);
        if (cols == 0)
            cols = len;
        if (cols == len)
            rows ++;
        else
            ft_error("##ERROR##Not a valid file!\n");
        free(line);
    }
    close(fd);
    map->width = cols;
    return (rows);
}


void		map_read(char *str, t_map *map)
{
	int		fd;
	int		x;
	char	*line;
	int		y;

	x = 0;
	y = 0;
	map->height = line_count(str, map);
	if ((fd = open(str, O_RDONLY)) < 0)
		ft_error("##ERROR## Can't open file!\n");
	map->matrix = (int **)malloc(sizeof(int *) * map->height);
	while (get_next_line(fd, &line) == 1 && y != map->height)
	{
		map->matrix[y] = (int *)malloc(sizeof(int) * map->width);
		if (!(isisnum(line)))
        {
            free(map->matrix);
            ft_error("##ERROR## Wrong Map!!\n");
        }
		fill_matrix(map, x, y, line);
		y++;
		free(line);
	}
	close(fd);
}

int			main(int argc, char **argv)
{
	t_map	*map;

	if (argc == 2)
	{
		if (!(map = (t_map *)malloc(sizeof(t_map))))
	        ft_error("##ERROR## Memory Allocation failed!\n");
	    map_read(argv[1], map);
	    nomalize_map(map);
	    map->mlx.init = mlx_init();
	    map->mlx.win = mlx_new_window(map->mlx.init, P_WIDTH, P_HEIGHT, "FDF");
	    mlx_hook(map->mlx.win, 2, 3, map_keys, map);
	    mlx_loop_hook(map->mlx.init, map_draw, map);
	    mlx_loop(map->mlx.init);

	}
	else
		ft_putstr_fd("##ERROR## Usage: ./map <filename>\n", 1);
	return (0);
}
