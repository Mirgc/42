/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 17:51:37 by migarcia          #+#    #+#             */
/*   Updated: 2021/10/23 10:11:46 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include "../libft/libft.h"
#include <fcntl.h>
#include <stdlib.h>

long	isisnum(char *str)
{
	long	num;

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

void	fill_matrix(t_map *map, int x, int y, char *line)
{
	int		i;
	char	**tab;

	tab = ft_split(line, ' ');
	if ((tab))
	{
		i = 0;
		while (tab[i] && (x != map->width))
		{
			map->matrix[y][x] = ft_atoi(tab[i]);
			free(tab[i++]);
			x++;
		}
		free(tab);
	}
}

int	ft_wdcount(char *line)
{
	int		count;
	char	**tab;

	count = 0;
	tab = ft_split(line, ' ');
	while (tab[count])
	{
		free(tab[count]);
		count++;
	}
	free(tab);
	return (count);
}

int	line_count(char *argv, t_map *map)
{
	int		rows;
	int		len;
	int		fd;
	char	*line;

	fd = open(argv, O_RDONLY);
	rows = 0;
	map->width = 0;
	while (get_next_line(fd, &line) == 1)
	{
		if (*line == '\0')
			break ;
		len = ft_wdcount(line);
		if (map->width == 0)
			map->width = len;
		if (map->width == len)
			rows ++;
		else
			ft_error("##ERROR##Not a valid file!\n");
		free(line);
	}
	free(line);
	close(fd);
	return (rows);
}

void	map_read(char *str, t_map *map)
{
	int		fd;
	int		x;
	char	*line;
	int		y;

	x = 0;
	y = 0;
	map->height = line_count(str, map);
	fd = open(str, O_RDONLY);
	if (fd < 0)
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
		fill_matrix(map, x, y++, line);
		free(line);
	}
	free(line);
	close(fd);
}
