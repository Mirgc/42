/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lights.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikgarci <mikgarci@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 03:06:17 by mikgarci          #+#    #+#             */
/*   Updated: 2022/03/03 17:50:49 by mikgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algft.h"

t_light	ft_point_light(t_tuple pos, t_color y)
{
	t_light	a;

	a.pos = ft_point(pos.x, pos.y, pos.z);
	a.i = ft_color(y.r, y.g, y.b);
	return (a);
}
