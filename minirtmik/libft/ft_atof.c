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

int	ft_atof(const char *nptr)
{
	int	i;
	double	d;
	long	multi;

	multi = 1;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			multi = -1;
		nptr++;
	}
	i = 0;
	while (*nptr >= 48 && *nptr <= 57)
		i = i * 10 + (*((*nptr)++) - '0');
	if (*nptr == '.')
		nptr++;
	d = 0.0;
	while (*nptr >= 48 && *nptr <= 57)
		d = d * 10 + (*((*nptr)++) - '0');
	while (d >= 1)
		d /= 10;
	d += i;
	return (d * multi);
}
