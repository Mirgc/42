/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osurcouf <.@student.42lisboa.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 19:48:47 by osurcouf          #+#    #+#             */
/*   Updated: 2021/06/30 16:52:07 by osurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "minirt.h"

# define TAB 9
# define SPACE ' '
# define END 0xd
# define COMMENT '#'

# if __APPLE__
#  define OS_APPLE 1
# else
#  define OS_APPLE 0
# endif

/*
**	Handle Errors
*/

void		handle_error(char *error, t_info *infos);
void		error_msg(char *error);

/*
**	Events
*/

int			events(int keycode, t_rt *rt);
int			exit_and_free(t_rt *rt);

/*
**	Rendering (mlx)
*/

void		my_mlx_pixel_put(t_img *img, int x, int y, int color);

/*
**	Vectors
*/

t_vec		create_vec(float a, float b, float c);
t_vec		add(t_vec v1, t_vec v2);
t_vec		substract(t_vec v1, t_vec v2);
t_vec		multiply(t_vec v1, float m);
t_vec		divide(t_vec v1, float d);
float		dot_product(t_vec v1, t_vec v2);
t_vec		cross_product(t_vec v1, t_vec v2);
t_vec		normalize(t_vec v);
float		length(t_vec v);

/*
** Colors
*/

int			create_color(t_color color);
t_color		set(int r, int g, int b);
t_color		color_add(t_color c1, t_color c2);
t_color		color_sub(t_color c1, t_color c2);
t_color		color_multiply(t_color c1, float m);
t_color		color_div(t_color c1, float d);
t_color		convert_to_max(t_color color);

/*
**	Parsing
*/

char		*next_nbr(char *line, t_info *infos);
char		*next_int(char *line, t_info *infos);
bool		is_space(char *line);
char		*pass_spaces(char *line, t_info *infos);
void		verify_end_line(char *line, t_info *infos);
char		*get_point(char *line, t_vec *vec, t_info *infos);
char		*get_orient(char *line, t_vec *vec, t_info *infos);
char		*get_color(char *line, t_color *color, t_info *infos);
void		get_caps(t_info *infos, t_cylinder cy);

/*
**	Memory
*/

int			init_objs(t_rt *rt);
void		del_mem_infos(t_info *infos);
t_obj		*add_mem_obj(int nb_objs, t_obj *objs);
t_light		*add_mem_light(int nb_light, t_light *light);
t_camera	*add_mem_cam(int nb_cam, t_camera *cam);

#endif
