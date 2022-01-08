/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 11:41:32 by migarcia          #+#    #+#             */
/*   Updated: 2021/05/02 21:43:21 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_h.h"

char	*ft_strcpy(char *c, int f_pos, int l_pos)
{
	int		i;
	char	*dest;

	i = f_pos;
	while (i < l_pos)
		i++;
	dest = malloc(sizeof(char) * i + 1);
	if (dest == NULL)
		return (0);
	else
	{
		i = 0;
		while (f_pos < l_pos)
		{
			if ((c[f_pos] == ' ' && c[f_pos + 1] == ' '))
				f_pos++;
			dest[i] = c[f_pos];
			i++;
			f_pos++;
			if (c[f_pos] == '\n')
				f_pos++;
		}
		dest[f_pos] = '\0';
		return (dest);
	}
}

int	ft_atoi_line(char *dictionary, int f_pos)
{
	int	mult;
	int	i;
	int	j;

	mult = 1;
	i = 0;
	j = -1;
	while (dictionary[f_pos] == ' ')
		f_pos++;
	if (dictionary[f_pos] == '-' || dictionary[f_pos] == '+')
	{
		if (dictionary[f_pos] == '-')
			mult *= -1;
		f_pos++;
	}
	while (dictionary[f_pos] >= '0' && dictionary[f_pos] <= '9')
	{
		j = 0;
		i *= 10;
		i += (dictionary[f_pos] - '0');
		f_pos++;
	}
	if (j == -1)
		return (-1);
	return (i * mult);
}

int	ft_parse_line(char *dictionary, t_list *tab, int *pos, int line)
{
	int		i;
	int		f_pos;
	int		l_pos;
	char	*dstr;

	dstr = dictionary;
	i = 0;
	f_pos = pos[0];
	l_pos = pos[1] + 1;
	if (f_pos + 1 == l_pos)
		return (-1);
	tab[line].nb = ft_atoi_line(dstr, f_pos);
	if (tab[line].nb == -1)
		return (-1);
	while (dstr[f_pos] != ':')
		f_pos++;
	f_pos++;
	while (dstr[f_pos] <= 32)
		f_pos++;
	tab[line].str = ft_strcpy(dstr, f_pos, l_pos);
	return (0);
}

void	ft_lines(char *dictionary, t_list *tab)
{
	int		pos[2];
	int		line;
	int		val;
	char	*dstr2;

	dstr2 = dictionary;
	pos[0] = 0;
	pos[1] = 0;
	line = 0;
	while (*dictionary)
	{
		if (*dictionary == '\n')
		{
			val = ft_parse_line(dstr2, tab, pos, line);
			if (val == 0)
				line++;
			pos[0] = pos[1] + 1;
		}
		pos[1]++;
		dictionary++;
	}
}

struct	s_list	*ft_parse(char *dictionary)
{
	t_list	*tab;
	int		lines;
	char	*dstr;

	dstr = dictionary;
	lines = 0;
	while (*dictionary)
	{
		if (*dictionary == '\n')
			lines++;
		dictionary++;
	}
	tab = malloc(sizeof(t_list) * lines + 1);
	if (tab == NULL)
		return (NULL);
	else
	{
		ft_lines(dstr, tab);
	}
	return (tab);
}
