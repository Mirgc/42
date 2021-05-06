/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 14:22:41 by migarcia          #+#    #+#             */
/*   Updated: 2021/04/26 13:54:17 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_calc_sqrt(int nb, int i)
{
	if (nb > 2147395600)
		return (0);
	if (i * i == nb)
		return (i);
	if (i * i < nb)
		return (ft_calc_sqrt(nb, i + 1));
	return (i);
}

int	ft_is_prime(int nb)
{
	int	i;
	int	j;
	int	aux;

	aux = 1;
	if (nb <= 1)
		return (0);
	else
	{
		i = 2;
		j = ft_calc_sqrt(nb, i);
		while (i < j)
		{
			aux = nb % i;
			if (aux == 0)
				return (0);
			i++;
		}
		return (1);
	}
}

int	ft_find_next_prime(int nb)
{
	int	i;

	i = 0;
	while (i == 0)
	{
		i = ft_is_prime(nb);
		if (i == 0)
			nb++;
	}
	return (nb);
}
