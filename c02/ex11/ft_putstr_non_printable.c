/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <migarcia@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 19:04:46 by migarcia          #+#    #+#             */
/*   Updated: 2021/04/21 20:13:20 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	hex(int c)
{
	char	hex1;
	char	hex2;

	ft_putchar ('\\');
	if (c < 0)
		c += 256;
	hex1 = c / 16;
	hex2 = c % 16;
	if (hex1 < 10)
		ft_putchar (hex1 + '0');
	else
		ft_putchar (hex1 + 87);
	if (hex2 < 10)
		ft_putchar (hex2 + '0');
	else
		ft_putchar (hex2 + 87);
}

void	ft_putstr_non_printable(char *str)
{
	int		c;
	char	*cstr;

	c = 0;
	cstr = str;
	while (*cstr)
	{
		c = (int)*cstr;
		if (c < 32 || c == 127)
		{
			hex(c);
		}
		else
			ft_putchar (c);
		cstr++;
	}
}
