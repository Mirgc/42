/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 09:38:33 by migarcia          #+#    #+#             */
/*   Updated: 2021/05/29 10:07:01 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_cowords(int n)
{
	int	co;

	co = 0;
	if (n < 0)
	{
		n *= -1;
		co++;
	}
	while (n > 0)
	{
		n /= 10;
		co++;
	}
	return (co);
}
char *ft_itoa(int n)
{
	char	*nbr;
	int		co;

	co = ft_cowords(n);
	nbr = (char *) malloc(co * sizeof(char) + 1);
	if (!nbr)
		return (NULL);
	if ( n < 0)
	{
		nbr[0] = '-';
		n *= -1;
	}
	while (n > 0)
	{
		nbr[co--] = n % 10 + '0';
		n /= 10; 
		printf("==%i, %i, %c\n", n, co, nbr[co]);
	}
	return (nbr);
}
