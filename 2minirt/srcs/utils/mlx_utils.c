/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osurcouf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 14:18:58 by osurcouf          #+#    #+#             */
/*   Updated: 2021/06/28 18:28:10 by osurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** 🦕
**
** function : a faster version of mlx_pixel_put from minilibX.
**
** Found this piece of code on the awesome 42Docs. Very good ressource
** if you're working on any graphic project from 42.
**
** -> https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html
**
** 🦕
*/

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_l + x * (img->bit_pix / 8));
	*(unsigned int *)dst = color;
}
