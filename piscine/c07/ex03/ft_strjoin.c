/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 08:01:16 by migarcia          #+#    #+#             */
/*   Updated: 2021/04/29 16:19:47 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_lenstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_len(int size, char **strs, char *sep)
{
	int	i;
	int	len_sep;
	int	len_str;

	len_sep = 0;
	while (*sep)
	{
		len_sep++;
		sep++;
	}
	len_sep = len_sep * (size - 1);
	i = 0;
	len_str = 0;
	while (i < size)
	{
		len_str += ft_lenstr(strs[i]);
		i++;
	}
	return (len_sep + len_str);
}

char	*ft_strcat(char *dest, char *src)
{
	char	*chdest;
	char	*chsrc;

	chdest = dest;
	chsrc = src;
	while (*chdest)
	{
		chdest++;
	}
	while (*chsrc)
	{
		*chdest = *chsrc;
		chdest++;
		chsrc++;
	}
	*chdest = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*res;
	int		i;

	if (size == 0)
	{
		res = malloc(sizeof(char));
		return (res);
	}	
	else
	{
		res = malloc(sizeof(char) * ft_len(size, strs, sep));
		if (res == NULL)
			return (0);
		else
		{
			i = -1;
			while (++i < size)
			{
				ft_strcat(res, strs[i]);
				if (i + 1 < size)
					ft_strcat(res, sep);
			}
		}
	}
	return (res);
}
