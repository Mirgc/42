/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 09:01:14 by migarcia          #+#    #+#             */
/*   Updated: 2021/05/29 11:15:30 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
int	ft_costr(char const *str, char c)
{
	int	count;

	count = 0;
	while (*str)
	{
		while (*str && (*str == c))
			str++;
		if (*str && *str != c)
		{
			count ++;
			while (*str && *str != c)
				str++;
		}
	}
	return (count);
}

char	*ft_intro(char const *s, char c)
{
	char	*str;
	int		i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	str = (char *) malloc((i + 1) * sizeof(char));
	if (!str)
		return (0);
	i = 0;
	while (s[i] && s[i] != c)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	**ft_split(char const *s, char c)
{
	int		w;
	int		a;
	char	**tab;

	if (!s)
		return (NULL);
	w = ft_costr(s, c);
	tab = (char **) malloc((w + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	a = 0;
	while (*s)
	{
		while (*s && (*s == c))
			s++;
		if (*s && *s != c)
		{
			tab[a] = ft_intro(s, c);
			a++;
			while (*s && *s != c)
				s++;
		}
	}
	tab[a] = NULL;
	return (tab);
}
