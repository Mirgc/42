/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_diagonals.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iibanez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 19:08:37 by iibanez-          #+#    #+#             */
/*   Updated: 2021/05/03 20:57:06 by iibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int	ft_get_table_d1_max(t_map *map)
{
	int	y;
	int	x;
	int	max_l;
	int	max;

	max = 0;
	y = -1;
	while (++y < map->size)
	{
		max_l = 0;
		x = 0;
		while ((x + y) < map->size)
		{
			if (map->tab[y + x][x] == 0)
				max_l++;
			else
				max_l = 0;
			if (max_l > max)
				max = max_l;
			x++;
		}
	}
	return (max);
}

int	ft_get_table_d2_max(t_map *map)
{
	int	y;
	int	x;
	int	max_l;
	int	max;

	max = 0;
	y = -1;
	while (++y < map->size)
	{
		max_l = 0;
		x = 0;
		while ((x + y) < map->size)
		{
			if (map->tab[x][x + y] == 0)
				max_l++;
			else
				max_l = 0;
			if (max_l > max)
				max = max_l;
			x++;
		}
	}
	return (max);
}

int	ft_get_table_d3_max(t_map *map)
{
	int	y;
	int	x;
	int	max_l;
	int	max;

	max = 0;
	y = -1;
	while (++y < map->size)
	{
		max_l = 0;
		x = 0;
		while ((x + y) < map->size)
		{
			if (map->tab[map->size - (y + x) - 1][map->size - x - 1] == 0)
				max_l++;
			else
				max_l = 0;
			if (max_l > max)
				max = max_l;
			x++;
		}
	}
	return (max);
}

int	ft_get_table_d4_max(t_map *map)
{
	int	y;
	int	x;
	int	max_l;
	int	max;

	max = 0;
	y = -1;
	while (++y < map->size)
	{
		max_l = 0;
		x = 0;
		while ((x + y) < map->size)
		{
			if (map->tab[map->size - x - 1][map->size - (x + y) - 1] == 0)
				max_l++;
			else
				max_l = 0;
			if (max_l > max)
				max = max_l;
			x++;
		}
	}
	return (max);
}
