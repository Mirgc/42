/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 19:04:20 by migarcia          #+#    #+#             */
/*   Updated: 2021/04/30 09:27:47 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

int	ft_strlen(char *av)
{
	int	i;

	i = 0;
	while (*av)
	{
		av++;
		i++;
	}
	return (i);
}

char	*ft_strcpy(char *c)
{
	int		i;
	char	*dest;

	i = 0;
	while (c[i])
		i++;
	dest = malloc(sizeof(char) * i + 1);
	if (dest == NULL)
		return (0);
	else
	{
		i = 0;
		while (c[i])
		{
			dest[i] = c[i];
			i++;
		}
		dest[i] = '\0';
		return (dest);
	}
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*tab;
	int			i;

		tab = malloc(sizeof(t_stock_str) * ac + 1);
		if (tab == NULL)
			return (NULL);
		i = 0;
		while (i < ac)
		{
			tab[i].size = ft_strlen(av[i]);
			tab[i].str = av[i];
			tab[i].copy = ft_strcpy(av[i]);
			i++;
		}
		tab[i].str = 0;
		tab[i].size = 0;
		tab[i].copy = 0;
		return (tab);
}
