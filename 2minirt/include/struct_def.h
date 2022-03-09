/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_def.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osurcouf <.@student.42lisboa.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 16:48:14 by osurcouf          #+#    #+#             */
/*   Updated: 2021/06/28 17:36:32 by osurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_DEF_H
# define STRUCT_DEF_H

# include "minirt.h"

/*
** VECTOR STRUCT
*/

typedef struct s_vec
{
	float	x;
	float	y;
	float	z;
}				t_vec;

typedef struct s_hit
{
	float	t;
	t_vec	point;
	t_vec	normal;
}				t_hit;

typedef struct s_params
{
	float	a;
	float	b;
	float	c;
}				t_params;

/*
** MATRIX STRUCT
*/

typedef struct s_matrix
{
	float	m[4][4];
}				t_matrix;

/*
** ELEMENTS OF OBJS STRUCT
*/

typedef struct s_sphere
{
	t_vec	point;
	float	radius;
}				t_sphere;

typedef struct s_plane
{
	t_vec	point;
	t_vec	orient;
}				t_plane;

typedef struct s_square
{
	t_vec	point;
	t_vec	orient;
	float	side;
}				t_square;

typedef struct s_cylinder
{
	t_vec	point;
	t_vec	orient;
	float	height;
	float	radius;
}				t_cylinder;

typedef struct s_triangle
{
	t_vec	point1;
	t_vec	point2;
	t_vec	point3;
}				t_triangle;

typedef struct s_circle
{
	t_vec	center;
	t_vec	orient;
	float	radius;
}				t_circle;

typedef struct s_color
{
	int		t;
	int		r;
	int		g;
	int		b;
	int		rgb;
}				t_color;

enum e_obj
{
	SPHERE = 1,
	PLANE,
	SQUARE,
	CYLINDER,
	TRIANGLE,
	CIRCLE,
};

typedef union u_type
{
	t_sphere	sp;
	t_plane		pl;
	t_square	sq;
	t_cylinder	cy;
	t_triangle	tr;
	t_circle	ci;
}				t_type;

/*
** OBJECT STRUCT
*/

typedef struct s_obj
{
	int		type;
	t_type	shape;
	t_color	color;
}				t_obj;

/*
** ELEMENTS OF SCENE SETUP STRUCT
*/

typedef struct s_res
{
	int	x;
	int	y;
}				t_res;

typedef struct s_ambient
{
	float	r;
	t_color	color;
}				t_ambient;

typedef struct s_camera
{
	t_vec	point;
	t_vec	orient;
	int		FOV;
}				t_camera;

typedef struct s_light
{
	t_vec	point;
	float	bright;
	t_color	color;
}				t_light;

/*
** SCENE SETUP STRUCT
*/

typedef struct s_scene
{
	t_res		res;
	t_ambient	amb;
	int			nb_cam;
	t_camera	*cam;
	int			nb_light;
	t_light		*light;
}				t_scene;

/*
** INFOS STRUCT
*/

typedef struct s_info
{
	t_scene		*scene;
	int			nb_objs;
	int			res;
	int			amb;
	t_obj		*objs;
}				t_info;

/*
** RAY STRUCT
*/

typedef struct s_ray
{
	t_vec	origin;
	t_vec	dir;
}				t_ray;

/*
** MLX STRUCTS
*/

typedef struct s_img
{
	void	*ptr;
	char	*addr;
	int		bit_pix;
	int		line_l;
	int		endian;
}				t_img;

/*
** CURRENT OBJECT AND CAMERA STRUCT
*/

typedef struct s_rec
{
	t_obj		obj;
	t_camera	cam;
	t_hit		hit;
	float		pix_color;
	t_params	param;
	float		t;
	float		t0;
	float		t1;
	float		dist_max;
	float		dist_min;

}				t_rec;

/*
** MINIRT STRUCT
*/

typedef struct s_rt
{
	void		*mlx;
	void		*win;
	t_img		img;
	t_info		*infos;
	t_rec		curr;
	t_ray		cam_ray;
	t_ray		shadow_ray;
	t_ray		light_ray;
}				t_rt;

#endif
