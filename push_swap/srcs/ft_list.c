/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 20:32:32 by migarcia          #+#    #+#             */
/*   Updated: 2021/08/03 20:35:36 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list  *ft_lstnew(long content)
{
	t_list  *list;

	list = malloc(sizeof(t_list) * 1);
	if (!list)
		return (NULL);
	list->num = content;
	list->ite = 1;
	list->next = NULL;
	return (list);
}

t_list  *ft_lstlast(t_list *lst)
{
	t_list  *aux;

	if (!lst)
		return (NULL);
	aux = lst;
	while (aux->next)
		aux = aux->next;
	return (aux);
}

void    ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list  *last;

	if (*lst)
	{
		last = ft_lstlast(*lst);
		last->next = new;
	}
	else
	*lst = new;
}
