/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 18:36:48 by migarcia          #+#    #+#             */
/*   Updated: 2021/05/31 17:42:57 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *str, int c)
{
	int		i;

	i = 0;
	while (*str)
	{
		str++;
		i++;
	}
	if (c == 0)
		return ((char *)str);
	while (i >= 0)
	{
		if (*str == c)
			return ((char *)str);
		i--;
		str--;
	}
	return (0);
}
