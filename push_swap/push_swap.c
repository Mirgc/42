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

void	sort_order(t_list **arr_a)
{
	if ((*arr_a)->num < (*arr_a)->next->num)
	{
		if ((*arr_a)->next->num < (*arr_a)->next->next->num)
			ft_putstr("");
		else if ((*arr_a)->num < (*arr_a)->next->next->num)
			ft_putstr("rra\nsa\n");
		else
			ft_putstr("rra\n");
	}
	else if ((*arr_a)->num > (*arr_a)->next->num)
	{
		if ((*arr_a)->next->num < (*arr_a)->next->next->num)
		{
			if ((*arr_a)->num < (*arr_a)->next->next->num)
				ft_putstr("sa\n");
			else
				ft_putstr("ra\n");
		}
		else
			ft_putstr("sa\nrra\n");
	}	
}

void	long_order(t_list **arr_a, t_list **arr_b, int change, int len)
{
	int	rot;
	
		printf("ite: %i\n",(*arr_a)->ite);
		if (len == 2 || len == 3)
			return ;
		if ((*arr_a)->ite == 1)
			rot = div_stack_a(arr_a, arr_b, len);
		else
			rot = div_stack_b(arr_a, arr_b, len);
		if (change == 1)
	                rotate_rot(arr_a, rot);
		if (((*arr_a)->ite == 1 || (*arr_a)->ite == 2)&& (len / 2 == 3 || len / 2 == 2))
			swap_arr(arr_a, arr_b, change, len);
		if ((*arr_a)->ite != 1)
		{
			long_order(arr_a, arr_b, change, len / 2);
			long_order(arr_a, arr_b, change, len - len / 2);
		}
		else
		{
			long_order(arr_a, arr_b, change, len - len / 2);
		//	long_order(arr_a, arr_b, change, len / 2);
		}
}

void	order(t_list **arr_a, t_list **arr_b, int change)
{
	int	len;

	len = ft_arr_len(arr_a);
	if (is_sorted(arr_a, len))
	{
		ft_putstr("");
		//del_node(&arr_a);
	}
	else if (len == 2)
	{
		if ((*arr_a)->num >= (*arr_a)->next->num)
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
		long_order(arr_a, arr_b, change, len);

}

int	main(int argc, char **argv)
{
	t_list	*arr_a;
	t_list	*arr_b;
	int	change;

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
		        change = 0;
			order(&arr_a, &arr_b, change);
		}
		printf ("A = ");
		while (arr_a->next != NULL)
		{
			printf("%li(%i), ",arr_a->num, arr_a->ite);
			arr_a = arr_a->next;
		}
		printf("%li(%i)\n",arr_a->num, arr_a->ite);
		printf ("B = ");
	        while (arr_b->next != NULL)
	        {
	            printf("%li(%i), ",arr_b->num, arr_b->ite);
	            arr_b = arr_b->next;
	        }
	        printf("%li(%i)\n",arr_b->num, arr_b->ite);
	}
	return (0);
}
