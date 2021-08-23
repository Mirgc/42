/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_divide.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 17:26:31 by migarcia          #+#    #+#             */
/*   Updated: 2021/08/19 18:07:39 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	div_arr_a(t_list **arr_a, t_list **arr_b, int len)
{
        int             rot;
        int             mid;
        t_list		*tmp;
        int             half;

        half = len / 2;
        tmp = *arr_a;
        rot = 0;
        mid = get_mid(*arr_a, len);
        while (tmp && half >= 0)
        {
                if (((*arr_a)->ite == 1 && tmp->num < mid) ||
                        ((*arr_a)->ite == 2 && tmp->num <= mid))
                {
                        while ((*arr_a)->num != tmp->num)
                                rot = arr_rot(arr_a, rot);
                        tmp = tmp->next;
                        half = arr_push(arr_a, arr_b, half);
                }
                else
                        tmp = tmp->next;
        }
        return (rot);
}

int	div_arr_b(t_list **arr_a, t_list **arr_b, int len)
{
        int     rot;
        int     mid;
        t_list	*tmp;
        int     half;

        half = len - len / 2;
        tmp = *arr_a;
        rot = 0;
        mid = get_mid(*arr_a, len);
        while (tmp && half > 0)
        {
                if (((*arr_a)->ite == 1 && tmp->num > mid) ||
                        ((*arr_a)->ite == 2 && tmp->num >= mid))
                {
                        while ((*arr_a)->num != tmp->num)
                                rot = arr_rot(arr_a, rot);
                        tmp = tmp->next;
                        half = arr_push(arr_a, arr_b, half);
                }
                else
                        tmp = tmp->next;
        }
        return (rot);
}

