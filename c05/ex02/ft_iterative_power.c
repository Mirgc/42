/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 10:02:54 by migarcia          #+#    #+#             */
/*   Updated: 2021/04/26 10:58:03 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	aux;

	aux = 1;
	if (power == 0)
	{
		return (1);
	}
	else if (power < 0)
		return (0);
	while (power > 0)
	{
		aux *= nb;
		power --;
	}
	return (aux);
}
