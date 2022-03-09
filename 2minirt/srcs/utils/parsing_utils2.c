/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osurcouf <.@student.42lisboa.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 11:40:24 by osurcouf          #+#    #+#             */
/*   Updated: 2021/06/30 17:12:15 by osurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

char	*get_color(char *line, t_color *color, t_info *infos)
{
	line = next_nbr(line, infos);
	line = pass_spaces(line, infos);
	color->r = ft_atoi(line);
	line = next_int(line, infos);
	color->g = ft_atoi(line);
	line = next_int(line, infos);
	color->b = ft_atoi(line);
	line = next_int(line, infos);
	if ((color->r < 0 || color->r > 255)
		|| (color->g < 0 || color->g > 255)
		|| (color->b < 0 || color->b > 255))
		handle_error("🎨	Color values should between 0 and 255.\n", infos);
	color->rgb = create_color(*color);
	return (line);
}

char	*get_point(char *line, t_vec *vec, t_info *infos)
{
	line = pass_spaces(line, infos);
	vec->x = ft_atof(line);
	line = next_nbr(line, infos);
	vec->y = ft_atof(line);
	line = next_nbr(line, infos);
	vec->z = ft_atof(line);
	if (vec->x > FLT_MAX || vec->y > FLT_MAX || vec->z > FLT_MAX)
		handle_error("📈	Wow ! One of your values is over the float max.\n",
			infos);
	return (line);
}

char	*get_orient(char *line, t_vec *vec, t_info *infos)
{
	line = pass_spaces(line, infos);
	vec->x = ft_atof(line);
	line = next_nbr(line, infos);
	vec->y = ft_atof(line);
	line = next_nbr(line, infos);
	vec->z = ft_atof(line);
	if ((vec->x > 1 || vec->x < -1)
		   	 || (vec->y > 1 || vec->y < -1)
		   	 || (vec->z > 1 || vec->z < -1))
		handle_error("📈	Orientation vectors should be between -1 and 1.\n",
			infos);
	return (line);
}

void	get_caps(t_info *infos, t_cylinder cy)
{
	t_circle	*cap;
	t_color		cy_color;
	int			i;

	cy_color = infos->objs[infos->nb_objs].color;
	i = 0;
	while (i < 2)
	{
		infos->nb_objs += 1;
		infos->objs = add_mem_obj(infos->nb_objs, infos->objs);
		if (!infos->objs)
			handle_error("💧	Fail to malloc circle.\n", infos);
		infos->objs[infos->nb_objs].type = CIRCLE;
		infos->objs[infos->nb_objs].color = cy_color;
		cap = &infos->objs[infos->nb_objs].shape.ci;
		if (i == 0)
			cap->center = add(cy.point, multiply(cy.orient, cy.height / 2));
		else if (i == 1)
			cap->center = add(cy.point, multiply(cy.orient, -cy.height / 2));
		cap->radius = cy.radius;
		cap->orient = cy.orient;
		i++;
	}
}
