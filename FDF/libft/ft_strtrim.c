/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 17:21:48 by migarcia          #+#    #+#             */
/*   Updated: 2021/10/09 18:40:19 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

static int	ft_check_ch(char c, char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_check_start(char const *s1, char const *set)
{
	int	a;

	a = 0;
	while (s1[a])
	{
		if (ft_check_ch((char)s1[a], (char *)set) == 0)
			break ;
		a++;
	}
	return (a);
}

static int	ft_check_end(char const *s1, char const *set, int lenend)
{
	int	b;

	b = 0;
	while (lenend > 0)
	{
		if (ft_check_ch((char)s1[lenend], (char *)set) == 0)
			break ;
		lenend--;
		b++;
	}
	return (lenend);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*dst;
	int		len;
	int		lenend;
	int		a;

	if (!s1 || !set)
		return (NULL);
	len = ft_strlen(set);
	lenend = ft_strlen(s1) - 1;
	a = ft_check_start(s1, set);
	if (a == lenend + 1)
		return (ft_substr(s1, 0, 0));
	lenend = ft_check_end(s1, set, lenend);
	if (lenend <= 0)
		lenend = 1;
	lenend = (lenend - a) + 1;
	dst = ft_substr(s1, a, lenend);
	return (dst);
}
