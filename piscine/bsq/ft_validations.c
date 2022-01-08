/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 16:43:41 by migarcia          #+#    #+#             */
/*   Updated: 2021/05/04 18:16:01 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_validation(t_map *map)
{
	int	i;
	int	j;
	int	full;

	full = 0;
	i = -1;
	while (++i < map->size && full == 0)
	{
		j = -1;
		while (++j < map->size && full == 0)
		{
			if (map->tab[i][j] == 0)
				full = 1;
		}
	}
	return (full);
}

void	ft_save_map(t_map *map_c1, t_map *map_c2)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map_c1->size)
	{
		j = -1;
		while (++j < map_c1->size)
		{
			map_c2->tab[i][j] = map_c1->tab[i][j];
		}
	}
}
