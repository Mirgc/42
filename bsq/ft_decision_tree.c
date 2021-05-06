/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decision_tree.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iibanez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 12:26:45 by iibanez-          #+#    #+#             */
/*   Updated: 2021/05/04 18:17:27 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_fill_small_squares_h(t_map *map, int i, int j)
{
	int	k;
	int	result;
	int	changes;

	changes = 0;
	result = -1;
	k = 0;
	while (k < map->r_size && result == -1)
	{
		if (map->tab[i][j + k] == 1 || (j + k) >= (map->size))
			result = k;
		k++;
	}
	k = 0;
	if (result != -1)
	{
		while (k < result)
		{
			map->tab[i][j + k] = 1 ;
			k++;
			changes = 1;
		}
	}
	return (changes);
}

int	ft_dec_tree_start_h(t_map *map)
{
	int	i;
	int	j;
	int	changes;
	int	max_changes;

	i = -1;
	while (++i < map->size)
	{
		j = 0;
		while (j < map->size)
		{
			if (j == 0 || map->tab[i][j - 1] == 1)
			{
				changes = ft_fill_small_squares_h(map, i, j);
				if (changes == 1)
					max_changes = 1;
			}
			j++;
		}
	}
	return (max_changes);
}

int	ft_fill_small_squares_v(t_map *map, int i, int j)
{
	int	k;
	int	result;
	int	changes;

	result = -1;
	k = 0;
	changes = 0;
	while (k < map->r_size && result == -1)
	{
		if ((j + k) >= (map->size) || map->tab[j + k][i] == 1)
			result = k;
		k++;
	}
	k = 0;
	if (result != -1)
	{
		while (k < result)
		{
			map->tab[j + k][i] = 1 ;
			k++;
			changes = 1;
		}
	}
	return (changes);
}

int	ft_dec_tree_start_v(t_map *map)
{
	int	i;
	int	j;
	int	changes;
	int	max_changes;

	i = -1;
	max_changes = 0;
	while (++i < map->size)
	{
		j = 0;
		while (j < map->size)
		{
			if (j == 0 || map->tab[j - 1][i] == 1)
			{
				changes = ft_fill_small_squares_v(map, i, j);
				if (changes == 1)
					max_changes = 1;
			}
			j++;
		}
	}
	return (max_changes);
}

void	ft_decision_tree(t_map *map_c1, t_map *map_c2)
{
	int	stop_flag;
	int	full;

	stop_flag = 1;
	while (stop_flag != 0)
	{
		stop_flag = ft_dec_tree_start_h(map_c1) + ft_dec_tree_start_v(map_c1);
	}
	full = ft_validation(map_c1);
	if (full)
	{
		ft_save_map(map_c1, map_c2);
		map_c1->r_size = map_c1->r_size + 1;
		ft_decision_tree(map_c1, map_c2);
	}
}
