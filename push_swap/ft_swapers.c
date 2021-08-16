/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swapers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 18:27:24 by migarcia          #+#    #+#             */
/*   Updated: 2021/08/05 19:00:46 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(long *a, long *b)
{
	long tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void    swap_three(t_list **arr)
{
        if ((*arr)->ite == 1)
		ft_putstr("a");
//                swap_three_a(arr, final);
        else
		ft_putstr("b");
//                swap_three_b(arr, final);
}

void    swap_two(t_list **arr)
{
        if ((*arr)->ite == 1 && ((*arr)->num > (*arr)->next->num))
        {
                sa_sb(arr);
                ft_putstr("sa\n");
        }
        else if ((*arr)->ite == 2 && ((*arr)->num < (*arr)->next->num))
        {
                sa_sb(arr);
                ft_putstr("sb\n");
        }
}


long int	get_min(t_list **arr)
{
	t_list *tmp;
	long int	i;
	
	tmp = *arr;
	i = tmp->num;
	while (tmp->next != NULL)
	{
		if (i > tmp->num)
			i = tmp->num;
		tmp = tmp->next;
	}
	return (i);
}

long int	get_max(t_list **arr)
{
	t_list	*tmp;
	long int	i;

	tmp = *arr;
	i = tmp->num;
	while (tmp->next != NULL)
	{
		if (i < tmp->num)
			i = tmp->num;
		tmp = tmp->next;
	}
	return (i);
}

long int	get_avg(t_list **arr, int len)
{
	t_list *tmp;
	long int i;
	
	tmp = *arr;
	i = 0;
	while (tmp->next !=NULL)
	{
		i += tmp->num;
		tmp = tmp->next;
	}
	return (i/len);
}

long	*create_array_from_list(t_list *stack, int len)
{
        long             *array;
        int             i;

        array = (long*)malloc(sizeof(long) * len);
        i = 0;
        while (i < len)
        {
                array[i] = stack->num;
                stack = stack->next;
                i++;
        }
        return (array);
}

int	get_mid(t_list *arr, int len)
{
        long	*array;
        int	mid;
	int	arr_len;

	arr_len = ft_arr_len(&arr);
	if (arr_len < len)
		len = arr_len;
        array = create_array_from_list(arr, len);
        quick_sort(array, 0, len - 1);
        mid = array[len / 2];
        free(array);
        return (mid);
}

