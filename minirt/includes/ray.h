#ifndef RAY_H
# define RAY_H

# include "structs.h"

t_tup		r_position(t_ray a, float i);
t_sphere	r_create_sphere();
t_ray		r_transform(t_ray a, t_matrix m);
void		set_transform(t_sphere *s, t_matrix m);
t_arr_inter	r_intersect(t_sphere s, t_ray ray);
t_inter		r_intersection(float t, char id);
t_arr_inter	r_intersections(t_inter i1, t_inter i2);
float		hit(t_arr_inter inter);
#endif
