/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_trans.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikgarci <mikgarci@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 18:36:12 by mikgarci          #+#    #+#             */
/*   Updated: 2022/02/10 20:45:48 by mikgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algft.h"
#include <math.h>

t_matrix	ft_transla_matrix(float x, float y, float z)
{
	t_matrix	a;

	a = ft_iden_matrix(4, 4);
	a.m[0][3] = x;
	a.m[1][3] = y;
	a.m[2][3] = z;
	return (a);
}

t_matrix	ft_scal_matrix(float x, float y, float z)
{
	t_matrix	a;

	a = ft_iden_matrix(4, 4);
	a.m[0][0] = x;
	a.m[1][1] = y;
	a.m[2][2] = z;
	return (a);
}

t_matrix	ft_rotate_x_matrix(float x)
{
	t_matrix	a;

	a = ft_iden_matrix(4, 4);
	a.m[1][1] = cos(x);
	a.m[2][1] = sin(x);
	a.m[1][2] = -1 * sin(x);
	a.m[2][2] = cos(x);
	return (a);
}

t_matrix	ft_rotate_y_matrix(float x)
{
	t_matrix	a;

	a = ft_iden_matrix(4, 4);
	a.m[0][0] = cos(x);
	a.m[2][0] = -1 * sin(x);
	a.m[0][2] = sin(x);
	a.m[2][2] = cos(x);
	return (a);
}

t_matrix	ft_rotate_z_matrix(float x)
{
	t_matrix	a;

	a = ft_iden_matrix(4, 4);
	a.m[0][0] = cos(x);
	a.m[0][1] = -1 * sin(x);
	a.m[1][0] = sin(x);
	a.m[1][1] = cos(x);
	return (a);
}
