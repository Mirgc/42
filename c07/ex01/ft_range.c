/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 11:22:03 by migarcia          #+#    #+#             */
/*   Updated: 2021/04/27 19:59:04 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*arr;
	int	i;
	int	j;

	i = 0;
	if (min >= max)
		return (NULL);
	else
	{
		while (i < max - min)
			i++;
	}
	arr = malloc(sizeof(*arr) * i);
	if (arr == NULL)
		return (0);
	j = 0;
	while (i > j)
	{
		arr[j] = min + j;
		j++;
	}
	return (arr);
}
