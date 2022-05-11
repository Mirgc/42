#ifndef RAY_H
# define RAY_H

# include "structs.h"

t_tup		r_position(t_ray a, float i);
t_sphere	r_create_sphere();
t_plane		r_create_plane();
t_cube		r_create_cube();
t_ray		r_transform(t_ray a, t_matrix m);
void		set_transform(t_sphere *s, t_matrix m);
float		r_intersect(t_world *wo, t_shape s, t_ray ray);
float		r_intersect_cube(t_world *wo, t_shape s, t_ray ray);
t_inter		r_intersection(float t, t_shape o);
t_arr_inter	r_intersections_plane(t_world wo, t_inter i);
t_arr_inter	r_intersections(t_world wo, t_inter i1, t_inter i2);
float		r_hit(t_arr_inter inter);
t_arr_inter     r_intersect_world(t_world w, t_ray r);
t_tup		r_normal_at(t_shape s, t_tup p);
t_tup		r_reflect(t_tup t, t_tup p);
#endif
