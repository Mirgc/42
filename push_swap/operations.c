/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 17:23:35 by migarcia          #+#    #+#             */
/*   Updated: 2021/08/05 20:00:19 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa_sb(t_list **arr)
{
	t_list *temp;

	temp = *arr;
	if(temp && temp->next)
		ft_swap(&temp->num, &temp->next->num);
}

void	pa_pb(t_list **arr_from, t_list **arr_to)
{
	t_list *tmp;
        t_list *to;
        t_list *from;

        to = *arr_to;
        from = *arr_from;
        if (!from)
                return ;
        tmp = from;
        from = from->next;
        *arr_from = from;
        if (!to)
        {
                to = tmp;
                to->next = NULL;
                *arr_to = to;
        }
        else
        {
                tmp->next = to;
                *arr_to = tmp;
        }
}

void 	ra_rb(t_list **arr, char *ope)
{
	t_list *first;
	t_list *last;
	t_list *temp;

	temp = *arr;
	first = temp;
	temp = temp->next;
	last = temp;
	while (last->next)
		last = last->next;
	last->next = first;
	last = last->next;
	last->next = NULL;
	*arr = temp;
	ft_putstr(ope);
}

void	rra_rrb(t_list **arr)
{
	t_list *last;
	t_list *prev;
	t_list *temp;

	temp = *arr;
	last = *arr;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = temp;
	*arr = last;
}
