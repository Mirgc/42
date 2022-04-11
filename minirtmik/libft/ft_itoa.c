/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 09:38:33 by migarcia          #+#    #+#             */
/*   Updated: 2021/10/09 18:46:45 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_cowords(long n)
{
	int	co;

	co = 0;
	if (n < 0)
	{
		n *= -1;
		co++;
	}
	while (n > 9)
	{
		n /= 10;
		co++;
	}
	return (co);
}

char	*ft_itoa(int n)
{
	char	*nbr;
	int		co;
	long	ln;

	ln = n;
	co = ft_cowords(ln);
	nbr = (char *) malloc(co * sizeof(char) + 1);
	if (!nbr)
		return (NULL);
	if (ln == 0)
	{
		nbr[0] = '0';
		return (nbr);
	}
	if (ln < 0)
	{
		nbr[0] = '-';
		ln *= -1;
	}
	while (ln > 0)
	{
		nbr[co--] = ln % 10 + '0';
		ln /= 10;
	}
	return (nbr);
}
