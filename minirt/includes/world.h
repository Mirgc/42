#ifndef WORLD_H
# define WORLD_H

# include "structs.h"

t_world	default_world();
t_comps	prepare_computations(t_inter i, t_ray ray);
t_color	color_at(t_world w, t_ray r);
#endif
