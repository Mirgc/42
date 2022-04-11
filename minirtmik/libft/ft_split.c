/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 09:01:14 by migarcia          #+#    #+#             */
/*   Updated: 2021/10/09 18:41:59 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_costr(char const *str, char c)
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

static char	**ft_clean(char **p, size_t count)
{
	size_t	i;

	if (p)
	{
		i = 0;
		while (i < count)
		{
			if (p[i] != NULL)
				free(p[i]);
			i++;
		}
		free (p);
	}
	return (NULL);
}

static char	*ft_intro(char const *s, char c)
{
	char	*str;
	int		i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	str = (char *) malloc((i + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != c)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static char	**ft_in_intro(char const *s, char c, char **tab)
{
	int	a;

	a = 0;
	while (*s)
	{
		while (*s && (*s == c))
			s++;
		if (*s && *s != c)
		{
			tab[a] = ft_intro(s, c);
			if (!tab[a])
				return (ft_clean(tab, a));
			a++;
			while (*s && *s != c)
				s++;
		}
	}
	tab[a] = NULL;
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	int		w;
	char	**tab;

	if (!s)
		return (NULL);
	w = ft_costr(s, c);
	tab = (char **) malloc((w + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	tab = ft_in_intro(s, c, tab);
	return (tab);
}
