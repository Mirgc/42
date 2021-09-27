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

int	ft_wordcount(char *line)
{
	int		count;

	count = 0;
	while (*line)
	{
		while (*line && (*line == ' '))
            line++;
        while (*line && *line != ' ')
            line++;
		count++;
	}
	return (count);
}

void	fill_matrix(int *matrix, char *line)
{
	char **tab;
	int		i;

	tab = ft_split(line, ' ');
	i = 0;
	while(tab[i])
	{
		matrix[i] = ft_atoi(tab[i]);
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	ft_get_matrix(char *argv, t_map *map)
{
	int fd;
	char *line;
	int i;

	fd = open(argv, O_RDONLY);
	map->matrix = (int **)malloc(sizeof(int *) * (map->height + 1));
	i = -1;
	while (i++ < map->height)
		map->matrix[i] = (int *)malloc(sizeof(int) * (map->width + 1));
	i = 0;
	while ((line = get_next_line(fd)))
	{
		fill_matrix(map->matrix[i], line);
		i++;
		free(line);
	}
	close(fd);
//	map->matrix[i] = NULL;
}

void	init_map(t_map *map)
{
	map->width = 0;
	map->height = 0;
}

int read_map(char *argv, t_map *map)
{
	int fd;
	char *line;

	init_map(map);
	fd = open(argv, O_RDONLY);
	while ((line = get_next_line(fd)))
	{
		map->width = ft_wordcount(line);
		map->height++;
		free(line);
	}        
	if (map->width == 0)
	{
		if (fd < 0)
			ft_putstr_fd("##ERROR## Can't read file!\n", 1);
		else
			ft_putstr_fd("##ERROR## Map is Wrong!\n", 1);
		return (1);
	}
	close(fd);
	ft_get_matrix(argv, map);
	return (0);
}

int	deal_key(int key, void *map)
{
	(void)map;
	printf("%d", key);
	return(0);
}

int	main(int argc, char **argv)
{
	t_map *map;

	if (argc != 2)
	{
		ft_putstr_fd("##ERROR## Usage: ./fdf <filename>\n", 1);
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
	map->mlx_ptr = mlx_init();
	map->win_ptr = mlx_new_window(map->mlx_ptr, 1000, 1000, "FDF");
	draw_map(map);
	mlx_key_hook(map->win_ptr, deal_key, NULL);
//	mlx_hook(map->mlx_ptr, 17, 0, (void *)exit, 0);
	mlx_loop(map->mlx_ptr);
	system("leaks fdf");
}
