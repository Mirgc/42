/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 08:00:45 by migarcia          #+#    #+#             */
/*   Updated: 2021/04/22 17:07:37 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h" 

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_putnbr(int nb)
{
	int	i;

	i = nb;
	if (i == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		i = 147483648;
	}
	if (i < 0)
	{
		ft_putchar('-');
		i *= -1;
	}
	if (i >= 10)
	{
		ft_putnbr(i / 10);
		ft_putnbr(i % 10);
	}
	else
		ft_putchar(i + '0');
}
