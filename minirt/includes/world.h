#ifndef WORLD_H
# define WORLD_H

# include "structs.h"

t_world		default_world(int nb);
//t_comps		prepare_computations(float t, t_inter i, t_ray ray);
t_comps		prepare_computations(t_inter i, t_ray ray);
t_color		color_at(t_world w, t_ray r, int rem);
t_matrix	view_transform(t_tup from, t_tup to, t_tup up);
int		is_shadowed(t_world w, t_tup p);
t_color		reflected_color(t_world w, t_comps c, int rem);
#endif
