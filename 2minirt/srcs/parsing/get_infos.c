/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_infos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osurcouf <.@student.42lisboa.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 18:22:44 by osurcouf          #+#    #+#             */
/*   Updated: 2021/06/30 17:15:30 by osurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** 🦕
**
** function : Parse the scene and get all the informations stored.
**
**	1. Open the scene.rt file.
**	2. Initialize the t_rt structure. Put all values to 0 and malloc
**		the arrays.
**	3. Parse one line at a time. (Not the most efficient to figure
**		the errors. Better go with storing the whole given file
**		in a ft_split and then go through this instead of being
**		blocked to one read.)
**	4. Parse for the scene elements.
**		- There can only be one resolution and one ambient lighting.
**		- If there are more than one camera or light, you need to
**			keep track to be able to allocate the right amount of
**			memory. One of each is already allocated in the init
**			function. (cf memory_utils)
**	5. Parse for the objects.
**		- Since memory for one object is already given in the
**			initialisation function, only give more memory if more
**			than one object.(cf memory_utils)
**
** 🦕
*/

static void	parse_obj(char *line, t_info *infos)
{
	int	add_mem;

	add_mem = no;
	if (infos->nb_objs)
		add_mem = yes;
	if (*line == 's' && *(line + 1) == 'p' && is_space(line + 2))
		get_sphere((line + 2), infos, add_mem);
	else if (*line == 's' && *(line + 1) == 'q' && is_space(line + 2))
		get_square((line + 2), infos, add_mem);
	else if (*line == 'p' && *(line + 1) == 'l' && is_space(line + 2))
		get_plane((line + 2), infos, add_mem);
	else if (*line == 'c' && *(line + 1) == 'y' && is_space(line + 2))
		get_cylinder((line + 2), infos, add_mem);
	else if (*line == 't' && *(line + 1) == 'r' && is_space(line + 2))
		get_triangle((line + 2), infos, add_mem);
	else
		handle_error("🧊	While parsing the objects names.\n", infos);
	infos->nb_objs += 1;
}

static void	parse_light(char *line, t_info *infos)
{
	int	add_mem;

	add_mem = no;
	if (infos->scene->nb_light)
		add_mem = yes;
	get_light(line + 1, infos, add_mem);
	infos->scene->nb_light += 1;
}

static void	parse_cam(char *line, t_info *infos)
{
	int	add_mem;

	add_mem = no;
	if (infos->scene->nb_cam)
		add_mem = yes;
	get_cam(line + 1, infos, add_mem);
	infos->scene->nb_cam += 1;
}

static void	parse(char *line, t_info *infos)
{
	while (is_space(line))
		line++;
	if (ft_isalnum(*line))
	{
		if ((*line == 'R' && is_space(line + 1)) && infos->res == no)
		{
			infos->res = yes;
			get_res((line + 1), infos);
		}
		else if ((*line == 'A' && is_space(line + 1)) && infos->amb == no)
		{
			infos->amb = yes;
			get_amb((line + 1), infos);
		}
		else if (*line == 'l' && is_space(line + 1))
			parse_light(line, infos);
		else if (*line == 'c' && is_space(line + 1))
			parse_cam(line, infos);
		else if (*line == 'c' || *line == 's' || *line == 'p' || *line == 't')
			parse_obj(line, infos);
		else
			handle_error("🎦	While parsing the elements names.\n", infos);
	}
	else if (ft_isalnum(*line))
		handle_error("	There's a weird character in an empty line.\n", infos);
}

void	get_infos(char *argv, t_rt *rt)
{
	int		fd;
	int		ret;
	char	*line;
	int		init;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
		error_msg("📂	Cannot open file.\n\n");
	init = init_objs(rt);
	if (!init)
		handle_error("💧	Fail to malloc at initialisation.\n", rt->infos);
	ret = 1;
	while (ret > 0)
	{
		ret = get_next_line(fd, &line);
		if (ret < 0)
			handle_error("📖	Cannot read the file.\n", rt->infos);
		parse(line, rt->infos);
		free(line);
	}
	if (!rt->infos->res || !rt->infos->amb)
		handle_error("🖥️	I need a resolution and ambient light !\n",
			rt->infos);
	if (close(fd) < 0)
		handle_error("❌	Cannot close the file.\n", rt->infos);
}
