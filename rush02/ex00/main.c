/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamorin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 13:03:10 by aamorin-          #+#    #+#             */
/*   Updated: 2021/05/02 21:42:20 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_h.h"
#include <stdio.h>

unsigned int	ft_atoi(char *argv2)
{
	unsigned int	atoi_value;
	char			*c;

	c = argv2;
	atoi_value = 0;
	while (*c)
	{
		if (!(*c >= '0' && *c <= '9'))
			return (-1);
		c++;
	}	
	while (*argv2 >= '0' && *argv2 <= '9')
	{
		atoi_value = (*argv2 - '0') + (atoi_value * 10);
		argv2++;
	}
	return (atoi_value);
}

long long	ft_filter(char *argv2)
{
	int		i;
	int		uns_int_max_length;
	char	*uns_int_max;

	uns_int_max = "4294967295";
	uns_int_max_length = 10;
	i = 0;
	while (argv2[i] != '\0')
		i++;
	if (i > uns_int_max_length)
		return (-1);
	if (i == uns_int_max_length)
	{
		i = 0;
		while (argv2[i] != '\0')
		{
			if (argv2[i] < uns_int_max[i])
				return (ft_atoi(argv2));
			i++;
		}
		return (-1);
	}
	return (ft_atoi(argv2));
}

unsigned int	ft_valid(int argc, char **argv)
{
	long long		atoi_value;

	atoi_value = 0;
	if (argc == 2)
	{
		argv[2] = argv[1];
		argv[1] = "numbers.dict";
		atoi_value = ft_filter(argv[2]);
		if (atoi_value == -1)
			return (-1);
	}
	else
		return (-1);
	return (atoi_value);
}

int	main(int argc, char **argv)
{
	long long	val;
	int			iwrite;
	t_list		*tab;

	val = ft_valid(argc, argv);
	if (val == -1)
		write(1, "Error\n", 6);
	tab = ft_read_dict_file(DICT_NAME);
	iwrite = write_number(val, tab);
	if (iwrite == -1)
		write(1, "Error\n", 6);
	return (0);
}
