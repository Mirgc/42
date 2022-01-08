/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <migarcia@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 16:36:59 by migarcia          #+#    #+#             */
/*   Updated: 2021/04/18 11:43:38 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_comb(void)
{
	char	i;
	char	j;
	char	k;

	i = '0' - 1;
	while (i++ < '7')
	{
		j = i;
		while (j++ < '8')
		{
			k = j;
			while (k++ < '9')
			{
				ft_putchar (i);
				ft_putchar (j);
				ft_putchar (k);
				if (i != '7' || j != '8' || k != '9')
				{
					ft_putchar (',');
					ft_putchar (' ');
				}
			}
		}
	}
}
