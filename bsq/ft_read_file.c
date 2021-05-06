/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 20:03:01 by migarcia          #+#    #+#             */
/*   Updated: 2021/05/04 20:03:09 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void	ft_strcat(char *str, char *read)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
		i++;
	while (read[j] != '\0')
	{
		str[i] = read[j];
		i++;
		j++;
	}
	str[i] = '\0';
}

unsigned int	ft_get_size(char *f_table)
{
	int		countreads;
	int		re;
	int		fd;
	char	fstr[BUFF];

	countreads = 0;
	fd = open(f_table, O_RDONLY);
	if (fd == -1)
		return (-1);
	re = read(fd, fstr, BUFF);
	while (re > 0)
	{
		re = read(fd, fstr, BUFF);
		countreads++;
	}
	close (fd);
	return (countreads);
}

void	ft_ini_str(char *str)
{
	int	k;

	k = 0;
	while (k < BUFF)
	{
		str[k] = '\0';
		k++;
	}
}

char	*ft_read_file(char *argv)
{
	int		reads;
	char	f_str[BUFF];
	char	*str;
	int		fd;
	int		re;

	ft_ini_str(f_str);
	reads = ft_get_size(argv);
	str = malloc(sizeof(char) * (BUFF * reads));
	if (str == NULL)
		return (NULL);
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		return (NULL);
	re = read(fd, f_str, BUFF);
	while (re > 0)
	{
		ft_strcat(str, f_str);
		ft_ini_str(f_str);
		re = read(fd, f_str, BUFF);
	}
	close(fd);
	return (str);
}

void	ft_printf_dia(t_map *map)
{
	int i;
	int	j;
	
	i = 0;
	while (i < map->size)
	{
		j = 0;
		while (j < map->size)
		{
			printf("%i ", map->tab[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}
