/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_scene.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osurcouf <.@student.42lisboa.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 18:22:37 by osurcouf          #+#    #+#             */
/*   Updated: 2021/06/30 17:06:47 by osurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** 🦕
** MiniRT Program
**
** function : parsing the scene elements
**
**	1. Resolution ↷
**			R [x] [y]
**	2. Ambient ↷
**			A [ratio] [R,G,B]
**	3. Lights ↷
**			l point[x,y,z] [brightness] [R,G,B]
**	4. Cameras ↷
**			c point[x,y,z] orient[x,y,z] [FOV]
**
**	Note : orient[x,y,z] should be normalized (in range of -1, 1)
**		   [R,G,B] values should be between 0 and 255
**		   Resolution's [x] & [y] should be integers > 0
**		   [ratio] and [brightness] should be between 0 and 1
**		   [FOV] should be an integer
**
** 🦕
*/

void	get_res(char *line, t_info *infos)
{
	t_res	*res;

	res = &infos->scene->res;
	line = pass_spaces(line, infos);
	res->x = ft_atoi(line);
	line = next_int(line, infos);
	line = pass_spaces(line, infos);
	res->y = ft_atoi(line);
	line = next_int(line, infos);
	if (res->x <= 0 || res->y <= 0)
		handle_error("📏	Careful, resolution should be greater than 0.\n",
			infos);
	verify_end_line(line, infos);
}

void	get_amb(char *line, t_info *infos)
{
	t_ambient	*amb;

	amb = &infos->scene->amb;
	amb->r = ft_atof(line);
	if (amb->r < 0.0 || amb->r > 1.0)
		handle_error("☁️	Ambient ratio should be between 0.0 and 1.0.\n",
			infos);
	line = pass_spaces(line, infos);
	line = get_color(line, &amb->color, infos);
	verify_end_line(line, infos);
}

void	get_light(char *line, t_info *infos, int add_mem)
{
	int		current;
	t_scene	*scene;

	scene = infos->scene;
	current = scene->nb_light;
	if (add_mem)
		scene->light = add_mem_light(scene->nb_light, scene->light);
	line = get_point(line, &scene->light[current].point, infos);
	line = next_nbr(line, infos);
	line = pass_spaces(line, infos);
	scene->light[current].bright = ft_atof(line);
	if (scene->light[current].bright < 0.0
		|| scene->light[current].bright > 1.0)
		handle_error("💡	Light brightness should be between 0.0 and 1.0.\n",
			infos);
	line = get_color(line, &scene->light[current].color, infos);
	verify_end_line(line, infos);
}

void	get_cam(char *line, t_info *infos, int add_mem)
{
	int		current;
	t_scene	*scene;

	scene = infos->scene;
	current = scene->nb_cam;
	if (add_mem)
		scene->cam = add_mem_cam(scene->nb_cam, scene->cam);
	line = get_point(line, &scene->cam[current].point, infos);
	line = next_nbr(line, infos);
	line = get_orient(line, &scene->cam[current].orient, infos);
	scene->cam[current].orient = normalize(scene->cam[current].orient);
	line = next_nbr(line, infos);
	line = pass_spaces(line, infos);
	scene->cam[current].FOV = ft_atoi(line);
	if (scene->cam[current].FOV < 0 || scene->cam[current].FOV > 180)
		handle_error("📐	FOV should be in range 0 to 180.\n", infos);
	line = next_int(line, infos);
	verify_end_line(line, infos);
}
