/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikgarci <mikgarci@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 17:18:35 by mikgarci          #+#    #+#             */
/*   Updated: 2022/02/23 20:35:36 by mikgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "algft.h"

void	ft_error(char *str, int	i)
{
	printf("Error. %s\n", str);
	exit(i);
}

void	ft_print_tup(t_tuple tuple)
{
	if (tuple.w)
		printf("point ");
	else
		printf("vector ");
	printf("(%f %f %f)\n", tuple.x, tuple.y, tuple.z);
}

void	ft_print_matrix(t_matrix a)
{
	int	row;
	int	col;

	col = 0;
	while (col < a.col)
	{
		row = 0;
		while (row < a.row)
		{
			printf("%f ", a.m[col][row]);
			row++;
		}
		printf("\n");
		col++;
	}
}

void	ft_print_color(t_color c)
{
	printf("COLOR: r %f g %f b %f\n", c.r, c.g, c.b);
}

