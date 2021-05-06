/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 08:53:10 by migarcia          #+#    #+#             */
/*   Updated: 2021/04/26 12:33:06 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	char	*c;

	c = str;
	while (*c)
	{
		write(1, c, 1);
		c++;
	}
	write(1, "\n", 1);
}

int	ft_compare(char *s1, char *s2)
{
	while (*s1 == *s2 && *s1)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	ft_order(char *str[], int argc)
{
	char	*aux;
	int		i;
	int		j;

	i = 1;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_compare(str[j], str[i]) < 0)
			{
				aux = str[i];
				str[i] = str[j];
				str[j] = aux;
			}
			j++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	i;

	ft_order(argv, argc);
	i = 1;
	while (i < argc)
	{
		ft_putstr(argv[i]);
		i++;
	}
}
