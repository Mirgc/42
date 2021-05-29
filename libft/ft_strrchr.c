/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 18:36:48 by migarcia          #+#    #+#             */
/*   Updated: 2021/05/26 18:38:58 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *str, int c)
{
	char	ch;
	int		i;

	ch = (char)c;
	i = 0;
	while (*str)
	{
		str++;
		i++;
	}
	while (i != 0)
	{
		if (*str == ch)
			return ((char *)str);
		i--;
		str--;
	}
	return (0);
}
