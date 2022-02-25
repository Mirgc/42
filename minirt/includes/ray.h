#ifndef RAY_H
# define RAY_H

# include "structs.h"

t_tup		r_position(t_ray a, float i);
t_sphere	r_create_sphere();
t_ray		r_transform(t_ray a, t_matrix m);
void		set_transform(t_sphere *s, t_matrix m);
t_arr_inter	r_intersect(t_sphere s, t_ray ray);
t_inter		r_intersection(float t, t_sphere o);
t_arr_inter	r_intersections(t_inter i1, t_inter i2);
t_arr_inter	r_intersect_world(t_world w, t_ray r);
float		r_hit(t_arr_inter inter);
t_tup		r_normal_at(t_sphere s, t_tup p);
t_tup		r_reflect(t_tup t, t_tup p);
#endif
