/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_objs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osurcouf <.@student.42lisboa.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 18:22:30 by osurcouf          #+#    #+#             */
/*   Updated: 2021/06/30 16:38:41 by osurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** 🦕
**
** function : parsing the scene elements
**
**	1. Sphere ↷
**			sp point[x,y,z] [radius] [R,G,B]
**	2. Square ↷
**			sq point[x,y,z] orient[x,y,z] [side] [R,G,B]
**	3. Plane ↷
**			pl point[x,y,z] orient[x,y,z] [R,G,B]
**	4. Triangle ↷
**			tr point1[x,y,z] point2[x,y,z] point3[x,y,z] [R,G,B]
**	5. Cylinder ↷
**			cy point[x,y,z] orient[x,y,z] [height] [diameter] [R,G,B]
**
**	Note : orient[x,y,z] should be normalized (in range of -1, 1)
**	Note : [R,G,B] values should be between 0 and 255
**
** 🦕
*/

void	get_sphere(char *line, t_info *infos, int add_mem)
{
	t_obj		*obj;
	t_sphere	*sphere;

	if (add_mem)
		infos->objs = add_mem_obj(infos->nb_objs, infos->objs);
	if (!infos->objs)
		handle_error("💧	Fail to malloc sphere\n", infos);
	obj = &infos->objs[infos->nb_objs];
	obj->type = SPHERE;
	sphere = &obj->shape.sp;
	line = get_point(line, &sphere->point, infos);
	line = next_nbr(line, infos);
	line = pass_spaces(line, infos);
	sphere->radius = ft_atof(line);
	line = get_color(line, &obj->color, infos);
	verify_end_line(line, infos);
}

void	get_square(char *line, t_info *infos, int add_mem)
{
	t_obj		*obj;
	t_square	*square;

	if (add_mem)
		infos->objs = add_mem_obj(infos->nb_objs, infos->objs);
	if (!infos->objs)
		handle_error("💧	Fail to malloc square.\n", infos);
	obj = &infos->objs[infos->nb_objs];
	obj->type = SQUARE;
	square = &obj->shape.sq;
	line = get_point(line, &square->point, infos);
	line = next_nbr(line, infos);
	line = get_orient(line, &square->orient, infos);
	line = next_nbr(line, infos);
	line = pass_spaces(line, infos);
	square->orient = normalize(square->orient);
	square->side = ft_atof(line);
	line = get_color(line, &obj->color, infos);
	verify_end_line(line, infos);
}

void	get_plane(char *line, t_info *infos, int add_mem)
{
	t_obj	*obj;
	t_plane	*plane;

	if (add_mem)
		infos->objs = add_mem_obj(infos->nb_objs, infos->objs);
	if (!infos->objs)
		handle_error("💧	Fail to malloc plane.\n", infos);
	obj = &infos->objs[infos->nb_objs];
	obj->type = PLANE;
	plane = &obj->shape.pl;
	line = get_point(line, &plane->point, infos);
	line = next_nbr(line, infos);
	line = get_orient(line, &plane->orient, infos);
	plane->orient = normalize(plane->orient);
	line = get_color(line, &obj->color, infos);
	verify_end_line(line, infos);
}

void	get_triangle(char *line, t_info *infos, int add_mem)
{
	t_obj		*obj;
	t_triangle	*triangle;

	if (add_mem)
		infos->objs = add_mem_obj(infos->nb_objs, infos->objs);
	if (!infos->objs)
		handle_error("💧	Fail to malloc triangle.\n", infos);
	obj = &infos->objs[infos->nb_objs];
	obj->type = TRIANGLE;
	triangle = &obj->shape.tr;
	line = get_point(line, &triangle->point1, infos);
	line = next_nbr(line, infos);
	line = get_point(line, &triangle->point2, infos);
	line = next_nbr(line, infos);
	line = get_point(line, &triangle->point3, infos);
	line = get_color(line, &obj->color, infos);
	verify_end_line(line, infos);
}

void	get_cylinder(char *line, t_info *infos, int add_mem)
{
	t_obj		*obj;
	t_cylinder	*cylinder;
	t_vec		orient;

	if (add_mem)
		infos->objs = add_mem_obj(infos->nb_objs, infos->objs);
	if (!infos->objs)
		handle_error("💧	Fail to malloc cylinder.\n", infos);
	obj = &infos->objs[infos->nb_objs];
	obj->type = CYLINDER;
	cylinder = &infos->objs[infos->nb_objs].shape.cy;
	line = get_point(line, &cylinder->point, infos);
	line = next_nbr(line, infos);
	line = get_orient(line, &orient, infos);
	cylinder->orient = normalize(orient);
	line = next_nbr(line, infos);
	line = pass_spaces(line, infos);
	cylinder->height = ft_atof(line);
	line = next_nbr(line, infos);
	line = pass_spaces(line, infos);
	cylinder->radius = ft_atof(line) / 2;
	line = get_color(line, &obj->color, infos);
	verify_end_line(line, infos);
	get_caps(infos, *cylinder);
}
