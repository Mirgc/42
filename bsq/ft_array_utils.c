/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iibanez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 16:53:05 by iibanez-          #+#    #+#             */
/*   Updated: 2021/05/04 14:37:50 by iibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int	ft_get_table_h_max(t_map *map)
{
	int	y;
	int	x;
	int	max_l;
	int	max;

	y = -1;
	max = 0;
	while (++y < map->size)
	{
		max_l = 0;
		x = -1;
		while (++x < map->size)
		{
			if (map->tab[y][x] == 0)
				max_l++;
			else
				max_l = 0;
			if (max_l > max)
				max = max_l;
		}
	}
	return (max);
}

int	ft_get_table_v_max(t_map *map)
{
	int	y;
	int	x;
	int	max_l;
	int	max;

	y = -1;
	max = 0;
	while (++y < map->size)
	{
		max_l = 0;
		x = -1;
		while (++x < map->size)
		{
			if (map->tab[x][y] == 0)
				max_l++;
			else
				max_l = 0;
			if (max_l > max)
				max = max_l;
		}
	}
	return (max);
}

int	ft_get_min_value_array(int *max_tab, int size)
{
	int	min;
	int	i;

	i = 0;
	min = max_tab[0];
	while (++i < size)
	{
		if (max_tab[i] < min)
			min = max_tab[i];
	}
	return (min);
}

void	ft_get_table_max_size(t_map *map)
{
	int	max[6];

	max[0] = ft_get_table_h_max(map);
	max[1] = ft_get_table_v_max(map);
	max[2] = ft_get_table_d1_max(map);
	max[3] = ft_get_table_d2_max(map);
	max[4] = ft_get_table_d3_max(map);
	max[5] = ft_get_table_d4_max(map);
	map->r_size = ft_get_min_value_array(max, 6);
}
