/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_det.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikgarci <mikgarci@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 18:14:44 by mikgarci          #+#    #+#             */
/*   Updated: 2022/02/17 16:53:44 by mikgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algft.h"

t_matrix	ft_sub_matrix(t_matrix a, int row, int col)
{
	int			i;
	int			j;
	int			x;
	int			y;
	t_matrix	b;

	b = ft_matrix(a.row - 1, a.col - 1);
	i = 0;
	y = 0;
	while (i < a.col)
	{
		x = 0;
		j = 0;
		while (j < a.row)
		{
			if (j != col && i != row)
				b.m[y][x++] = a.m[i][j];
			j++;
		}
		if (i != row)
			y++;
		i++;
	}
	return (b);
}

float	ft_minor_matrix(t_matrix a, int row, int col)
{
	t_matrix	b;
	float		min;

	b = ft_sub_matrix(a, row, col);
	min = ft_det_matrix(b);
	return (min);
}

float	ft_cofac_matrix(t_matrix a, int row, int col)
{
	float	min;

	min = ft_minor_matrix(a, row, col);
	if ((row + col) % 2)
		return (min * -1);
	return (min);
}

float	ft_det_matrix(t_matrix a)
{
	float	det;
	int		i;

	det = 0;
	if (a.row == 2 && a.col == 2)
		det = (a.m[0][0] * a.m[1][1]) - (a.m[0][1] * a.m[1][0]);
	else
	{
		i = 0;
		while (i < a.row)
		{
			det += a.m[0][i] * ft_cofac_matrix(a, 0, i);
			i++;
		}
	}
	return (det);
}
