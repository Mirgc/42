/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 17:51:29 by migarcia          #+#    #+#             */
/*   Updated: 2021/05/06 17:48:18 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	j;
	int	*tab;

	if (min >= max)
	{
		range = NULL;
		return (0);
	}
	else
	{
		i = 0;
		while (i < (max - min))
			i++;
		tab = malloc(sizeof(*tab) * i);
		if (tab == NULL)
			return (-1);
		j = -1;
		while (++j < i)
			tab[j] = min + j;
		*range = tab;
	}
	return (j);
}
