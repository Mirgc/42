/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikgarci <mikgarci@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 17:18:35 by mikgarci          #+#    #+#             */
/*   Updated: 2022/04/05 19:27:27 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "../includes/algft.h"

int	ft_error(char *str)
{
	printf("%s\n", str);
	return (1);
}

void	ft_exit(char *str, int	i)
{
	printf("%s\n", str);
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

