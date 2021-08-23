/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 15:10:01 by migarcia          #+#    #+#             */
/*   Updated: 2021/08/19 18:21:18 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_printerr()
{
	write(1, "Error\n", 6);
}

void	ft_putstr(char *str)
{
	while(*str)
	{
		write(1, str, 1);
		str++;
	}
}

int	ft_arr_len(t_list **arr)
{
	t_list	*temp;
	int	len;

	temp = *arr;
	len = 0;
	if (!temp)
		return (0);
	while(temp->next != NULL)
	{
		len++;
		temp = temp->next;
	}
	len++;
	return (len);
}

long ft_atoi(char *str)
{
	long	num;
	int		min;
	int		i;
	
	min = 1;
	num = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == 45 || str[i] == 43)
		{
			if (str[i] == 45)
				min = -1;
			i++;
		}
		if (str[i] >= 48 && str[i] <= 57 )
		{
			num *= 10;
			num += str[i] - '0';
			i++;
		}
		else
			return (0);
	}
	num = num * min;
	return (num);
}
