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

void	long_order(t_list **arr_a, t_list **arr_b, t_res **final, int len)
{
	(void)*arr_b;
	int	rot;
	
	if (is_sorted(arr_a, len))
		return ;
	else
	{
		if ((*arr_a)->ite == 1)
			rot = div_stack_a(arr_a, arr_b, len);
		else
			rot = div_stack_b(arr_a, arr_b, len);
		if ((*final)->chang == 1)
	                rotate_rot(arr_a, rot);
		if ((*arr_a)->ite == 1 && (len / 2 == 3 || len / 2 == 2))
			swap_arr(arr_a, arr_b, len);
	}
	return ;
}

void	order(t_list *arr_a, t_list *arr_b, t_res *final)
{
	int	len;

	len = ft_arr_len(&arr_a);
	if (len == 1)
	{
		ft_putstr("");
		//del_node(&arr_a);
	}
	else if (len == 2)
	{
		if (arr_a->num >= arr_a->next->num)
			ft_putstr("rra\n");
		else
			ft_putstr("");
		//del_node(&arr_a);
	}
	else if (len == 3)
	{
		sort_order(arr_a);
		//del_node(&arr_a);
	}
	else
		long_order(&arr_a, &arr_b, &final, len);
}

int	main(int argc, char **argv)
{
	t_list	*arr_a;
	t_list	*arr_b;
	t_res	*final;

	if (argc < 1)
		ft_printerr();
	else
	{
		arr_a = fill_arra(argc, argv);
		arr_b = NULL;
		if (!(arr_a))
		{
			ft_printerr();
			return (0);
		}
		else
		{
			final = (t_res*)malloc(sizeof(t_res));
		        final->chang = 0;
			order(arr_a, arr_b, final);
		}
		//pa_pb(&arr_a, &arr_b);
		//pa_pb(&arr_a, &arr_b);
		printf ("A = ");
		while (arr_a->next != NULL)
		{
			printf("%li, ",arr_a->num);
			arr_a = arr_a->next;
		}
		printf("%li, \n",arr_a->num);
/*		printf ("B = ");
	        while (arr_b->next != NULL)
	        {
	            printf("%li, ",arr_b->num);
	            arr_b = arr_b->next;
	        }
	        printf("%li, \n",arr_b->num);*/
	}
	return (0);
}
