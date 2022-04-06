/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikgarci <mikgarci@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 16:40:26 by mikgarci          #+#    #+#             */
/*   Updated: 2022/03/23 20:19:17 by mikgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include <stdbool.h>

typedef struct s_tuple
{
	float	x;
	float	y;
	float	z;
	float	w;
}	t_tuple;

typedef struct s_color
{
	float	r;
	float	g;
	float	b;
}	t_color;

typedef struct s_matrix
{
	float	m[4][4];
	int		row;
	int		col;
}	t_matrix;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_generic {
	t_data	img;
	void	*mlx;
	void	*mlx_win;
}	t_generic;

typedef struct s_material {
	float	ambient;
	float	diffuse;
	float	specular;
	float	shininess;
	float	reflective;
	t_color	color;
}	t_material;

typedef struct s_ray {
	t_tuple	org;
	t_tuple	dir;
}	t_ray; 

typedef struct s_sphere {
	t_tuple		org;
	float		r;
	t_matrix	transform;
	t_material	mat;
}	t_sphere;

typedef struct s_plane {
	t_matrix	transform;
	t_material	mat;
	t_tuple		org;
	t_tuple		norm;
}	t_plane;

typedef struct s_cylinder {
	t_tuple		org;
	float		r;
	t_material	mat;
	t_matrix	transform;
	float		min;
	float		max;
	bool		closed;
}	t_cylinder;

typedef struct s_shape {
	t_sphere	s;
	t_plane		p;
	t_cylinder	cy;
	char		c;
}	t_shape;

typedef struct s_inter {
	float	t;
	t_shape	obj;
}	t_inter;

typedef struct s_arr_inter {
	int			count;
	t_inter		*a;
}	t_arr_inter;

typedef struct s_light {
	t_tuple	pos;
	t_color	i;
}	t_light;

typedef struct s_amb{
	int	n;
	float	r;
	t_color	col;
}	t_amb;

typedef struct s_world {
	t_light		light;
	int			count;
	t_shape		*s;
}	t_world;

typedef struct s_comps {
	float		t;
	t_shape		obj;
	t_tuple		p;
	t_tuple		eye;
	t_tuple		norm;
	bool		inside;
	t_tuple		op;
	t_tuple		reflectv;
}	t_comps;

typedef struct s_camera {
	int			hsize;
	int			vsize;
	float		hw;
	float		hh;
	float		ps;
	t_tup		pos;
	t_tup		ori;
	float		fov;
	t_matrix	trans;	
}	t_camera;

typedef struct s_scene {
	t_amb		amb;
	t_camera	*cam;
	t_world		world;
}

#endif