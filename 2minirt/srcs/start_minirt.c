/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osurcouf <.@student.42lisboa.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 17:55:35 by osurcouf          #+#    #+#             */
/*   Updated: 2021/06/30 17:19:05 by osurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** 🦕
**
** function : Starts miniRT
**  1. Checks for errors
**		- Resolution 0 on one side
**		- No cameras
** 2. Creates the window with minilibX
** 3. Create the image in the window
		- Handles events (keyboard, mouse...)
** 4. Render miniRT
**		- Iterates through each pixel to determine which color
**		  it will have in the window.
**		- First, generate the ray from the camera to the scene.
**		- Then, determine if it hits an object on the way and
**		  which is closest.
**		- Then get the actual color by calculating the light
**		  the object gets, what color the object will be, and
**		  if it's in the shadows or not.
**		- Finally, put the pixel's color on the screen !
**	5. Loop (so it keeps appearing and updating) thanks to
**	   mlx_loop.
**
** 🦕
*/

static void	render_minirt(t_rt *rt)
{
	int		x;
	int		y;
	t_scene	*scene;

	scene = rt->infos->scene;
	y = 0;
	x = 0;
	while (y < scene->res.y)
	{
		x = 0;
		while (x < scene->res.x)
		{
			gen_cam_ray(x, y, rt);
			check_if_it_hits_object(rt);
			get_pixel_color(rt);
			my_mlx_pixel_put(&rt->img, x, y, rt->curr.pix_color);
			x++;
		}
		y++;
	}
}

void	create_img(t_rt *rt)
{
	render_minirt(rt);
	mlx_hook(rt->win, DESTROY, 0, exit_and_free, rt);
	mlx_key_hook(rt->win, events, rt);
	if (rt->infos->nb_objs == no)
	{
		printf(COLOR_YELLOW"	Fair warning ✋\n");
		printf(COLOR_WHITE"	This program is cooler with objects 🪑 🛀\n");
	}
	mlx_put_image_to_window(rt->mlx, rt->win, rt->img.ptr, 0, 0);
}

static void	create_window(t_rt *rt)
{
	t_res	*res;
	int		screen_width;
	int		screen_height;

	res = &rt->infos->scene->res;
	rt->mlx = mlx_init();
	screen_width = 1920;
	screen_height = 1080;
	if (OS_APPLE == yes)
		mlx_get_screen_size(rt->mlx, &screen_width, &screen_height);
	if (res->x > screen_width)
		res->x = screen_width;
	if (res->y > screen_height)
		res->y = screen_height;
	rt->win = mlx_new_window(rt->mlx, res->x, res->y, "miniRT");
	rt->img.ptr = mlx_new_image(rt->mlx, res->x, res->y);
	rt->img.addr = mlx_get_data_addr(rt->img.ptr, &rt->img.bit_pix,
			&rt->img.line_l, &rt->img.endian);
	return ;
}

void	start_minirt(t_rt *rt)
{
	if (rt->infos->scene->nb_cam == 0)
		handle_error("🎥	There are no cameras.\n", rt->infos);
	else
		rt->curr.cam = rt->infos->scene->cam[0];
	printf("\n	" COLOR_LIGHT_CYAN "🖼️  Starting miniRT 🖼️\n\n" COLOR_END);
	if (rt->infos->scene->nb_cam > 1)
	{
		printf(COLOR_WHITE"	["COLOR_LIGHT_PURPLE"INSTRUCTIONS"COLOR_WHITE"]\n");
		printf("🎥	[To Change Cameras] : Press <- or ->\n" COLOR_END);
	}
	create_window(rt);
	create_img(rt);
	mlx_loop(rt->mlx);
}
