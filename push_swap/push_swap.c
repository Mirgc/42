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

void ft_printerr()
{
	write(1, "Error\n", 6);
}

void	del_node(t_list **arr)
{
	t_list	*del;
	t_list	*temp;

	temp = *arr;
	while(temp)
	{
		del = temp;
		temp = temp->next;
		free(del);
	}
	*arr = NULL;
}

int ft_atoi(char *str)
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
			num += str[i] - '0';
			i++;
		}
		else
			return (0);
	}
	num = num * min;
	return (num);
}

t_list	*add_node(void)
{
	t_list *temp;

	temp = (t_list *)malloc(sizeof(t_list));
	temp->num = 0;
	temp->ite = 1;
	temp->next = NULL;

	return (temp);
}

int	is_num(char *str)
{
	if(str[0] != 48)
		return(ft_atoi(str));
	else
		return(1);	
}

t_list	*fill_arra(int argc, char **argv)
{
	t_list  *f_arr;
	t_list	*temp;
	int	err;
	int	i;

	i = 1;
	f_arr = add_node();
	temp = f_arr;
	while (i < argc)
	{
		if (!(is_num(argv[i])))
		{
			del_node(&f_arr);
			return (NULL);
		}
		else
			temp->num = ft_atoi(argv[i]);
			if (i < argc - 1)
			{
				temp->next = add_node();
				temp = temp->next;
			}
		i++;
	}
	return (f_arr);
}


int	main(int argc, char **argv)
{
	t_list	*arr_a;
//	t_list	*arr_b;
	
	if (argc < 1)
		ft_printerr();
	else
	{
		if (!(arr_a = fill_arra(argc, argv)))
		{
			ft_printerr();
			return (0);
		}
		while(arr_a->next != NULL)
		{
			printf("%i = %p\n",arr_a->num, arr_a);
			arr_a = arr_a->next;
		}
		printf("%i = %p\n",arr_a->num, arr_a);
	}
	return (0);
}
