/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikgarci <mikgarci@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 17:35:51 by mikgarci          #+#    #+#             */
/*   Updated: 2022/04/06 20:06:23 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGFT_H
# define ALGFT_H

# define EPSILON 0.001
# define W_WIN 200
# define H_WIN 100

# include "mlx.h"
# include "struct.h"

//CREATE TUPLE// POINT 1 VECTOR 0
t_tuple	ft_point(float x, float y, float z);
t_tuple	ft_vector(float x, float y, float z);

//OPERATION TUPLE//
t_tuple	ft_add_tup(t_tuple a, t_tuple b);
t_tuple	ft_sub_tup(t_tuple a, t_tuple b);
t_tuple ft_div_tup(t_tuple a, float d);
t_tuple ft_mult_tup(t_tuple a, float m);
t_tuple ft_neg_tup(t_tuple a);
//TWO//
float	ft_mag_vec(t_tuple v);
t_tuple ft_norm_vec(t_tuple v);
float	ft_dot_prod(t_tuple a, t_tuple b);
t_tuple	ft_cross_prod(t_tuple a, t_tuple b);
t_tuple	ft_reflect(t_tuple in, t_tuple nor);

//COLORS//
t_color	ft_color(float	r, float g, float b);
t_color	ft_add_color(t_color a, t_color b);
t_color	ft_sub_color(t_color a, t_color b);
t_color	ft_escal_color(t_color a, float b);
t_color	ft_mult_color(t_color a, t_color b);

//MATRIX//
t_matrix	ft_matrix(int row, int column);
t_matrix	ft_mult_matrix(t_matrix a, t_matrix b);
t_tuple		ft_mult_matrix_tup(t_matrix a, t_tuple b);
t_matrix	ft_trans_matrix(t_matrix a);
t_matrix	ft_mult_matrix_f(t_matrix a, float w);
//Determinant//
t_matrix	ft_sub_matrix(t_matrix a, int row, int col);
float		ft_minor_matrix(t_matrix a, int row, int col);
float		ft_det_matrix(t_matrix a);
float		ft_cofac_matrix(t_matrix a, int row, int col);
//Inverse//
t_matrix	ft_atta_matrix(t_matrix	a);
t_matrix	ft_inver_matrix(t_matrix a);
t_matrix	ft_iden_matrix(int row, int col);

//TRANSFORMATION//
t_matrix	ft_transla_matrix(float x, float y, float z);
t_matrix	ft_scal_matrix(float x, float y, float z);
t_matrix	ft_rotate_x_matrix(float x);
t_matrix	ft_rotate_y_matrix(float x);
t_matrix	ft_rotate_z_matrix(float x);
//Two//
t_matrix	ft_shear_matrix(t_tuple b, t_tuple c);
t_matrix	ft_view_trans(t_tuple from, t_tuple to, t_tuple up);
t_matrix	ft_put_matrix(t_tuple a, t_tuple b, t_tuple c);

//PRINT & ERROR//
int		ft_error(char *str);
void	ft_exit(char *str, int	i);
void	ft_print_tup(t_tuple tuple);
void	ft_print_matrix(t_matrix a);
void	ft_print_color(t_color c);

//RAY//
t_ray	ft_ray(t_tuple a, t_tuple b);
t_tuple	ft_pos_ray(t_ray a, float b);
float	ft_hit(t_arr_inter x);
t_ray	ft_transform(t_ray r, t_matrix m);

//SPHERE//
t_arr_inter	ft_sphere_inter(t_ray r, t_sphere s);
t_sphere	ft_sphere(t_tuple org, float r);
t_inter		ft_intersection(float a, t_sphere s);
t_tuple		ft_normal_at(t_sphere s, t_tuple p);

//PLANE//
t_plane		ft_plane(void);
t_tuple		ft_normal_at_plane(t_plane plane, t_tuple p);
t_arr_inter	ft_plane_inter(t_ray r, t_plane p);
t_inter		ft_intersection_plane(float a, t_plane p);

//CYLINDER//
t_cylinder	ft_cylinder(void);
t_arr_inter	ft_cylinder_inter(t_ray r, t_cylinder cy);
t_inter	ft_intersection_cylinder(float a, t_cylinder c);
t_tuple	ft_normal_at_cylinder(t_cylinder c, t_tuple p);

//LIGHT//
t_light		ft_point_light(t_tuple pos, t_color y);

//MATERIALS//
t_material	ft_materials(void);
t_color		ft_lighting(t_material m, t_light l, t_tuple pos, t_tuple eyev, t_tuple normalv, bool a);
bool		ft_is_shadowed(t_world w, t_tuple p);

//WORLD//
t_world		ft_def_world(void);
t_arr_inter	ft_add_inter(t_arr_inter temp, t_arr_inter x);
t_arr_inter	ft_inter_world(t_world w, t_ray r);
t_arr_inter	ft_order_inter(t_arr_inter x);
t_color		ft_shade_hit(t_world w, t_comps comps, int rem);
//Two//
t_color	ft_color_at(t_world w, t_ray r, int rem);
t_world	ft_add_world(t_world w, t_shape s);

//INTERSECTIONS//
t_comps	ft_prep_comps(t_inter i, t_ray r);

//CAMERA//
t_camera	ft_camera(int hsize, int vsize, float fov);
t_ray		ft_ray_for_pixel(t_camera c, float px, float py);
void		ft_render(t_camera c, t_world w, t_generic g);

/*//SHAPE//
t_shape		ft_shape(void);
t_inter		ft_intersection_shape(float a, t_shape s);
t_arr_inter	ft_shape_inter(t_ray r, t_shape s);
t_tuple		ft_normal_at_shape(t_shape s, t_tuple p);*/

#endif
