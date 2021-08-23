/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 15:13:40 by migarcia          #+#    #+#             */
/*   Updated: 2021/08/03 20:38:47 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	del_node(t_list	**arr)
{
	t_list	*del;
	t_list	*temp;

	temp = *arr;
	while (temp)
	{
		del = temp;
		temp = temp->next;
		free(del);
	}
	*arr = NULL;
}

t_list	*add_node(void)
{
	t_list	*temp;	

	temp = (t_list *)malloc(sizeof(t_list));
	temp->num = 0;
	temp->ite = 1;
	temp->next = NULL;
	return (temp);
}

long	is_num(char *str, t_list **f_arr)
{
	int			num;
	t_list		*temp;

	temp = *f_arr;
	num = ft_atoi(str);
	while (temp->next != NULL)
	{
		if (temp->num == num)
			return (0);
		temp = temp->next;
	}
	num = isisnum(str);
	return (num);
}

long	isisnum(char *str)
{
	long num;

	num = ft_atoi(str);
	if (str[0] == 48) 
		return (1);
	else if ((str[0] == 43 || str[0] == 45) && str[1] == 48)
		return (1);
	else if (num <= 2148473647 && num >= -2148473648)
	   return (num);
	return (0);
}

t_list	*fill_arra(int argc, char **argv)
{
	t_list	*f_arr;
	t_list	*temp;
	char	**split;
	int		i;

	i = 1;
	f_arr = NULL;
	temp = NULL;
	while (i < argc)
	{
		split = ft_split(argv[i], ' ');
		while (*split)
		{
			temp = ft_lstnew(ft_atoi(*split));
			ft_lstadd_back(&f_arr, temp);
			if(!(is_num(*split, &f_arr)))
			{
				del_node(&f_arr);
				return (NULL);
			}
			split++;
		}
		i++;
	}
	return (f_arr);
}
