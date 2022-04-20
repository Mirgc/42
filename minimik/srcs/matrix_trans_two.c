/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_trans_two.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikgarci <mikgarci@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 02:37:26 by mikgarci          #+#    #+#             */
/*   Updated: 2022/02/23 20:46:05 by mikgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algft.h"

t_matrix	ft_put_matrix(t_tuple a, t_tuple b, t_tuple c)
{
	t_matrix m;

	m = ft_iden_matrix(4, 4);
	m.m[0][0] = a.x;
	m.m[0][1] = a.y;
	m.m[0][2] = a.z;
	m.m[1][0] = b.x;
	m.m[1][1] = b.y;
	m.m[1][2] = b.z;
	m.m[2][0] = c.x;
	m.m[2][1] = c.y;
	m.m[2][2] = c.z;
	return (m);
}

t_matrix	ft_view_trans(t_tuple from, t_tuple to, t_tuple up)
{
	t_tuple		forward;
	t_matrix	m;
	t_tuple		upn;
	t_tuple		left;
	t_tuple		true_up;

	forward = ft_norm_vec(ft_sub_tup(to, from));
	upn = ft_norm_vec(up);
	left = ft_cross_prod(forward, upn);
	true_up = ft_cross_prod(left, forward);
	m = ft_put_matrix(left, true_up, ft_neg_tup(forward));
	return (ft_mult_matrix(m, ft_transla_matrix(-1 * from.x, -1 * from.y, -1 * from.z)));
}

t_matrix	ft_shear_matrix(t_tuple b, t_tuple c)
{
	t_matrix	a;

	a = ft_iden_matrix(4, 4);
	a.m[1][0] = b.x;
	a.m[2][0] = b.y;
	a.m[0][1] = b.z;
	a.m[2][1] = c.x;
	a.m[0][2] = c.y;
	a.m[1][2] = c.z;
	return (a);
}
