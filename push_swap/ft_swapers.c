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

//void	split_to_a(t_list *arr_a, t_list *arr_b, int avg, int len)
//{
//	while (l-- > 0)
//	{
//		if (len = 13)	
//	}
//}

void	push_swap(t_list **arr_a, t_list **arr_b)
{
	t_list *a;
	t_list *b;
        int max;
	int len_a;
	int len_b;

	a = *arr_a;
	b = *arr_b;
        max = get_max(b);
	len_a = ft_arr_len(&arr_a);
	len_b = ft_arr_len(&arr_b);
        if (len_b == 0)
                return ;
//        split_to_a(a, b, pw_get_avg(b), len_b);
        while ((*(a + (len_a - 1)) == *(a + 1) ||
                *(a + (len_a - 1)) == 1) && !is_sorted(a, len_a))
                ra_rb(a, "ra");
        push_swap(a, b);
        //if (get_size(a, max) >= 20)
        //        pw_backtrack_split(a, b, max);
        //pw_backtrack(a, b, max);

}
