/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 18:46:01 by migarcia          #+#    #+#             */
/*   Updated: 2021/10/23 10:12:44 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_str(char *s, int start, size_t len)
{
	char	*dst;
	int		i;

	dst = (char *) malloc(len * sizeof(char) + 1);
	if (!dst)
		return (NULL);
	if (!s)
	{
		free(dst);
		return (NULL);
	}
	if (start >= ft_len(s))
		return (dst);
	i = 0;
	while (len --)
	{
		dst[i] = s[start];
		i++;
		start++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*get_str(char *str, char **line, int filed)
{
	char	*dst;
	int		i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (i < ft_len(str))
	{
		*line = ft_str(str, 0, i);
		dst = ft_str(str, i + 1, ft_len(str));
		free (str);
		str = ft_dup(dst);
		free (dst);
	}
	else if (filed == 0)
	{
		*line = str;
		str = NULL;
	}
	return (str);
}

char	*ft_while(char *buff, char *str)
{
	char	*dst;

	if (str)
	{
		dst = join(str, buff);
		str = ft_dup(dst);
		free (dst);
	}
	else
	{
		if (buff)
			str = ft_dup(buff);
		else
			str = NULL;
	}
	return (str);
}

int	get_next_line(int fd, char **line)
{
	int			filed;
	static char	*str;
	char		*buff;

	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	filed = 1;
	while ((!(check_ch(str)) && filed != 0))
	{
		filed = read(fd, buff, BUFFER_SIZE);
		if (filed == -1)
		{
			free (buff);
			return (-1);
		}
		buff[filed] = '\0';
		str = ft_while(buff, str);
	}
	free(buff);
	str = get_str(str, line, filed);
	if (filed == 0 && !str)
		return (filed);
	return (1);
}
