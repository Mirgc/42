/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_inver.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikgarci <mikgarci@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 16:32:22 by mikgarci          #+#    #+#             */
/*   Updated: 2022/02/18 18:59:24 by mikgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "algft.h"

static bool	ft_isinver_matrix(t_matrix a)
{
	if (ft_det_matrix(a))
		return (true);
	return (false);
}

t_matrix	ft_atta_matrix(t_matrix	a)
{
	int			y;
	int			x;
	t_matrix	b;
	
	b = ft_matrix(4, 4);
	y = 0;
	while (y < a.col)
	{
		x = 0;
		while (x < a.row)
		{
			b.m[y][x] = ft_cofac_matrix(a, x, y);
			x++;
		}
		y++;
	}
	return (b);
}

t_matrix	ft_inver_matrix(t_matrix a)
{
	t_matrix	b;

	b = ft_matrix(4, 4);
	if (!ft_isinver_matrix(a))
		return (a);
	b = ft_atta_matrix(a);
	return (ft_mult_matrix_f(b, 1 / ft_det_matrix(a)));
}

t_matrix	ft_iden_matrix(int row, int col)
{
	t_matrix	a;

	a = ft_matrix(row, col);
	a.m[0][0] = 1;
	a.m[1][1] = 1;
	a.m[2][2] = 1;
	a.m[3][3] = 1;
	return (a);
}
