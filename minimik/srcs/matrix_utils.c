/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikgarci <mikgarci@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 20:33:18 by mikgarci          #+#    #+#             */
/*   Updated: 2022/02/14 18:07:10 by mikgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algft.h"

t_matrix	ft_matrix(int row, int column)
{
	t_matrix	a;
	int			x;
	int			y;

	a.row = row;
	a.col = column;
	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			a.m[y][x] = 0.0;
			x++;
		}
		y++;
	}
	return (a);
}

t_matrix	ft_mult_matrix(t_matrix a, t_matrix b)
{
	t_matrix	c;
	int			x;
	int			y;
	int			len;

	c = ft_matrix(a.row, b.col);
	y = 0;
	while (y < b.col)
	{
		x = 0;
		while (x < a.row)
		{
			len = 0;
			while (len < a.col)
			{
				c.m[y][x] += a.m[y][len] * b.m[len][x];
				len++;
			}
			x++;
		}
		y++;
	}
	return (c);
}

t_matrix	ft_mult_matrix_f(t_matrix a, float w)
{
	t_matrix	b;
	int			x;
	int			y;

	b = ft_matrix(a.row, a.col);
	y = 0;
	while (y < a.col)
	{
		x = 0;
		while (x < a.row)
		{
			b.m[y][x] = a.m[y][x] * w;
			x++;
		}
		y++;
	}
	return (b);
}

t_tuple	ft_mult_matrix_tup(t_matrix a, t_tuple b)
{
	t_tuple	c;

	c.x = a.m[0][0] * b.x + a.m[0][1] * b.y + a.m[0][2] * b.z + a.m[0][3] * b.w;
	c.y = a.m[1][0] * b.x + a.m[1][1] * b.y + a.m[1][2] * b.z + a.m[1][3] * b.w;
	c.z = a.m[2][0] * b.x + a.m[2][1] * b.y + a.m[2][2] * b.z + a.m[2][3] * b.w;
	c.w = a.m[3][0] * b.x + a.m[3][1] * b.y + a.m[3][2] * b.z + a.m[3][3] * b.w;
	return (c);
}

t_matrix	ft_trans_matrix(t_matrix a)
{
	t_matrix	b;
	int			i;

	b = ft_matrix(a.row, a.col);
	i = 0;
	while (i < 4)
	{
		b.m[i][0] = a.m[0][i];
		b.m[i][1] = a.m[1][i];
		b.m[i][2] = a.m[2][i];
		b.m[i][3] = a.m[3][i];
		i++;
	}
	return (b);
}
