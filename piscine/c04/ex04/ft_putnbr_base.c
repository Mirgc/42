/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 12:24:05 by migarcia          #+#    #+#             */
/*   Updated: 2021/04/22 17:51:00 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_checkbase(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		j = i + 1;
		if (base[i] == '+' || base[i] == '-' || base [i] <= 31)
			return (0);
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	if (i <= 1)
		return (0);
	else
		return (i);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	len;

	len = ft_checkbase(base);
	if (len != 0)
	{
		if (nbr < 0)
		{
			write (1, "-", 1);
			nbr *= -1;
		}
		if (nbr >= len)
		{
			ft_putnbr_base(nbr / len, base);
			ft_putnbr_base(nbr % len, base);
		}
		else
			write(1, base + nbr, 1);
	}
}
