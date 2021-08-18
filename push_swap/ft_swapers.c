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

void    swap_three_a2(t_list **arr)
{
        if ((*arr)->num > (*arr)->next->num &&
                (*arr)->num > (*arr)->next->next->num &&
                (*arr)->next->num < (*arr)->next->next->num)
        {
                if (ft_arr_len(arr) > 3)
                        op_3(arr);
                else
                        op_7(arr);
        }
        else if ((*arr)->num < (*arr)->next->num &&
                (*arr)->num > (*arr)->next->next->num &&
                (*arr)->next->num > (*arr)->next->next->num)
        {
                if (ft_arr_len(arr) > 3)
                        op_4(arr);
                else
                        op_8(arr);
        }
        else if ((*arr)->num > (*arr)->next->num &&
                (*arr)->next->num > (*arr)->next->next->num)
        {
                if (ft_arr_len(arr) > 3)
                        op_5(arr);
                else
                        op_9(arr);
        }
}

void    swap_three_a(t_list **arr)
{
        if ((*arr)->num < (*arr)->next->num &&
                (*arr)->next->num < (*arr)->next->next->num)
                return ;
        if ((*arr)->num > (*arr)->next->num &&
                (*arr)->next->num < (*arr)->next->next->num &&
                (*arr)->num < (*arr)->next->next->num)
	{
        	if (ft_arr_len(arr) > 3)
			op_1(arr);
		else
			swap_two(arr);
	}
        else if ((*arr)->num < (*arr)->next->num &&
                (*arr)->next->num > (*arr)->next->next->num &&
                        (*arr)->num < (*arr)->next->next->num)
	{
		if (ft_arr_len(arr) > 3)
			op_2(arr);
		else
			op_6(arr);
	}
	else
		swap_three_a2(arr);
}

void    swap_three_b(t_list **arr)
{
        if ((*arr)->num > (*arr)->next->num &&
                (*arr)->next->num > (*arr)->next->next->num)
                return ;
        else if ((*arr)->num < (*arr)->next->num &&
                (*arr)->num > (*arr)->next->next->num &&
                (*arr)->next->num > (*arr)->next->next->num)
	{
		if (ft_arr_len(arr) > 3)
			op_1(arr);
		else
			swap_two(arr);
	}
        else if ((*arr)->num > (*arr)->next->num &&
                (*arr)->num > (*arr)->next->next->num &&
                (*arr)->next->num < (*arr)->next->next->num)
	{
		if (ft_arr_len(arr) > 3)
			op_2(arr);
		else
			op_6(arr);
	}
        else if ((*arr)->num < (*arr)->next->num &&
                (*arr)->next->num > (*arr)->next->next->num &&
                (*arr)->num < (*arr)->next->next->num)
	{
                if (ft_arr_len(arr) > 3) 
			op_3(arr);
		else
			op_7(arr);
	}
        else if ((*arr)->num > (*arr)->next->num &&
                (*arr)->next->num < (*arr)->next->next->num &&
                (*arr)->num < (*arr)->next->next->num)
	{
		if (ft_arr_len(arr) > 3)
			op_4(arr);
		else
			op_8(arr);
	}
        else if ((*arr)->num < (*arr)->next->num &&
                (*arr)->next->num < (*arr)->next->next->num)
	{
		if (ft_arr_len(arr) > 3)
			op_5(arr);
		else
			op_9(arr);
	}
}


void    swap_three(t_list **arr)
{
        if ((*arr)->ite == 1)
	{
                swap_three_a(arr);
	}
        else
                swap_three_b(arr);
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


long	*create_array_from_list(t_list *arr, int len)
{
        long             *array;
        int             i;

        array = (long*)malloc(sizeof(long) * len);
        i = 0;
        while (i < len)
        {
                array[i] = arr->num;
                arr = arr->next;
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
	sort_array(array);
        mid = array[len / 2];
        free(array);
        return (mid);
}

