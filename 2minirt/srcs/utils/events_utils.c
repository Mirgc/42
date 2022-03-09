/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_minirt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osurcouf <.@student.42lisboa.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 18:29:19 by osurcouf          #+#    #+#             */
/*   Updated: 2021/06/28 18:25:01 by osurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** 🦕
**
** function : Events in miniRT
**
**	1. Exit & Free
**		- Click on the cross on top of the window
**			and it will close all nice and pretty.
**	2. Change_cam
**		- By pressing the left or right arrow, you
**			can naviguate from one cam to the other.
**
**	Note : I want to make more events.
**			- Rotate camera (keyboard)
**			- Select & Move object (mouse)
**
** 🦕
*/

int	exit_and_free(t_rt *rt)
{
	printf("\n"COLOR_YELLOW"	👋 Bye bye 👋\n\n");
	del_mem_infos(rt->infos);
	mlx_clear_window(rt->mlx, rt->win);
	mlx_destroy_window(rt->mlx, rt->win);
	exit(EXIT_SUCCESS);
}

static void	change_cam(t_rt *rt, int curr_cam)
{
	rt->curr.cam = rt->infos->scene->cam[curr_cam];
	create_img(rt);
	if (curr_cam == rt->infos->scene->nb_cam - 1)
		printf("	🎥 Last Camera\n");
	else if (curr_cam == 0)
		printf("	🎥 First Camera\n");
}

int	events(int keycode, t_rt *rt)
{
	static int	curr_cam = 0;

	if (keycode == KEY_ESC)
		exit_and_free(rt);
	if (rt->infos->scene->nb_cam > 1)
	{
		if (keycode == KEY_RIGHT && curr_cam < rt->infos->scene->nb_cam - 1)
			curr_cam++;
		else if (keycode == KEY_LEFT && curr_cam > 0)
			curr_cam--;
		else
			return (EXIT_SUCCESS);
		change_cam(rt, curr_cam);
	}
	return (EXIT_SUCCESS);
}
