/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 15:42:13 by migarcia          #+#    #+#             */
/*   Updated: 2021/08/19 16:13:55 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_list **arr, int len)
{
	t_list	*tmp;

	tmp = *arr;
	if (len == 0)
		return (1);
	while (tmp->next != NULL)
	{
		if (tmp->num > tmp->next->num)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void    sort_array(long *array)
{
	int i;
	int j;

	i = 0;
	while (array[i])
	{
		j = i + 1;
		while (array[j])
		{
			if (array[i] > array[j])
				ft_swap(&array[i], &array[j]);
			j++;
		}
		i++;
	}	
}
