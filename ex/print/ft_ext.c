/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ext.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 15:20:35 by migarcia          #+#    #+#             */
/*   Updated: 2021/09/16 13:57:55 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str_arg)
{
	int	c_count;

	c_count = 0;
	if (!str_arg)
		str_arg = "(null)";
	while (*str_arg)
	{
		c_count += ft_putchar(*str_arg);
		str_arg++;
	}
	return (c_count);
}

int	ft_len(long long num, int base)
{
	int	len;

	len = 0;
	if (num == 0)
		return (1);
	if (num < 0)
		len++;
	while (num != 0)
	{
		num /= base;
		len++;
	}
	return (len);
}

int	ft_putnbr(long num)
{
	int	c_count;

	c_count = 0;
	if (num == -2147483648)
	{
		c_count += ft_putstr("-2");
		num = 147483648;
	}
	if (num < 0)
	{
		c_count += ft_putchar('-');
		num *= -1;
	}
	if (num >= 10)
	{
		ft_putnbr(num / 10);
		ft_putnbr(num % 10);
	}
	else
		ft_putchar(num + '0');
	c_count += ft_len(num, 10);
	return (c_count);
}

int	ft_puthex(unsigned long long num, int c_count)
{
	int			tmp;
	static int	c_sta;

	c_sta = 0;
	if (num == 0 && (c_count == 0 || c_count == 2))
		c_sta += ft_putchar('0');
	if (num > 0)
	{
		c_count = 1;
		ft_puthex(num / 16, c_count);
		tmp = num % 16;
		if (tmp > 9)
			c_sta += ft_putchar((tmp - 10) + 'a');
		else
			c_sta += ft_putchar(tmp + '0');
	}
	return (c_sta);
}
