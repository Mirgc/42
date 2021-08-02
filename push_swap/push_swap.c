/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 17:48:13 by migarcia          #+#    #+#             */
/*   Updated: 2021/08/02 17:43:29 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

int ft_printerr()
{
	write(1, "Error\n", 6);
	return (1);
}

int ft_atoi(char *str, a_list *arr_a)
{
	int num;
	int min;
	int i;

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
			num += *str - '0';
			i++;
		}
		else
			return (1);
	}
	(void) arr_a;
	arr_a->num = num * min;
	arr_a->next = NULL;
	return (0);
}

int	main(int argc, char **argv)
{
	int err;
	int i;
	a_list	*arr_a;

	err = 0;
	i = 1;
	arr_a = malloc(sizeof(a_list *) * argc + 1 );
	if (!arr_a)
		return (0);
	if (argc <= 1)
		ft_printerr();
	else
	{
		while(i < argc)
		{
			err = ft_atoi(argv[i], arr_a);
			if(err == 1)
			{
				ft_printerr();
				return (1);
			}
			i++;
		}
		arr_a = arr_a->next;
	}
	return (0);
}
