/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmartin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 10:12:34 by hmartin-          #+#    #+#             */
/*   Updated: 2021/05/02 21:44:26 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_h.h"

struct s_list	find_nb_def(int number, t_list *tab)
{
	t_list	best_match;
	int		count_defs;
	int		i;
	int		j;

	i =0;
	j =0;
	best_match.nb = -1;
	best_match.str ="not found";
	count_defs = sizeof((t_list *) tab);
	count_defs = 33;
	while (i < count_defs - 1)
	{
		if (tab[i].nb <= number)
		{
			if (best_match.nb < tab[i].nb)
			{
				best_match.nb = tab[i].nb;
				best_match.str = tab[i].str;
			}
		}
		i++;
	}
	return (best_match);
}

void	write_nb_word(char *word)
{
	(void)word;
	while (*word)
		write(1, word++, 1);
	write(1, " ", 1);
}

int	write_number(unsigned int number, t_list *tab)
{
	t_list			best_match;
	long long		nb1;
	long long		nb2;

	nb1 = 0;
	nb2 = 0;
	best_match = find_nb_def(number, tab);
	if (best_match.nb != -1)
	{
		if (best_match.nb < 20)
			write_nb_word(best_match.str);
		else
		{
			nb1 = number / best_match.nb;
			if (!(best_match.nb < 100 && nb1 ==1 ))
				write_number(nb1, tab);
			write_nb_word(best_match.str);
			nb2 = number % best_match.nb;
			if (nb2 != 0)
				write_number(nb2, tab);
		}
	}
	else
		return (-1);
	return (0);
}
