/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <migarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 18:40:38 by migarcia          #+#    #+#             */
/*   Updated: 2021/06/02 19:11:03 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *nptr)
{
	long	i;
	long	multi;

	multi = 1;
	while (*nptr == ' ' || *nptr == '\t' || *nptr == '\n' || *nptr == '\r'
		|| *nptr == '\v' || *nptr == '\f')
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			multi = -1;
		nptr++;
	}
	i = 0;
	while (*nptr >= 48 && *nptr <= 57)
	{
		i *= 10;
		i += (*nptr - '0');
		nptr++;
	}
	return (i * multi);
}
