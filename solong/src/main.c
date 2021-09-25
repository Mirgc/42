/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 14:44:05 by migarcia          #+#    #+#             */
/*   Updated: 2021/09/25 13:09:10 by migarcia         ###   ########.fr       */
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

int read_map(char *argv, t_map *map)
{
	int fd;
	char *line;

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

void	init_map(t_map *map)
{
	map->width = 0;
	map->height = 0;
}

int	main(int argc, char **argv)
{
	t_map *map;
	char *pru;

	pru = malloc(sizeof(char*)* 15);
	
	if (argc == 2)
	{
		map = malloc(sizeof(map));
		if (!map)
			return (0);
		init_map(map);
		if (read_map(argv[1], map) == 1)
		{
			free(map);
			return(0);
		}
	}
	else
	{
		ft_putstr_fd("##ERROR## Usage: ./fdf <filename>\n", 1);
		return (0);
	}
	system("leaks fdf");
}
