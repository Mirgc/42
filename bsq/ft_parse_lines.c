/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_lines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 16:51:57 by migarcia          #+#    #+#             */
/*   Updated: 2021/05/04 14:38:17 by iibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

struct s_map	*ft_parse_lines(int l_n, char *str, int line_s, t_map *map)
{
	int	i;

	i = 0;
	while (str[line_s] != '\n')
	{
		if (str[line_s] != map->empty_c && str[line_s] != map->obstacle_c)
			map->size = -1;
		else
		{
			if (str[line_s] == map->empty_c)
				map->tab[l_n - 1][i] = 0;
			if (str[line_s] == map->obstacle_c)
				map->tab[l_n - 1][i] = 1;
		}
		i++;
		line_s++;
	}
	if (i != map->size)
		map->size = -1;
	if (l_n > map->size)
		map->size = -1;
	return (map);
}

struct s_map	*ft_parse_last_line(int l_n, t_map *map)
{
	if (l_n < map->size + 1)
		map->size = -1;
	return (map);
}
