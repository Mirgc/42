/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 17:06:19 by migarcia          #+#    #+#             */
/*   Updated: 2021/09/30 17:06:23 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int check_ch(char *str)
{
	int i;

	i = 0;
	if (!str)
		return(0);
	while(str[i])
	{
		if(str[i] == '\n' || str[i] == '\0')
			return (1);
		i++;
	}
	return (0);
}

char *ft_aux(char *line, char c)
{
	char *str;
	int i;

	i = 0;
	while(line[i])
		i++;
	str = (char *)malloc(2 + i);
	if(!str)
		return(NULL);
	i = 0;
	while(line[i])
	{
		str[i] = line[i];
		i++;
	}
	str[i] = c;
	str[i + 1] = '\0';
	free(line);
	return(str);
}

char *get_next_line(int fd)
{
	char *line;
	char buff;
	int filed;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = malloc(1);
	if (!line)
		return (NULL);
	line[0] = '\0';
	filed = 1;
	while (!(check_ch(line)) && filed != 0)
	{
		filed = read(fd, &buff, 1);
		if (filed == 0)
		{
			if (line[0] == '\0')
			{
				free(line);
				return (NULL);
			}
			return (line);
		}
		if (filed < 0)
		{
			free(line);
			return (NULL);
		}
		line = ft_aux(line, buff);
	}
	return (line);
}
