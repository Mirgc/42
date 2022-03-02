/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osurcouf <.@student.42lisboa.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 16:48:25 by osurcouf          #+#    #+#             */
/*   Updated: 2021/06/30 15:06:54 by osurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <mlx.h>
# include <math.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <errno.h>
# include <stdbool.h>
# include <limits.h>
# include <float.h>
# include <pthread.h>
# include "mlx.h"
# include "../libft/libft.h"
# include "struct_def.h"
# include "utils.h"
# include "keys.h"
# include "colors.h"

enum e_y_or_no
{
	no,
	yes,
};

/*
**	Start minirt & Window management
*/

void		start_minirt(t_rt *rt);
void		create_img(t_rt *rt);

/*
**	Raytracing
*/

void		gen_cam_ray(int x, int y, t_rt *rt);
void		get_pixel_color(t_rt *rt);

/*
**	Intersecting objects
*/

void		check_if_it_hits_object(t_rt *rt);
float		intersect_obj(t_ray *ray, t_rec *curr);
float		sphere(t_ray *ray, t_rec *curr);
void		sphere_normal(t_rec *curr);
float		plane(t_ray *ray, t_rec *curr, t_vec point, t_vec orient);
float		cylinder(t_ray *ray, t_rec *curr);
void		cylinder_normal(t_rec *curr);
float		circle(t_ray *ray, t_rec *curr);
float		square(t_ray *ray, t_rec *curr);
float		triangle(t_ray *ray, t_rec *curr);
void		triangle_normal(t_rec *curr);
bool		solve_quadratic(t_params param, float *t0, float *t1);
t_params	new_params(float a, float b, float c);

/*
**	Parsing
*/

void		get_infos(char *argv, t_rt *rt);
void		get_res(char *line, t_info *infos);
void		get_amb(char *line, t_info *infos);
void		get_cam(char *line, t_info *infos, int add_mem);
void		get_light(char *line, t_info *infos, int add_mem);
void		get_sphere(char *line, t_info *infos, int add_mem);
void		get_square(char *line, t_info *infos, int add_mem);
void		get_plane(char *line, t_info *infos, int add_mem);
void		get_triangle(char *line, t_info *infos, int add_mem);
void		get_cylinder(char *line, t_info *infos, int add_mem);

#endif
