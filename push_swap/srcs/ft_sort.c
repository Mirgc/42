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

int             partition(long *arr, int start, int end)
{
        int     val;
        int     i_sta;
        int     i_now;

        val = arr[end];
        i_sta = start - 1;
        i_now = start;
        while (i_now <= end - 1)
        {
                if (arr[i_now] <= val)
                {
                        i_sta++;
                        ft_swap(&arr[i_sta], &arr[i_now]);
                }
                i_now++;
        }
        ft_swap(&arr[i_sta + 1], &arr[end]);
        return (i_sta + 1);
}

void    quick_sort(long *arr, int start, int end)
{
        long    arr2[end + 1];
        int     i;
        int     mid;

        i = -1;
        arr2[++i] = start;
        arr2[++i] = end;
        while (i >= 0)
        {
                end = arr2[i--];
                start = arr2[i--];
                mid = partition(arr, start, end);
                if (mid - 1 > start)
                {
                        arr2[++i] = start;
                        arr2[++i] = mid - 1;
                }
                if (mid + 1 < end)
                {
                        arr2[++i] = mid + 1;
                        arr2[++i] = end;
                }
        }
}

long    *create_array_from_list(t_list *arr, int len)
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

int     get_mid(t_list *arr, int len)
{
        long    *array;
        int             mid;
        int             arr_len;

        arr_len = ft_arr_len(&arr);
        if (arr_len < len)
                len = arr_len;
        array = create_array_from_list(arr, len);
        quick_sort(array, 0, len -1);
        mid = array[len / 2];
        free(array);
        return (mid);
}

