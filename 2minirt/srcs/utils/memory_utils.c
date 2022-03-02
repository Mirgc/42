/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osurcouf <.@student.42lisboa.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 15:56:58 by osurcouf          #+#    #+#             */
/*   Updated: 2021/06/28 18:31:30 by osurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** 🦕
**
** function : Handles all memory-related utilities.
**
**	1. Initialize the global struct. Very important to
**		calloc (or bzero) the memory. Since we're dealing
**		with numbers and calculations the whole program.
**		You don't want lone weird numbers derailing 
**		everything !
**		- Only allocate memory for the size of the arrays
**			    -> (cameras, light, objects)
**	2. Add memory for lights, cameras, objects.
**		- Will copy the given array to a temporary one,
**			free the given one,
**			give it the same space + 1 element,
**			copy the temp back into it.
**		Note : it would be easier to handle the memory part
**			   with lists, but since we never move the objects 
**			   around and always access them in a row, it's
**			   much faster and easier to use an array in the
**			   program in general. Not sure what is best practice.
** 3. Delete memory - all allocated memory has to be freed :)
**
** 🦕
*/

int	init_objs(t_rt *rt)
{
	t_info	*init;

	rt->curr.obj.type = 0;
	rt->infos = ft_calloc(sizeof(t_info), 1);
	if (!rt->infos)
		return (no);
	init = rt->infos;
	init->nb_objs = 0;
	init->scene = ft_calloc(sizeof(t_scene), 1);
	if (!init->scene)
		return (no);
	init->scene->nb_cam = 0;
	init->scene->nb_light = 0;
	init->scene->cam = ft_calloc(sizeof(t_camera), 1);
	if (!init->scene->cam)
		return (no);
	init->scene->light = ft_calloc(sizeof(t_light), 1);
	if (!init->scene->light)
		return (no);
	init->objs = ft_calloc(sizeof(t_obj), 1);
	if (!init->objs)
		return (no);
	return (yes);
}

t_obj	*add_mem_obj(int nb_objs, t_obj *objs)
{
	t_obj	*temp;

	temp = (t_obj *)ft_calloc(sizeof(t_obj), nb_objs);
	if (!temp)
		return (NULL);
	ft_memcpy(temp, objs, (sizeof(t_obj) * nb_objs));
	free(objs);
	objs = (t_obj *)ft_calloc(sizeof(t_obj), nb_objs + 1);
	if (!objs)
		return (NULL);
	ft_memcpy(objs, temp, (sizeof(t_obj) * nb_objs));
	free(temp);
	return (objs);
}

t_camera	*add_mem_cam(int nb_cam, t_camera *cam)
{
	t_camera	*temp;

	temp = (t_camera *)ft_calloc(sizeof(t_camera), nb_cam);
	if (!temp)
		return (NULL);
	ft_memcpy(temp, cam, (sizeof(t_camera) * nb_cam));
	free(cam);
	cam = (t_camera *)ft_calloc(sizeof(t_camera), nb_cam + 1);
	if (!cam)
		return (NULL);
	ft_memcpy(cam, temp, (sizeof(t_camera) * nb_cam));
	free(temp);
	return (cam);
}

t_light	*add_mem_light(int nb_light, t_light *light)
{
	t_light	*temp;

	temp = (t_light *)ft_calloc(sizeof(t_light), nb_light);
	if (!temp)
		return (NULL);
	ft_memcpy(temp, light, (sizeof(t_light) * nb_light));
	free(light);
	light = (t_light *)ft_calloc(sizeof(t_light), nb_light + 1);
	if (!light)
		return (NULL);
	ft_memcpy(light, temp, (sizeof(t_light) * nb_light));
	free(temp);
	return (light);
}

void	del_mem_infos(t_info *infos)
{
	if (infos->scene->cam)
		free(infos->scene->cam);
	if (infos->scene->light)
		free(infos->scene->light);
	if (infos->scene)
		free(infos->scene);
	if (infos->objs)
		free(infos->objs);
	if (infos)
		free((void *)infos);
}
