/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 18:27:04 by migarcia          #+#    #+#             */
/*   Updated: 2021/04/22 20:01:51 by migarcia         ###   ########.fr       */
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

int	ft_base_len(char *base)
{
	int	i;

	i = 0;
	while (*base)
	{
		base++;
		i++;
	}
	return (i);
}

int	ft_atoi_base(char *str, char *base)
{
	int	mult;
	int	i;

	if (ft_checkbase(base) != 0)
	{
		mult = 1;
		i = 0;
		while (*str == ' ' || *str == '\t' || *str == '\r'
			|| *str == '\f' || *str == '\v' || *str == '\n')
			str++;
		while (*str == '-' || *str == '+')
		{
			if (*str == '-')
				mult *= -1;
			str++;
		}
		while (*str >= '0' && *str <= '9')
		{
			i *= ft_base_len(base);
			i += (*str - 'base');
			str++;
		}
		return (i * mult);
	}
	return (0);
}
