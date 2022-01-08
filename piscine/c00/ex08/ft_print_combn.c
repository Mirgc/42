/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <migarcia@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 08:20:52 by migarcia          #+#    #+#             */
/*   Updated: 2021/04/18 11:13:03 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print(int *r, int n)
{
	int	i;

	i = 0;
	while (++i < n)
		if (r[i - 1] >= r[i])
			return ;
	i = -1;
	while (++i < n)
		ft_putchar(r[i] + '0');
	if (r[0] < (10 - n))
	{
		write(1, ", ", 2);
	}
}

void	ft_print_combn(int n)
{
	int	i;
	int	r[10];

	if (n > 10 || n < 0)
		return ;
	i = -1;
	while (++i < n)
		r[i] = i;
	while (r[0] <= (10 - n))
	{
		print(r, n);
		if (n == 10)
			break ;
		r[n - 1]++;
		i = n;
		while (i && n > 1)
		{
			i--;
			if (r[i] > 9)
			{
				r[i - 1]++;
				r[i] = 0;
			}
		}
	}
}
