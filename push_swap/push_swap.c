/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 17:48:13 by migarcia          #+#    #+#             */
/*   Updated: 2021/08/05 19:38:42 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	sort_order(t_list *arr_a)
{
	if (arr_a->num < arr_a->next->num)
	{
		if (arr_a->next->num < arr_a->next->next->num)
			ft_putstr("");
		else if (arr_a->num < arr_a->next->next->num)
			ft_putstr("rra\nsa\n");
		else
			ft_putstr("rra\n");
	}
	else if (arr_a->num > arr_a->next->num)
	{
		if (arr_a->next->num < arr_a->next->next->num)
		{
			if (arr_a->num < arr_a->next->next->num)
				ft_putstr("sa\n");
			else
				ft_putstr("ra\n");
		}
		else
			ft_putstr("sa\nrra\n");
	}	
}

void	order(t_list *arr_a)
{
	int	len;

	len = ft_arr_len(&arr_a);
	if (len == 1)
		ft_putstr("");
	else if (len == 2)
	{
		if (arr_a->num >= arr_a->next->num)
			ft_putstr("rra\n");
		else
			ft_putstr("");
	}
	else if (len == 3)
		sort_order(arr_a);
}

int	main(int argc, char **argv)
{
	t_list	*arr_a;
//	t_list	*arr_b;

	if (argc < 1)
		ft_printerr();
	else
	{
		arr_a = fill_arra(argc, argv);
		if (!(arr_a))
		{
			ft_printerr();
			return (0);
		}
		else
			order(arr_a);
		ra_rb(&arr_a);
		printf ("A = ");
		while (arr_a->next != NULL)
		{
			printf("%li, ",arr_a->num);
			arr_a = arr_a->next;
		}
		printf("%li\n",arr_a->num);
/*		printf ("B = ");
        while (arr_b->next != NULL)
        {
            printf("%li, ",arr_b->num);
            arr_b = arr_b->next;
        }
        printf("%li\n",arr_b->num);*/
	}
	return (0);
}
