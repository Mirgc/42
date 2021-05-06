/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve_square.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iibanez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 19:57:47 by iibanez-          #+#    #+#             */
/*   Updated: 2021/05/03 20:21:45 by iibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void	ft_check_square_sol(t_map *map, int y, int x)
{
	int	y2;
	int	x2;
	int	valid;

	valid = 0;
	y2 = 0;
	while (y2 < map->r_size && valid != -1)
	{
		x2 = 0;
		while (x2 < map->r_size && valid != -1)
		{
			if (map->tab[y2][x2] == 2)
				valid = -1;
		}
	}
	if (valid == 0)
		map->resolved = 1;
}

void	ft_resolve_square(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (((y + map->r_size) < map->size) && map->resolved != 1)
	{
		x = 0;
		while (((x + map->r_size) < map->size) && map->resolver != 1)
		{
			ft_check_square_sol(map, y, x);
		}
	}
}
