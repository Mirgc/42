/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iibanez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 11:50:40 by iibanez-          #+#    #+#             */
/*   Updated: 2021/05/04 08:36:57 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int	ft_validate_first_line(char *str, int l_start, int l_end)
{
	int	result;

	result = 0;
	if (str[l_end - 1] < 32 || str[l_end] == 127)
		return (-1);
	if (str[l_end - 2] < 32 || str[l_end] == 127)
		return (-1);
	if (str[l_end - 3] < 32 || str[l_end] == 127)
		return (-1);
	while (l_start < l_end - 3)
	{
		if (str[l_start] >= '0' && str[l_start] <= '9')
			result = result * 10 + (str[l_start] - '0');
		else
			return (-1);
		l_start++;
	}
	return (result);
}

struct s_map	*ft_parse_first_line(char *str, int l_start, int l_end)
{
	t_map			*map;
	unsigned int	length;

	if (l_end >= 4)
	{
		length = ft_validate_first_line(str, l_start, l_end);
		if (length > 0)
			map = set_map((unsigned int)length, str[l_end -3],
					str[l_end -2], str[l_end -1]);
		else
			map = set_error_map();
	}
	else
		map = set_error_map();
	return (map);
}

struct s_map	*ft_parse_str_to_map(char *str)
{
	t_map	*map;
	int		line_start;
	int		line_end;
	int		line_n;

	line_n = 0;
	line_end = 0;
	line_start = 0;
	while (str[line_end] != '\0')
	{
		if (str[line_end] == '\0' || str[line_end] == '\n')
		{
			if (line_n == 0)
				map = ft_parse_first_line(str, line_start, line_end);
			if (line_n > 0)
				map = ft_parse_lines(line_n, str, line_start, map);
			line_n++;
			line_start = line_end + 1;
			if (map->size == -1)
				return (map);
		}
		line_end++;
	}
	ft_parse_last_line(line_n, map);
	return (map);
}
