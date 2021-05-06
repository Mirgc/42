/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combi2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <migarcia@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 18:11:54 by migarcia          #+#    #+#             */
/*   Updated: 2021/04/17 09:01:52 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_print_comb2(void)
{
	int	a;
	int	b;

	a = -1;
	while (a++ <= 98)
	{
		b = a;
		while (b++ < 99)
		{
			ft_putchar((char)(a / 10 + '0'));
			ft_putchar((char)(a % 10 + '0'));
			ft_putchar(' ');
			ft_putchar((char)(b / 10 + '0'));
			ft_putchar((char)(b % 10 + '0'));
			if (a != 98)
			{
				write (1, ", ", 2);
			}
		}
	}
}
