/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iibanez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 10:34:36 by iibanez-          #+#    #+#             */
/*   Updated: 2021/05/04 18:12:02 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int	**reserve_tab_memory(int size)
{
	int	**tab;
	int	i;

	tab = malloc (sizeof(*tab) * size);
	i = 0;
	while (i < size)
	{
		tab[i] = malloc (sizeof (*tab[i]) * size);
		i++;
	}
	return (tab);
}

struct s_map	*set_map(unsigned int size, char empty_c,
							char obstacle_c, char full_c)
{
	t_map	*map;

	map = malloc(sizeof(*map) * 1);
	map->size = size;
	map->empty_c = empty_c;
	map->full_c = full_c;
	map->obstacle_c = obstacle_c;
	map->tab = reserve_tab_memory(map->size);
	map->r_size = 0;
	map->resolved = 0;
	return (map);
}

struct s_map	*set_error_map(void)
{
	t_map	*map;

	map = malloc(sizeof(*map) * 1);
	map->size = -1;
	return (map);
}

void	free_map_memory(t_map map)
{
	int	i;

	i = 0;
	while (i < map.size)
	{
		free(map.tab[i]);
		i++;
	}
	free(map.tab);
}

struct	s_map	*ft_copy(t_map *map)
{
	t_map	*map_copy;
	int		i;
	int		j;

	map_copy = set_map(map->size, map->empty_c, map->obstacle_c, map->full_c);
	i = -1;
	while (++i < map->size)
	{
		j = -1;
		while (++j < map->size)
		{
			map_copy->tab[i][j] = map->tab[i][j];
		}
	}
	return (map_copy);
}
