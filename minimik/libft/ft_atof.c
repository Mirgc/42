/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <migarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 18:40:38 by migarcia          #+#    #+#             */
/*   Updated: 2022/04/06 20:06:52 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

float	ft_atof(char **nptr)
{
	int	i;
	double	d;
	long	multi;

	multi = 1;
	if (**nptr == '-' || **nptr == '+')
	{
		if (**nptr == '-')
			multi = -1;
		(*nptr)++;
	}
	i = 0;
	while (**nptr >= 48 && **nptr <= 57)
	{
		i = i * 10 + **nptr - '0';
		(*nptr)++;
	}
	if (**nptr == '.')
		(*nptr)++;
	d = 0.0;
	while (**nptr >= 48 && **nptr <= 57)
	{
		d = d * 10 + **nptr - '0';
		(*nptr)++;
	}
	while (d >= 1)
		d /= 10;
	d += i;
	return (d * multi);
}
