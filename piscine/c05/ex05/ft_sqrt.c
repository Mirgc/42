/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 12:40:51 by migarcia          #+#    #+#             */
/*   Updated: 2021/04/23 14:20:32 by migarcia         ###   ########.fr       */
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
	return (0);
}

int	ft_sqrt(int nb)
{
	return (ft_calc_sqrt(nb, 0));
}
