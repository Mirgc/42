#ifndef TUPLES_H
#define TUPLES_H

# include "structs.h"

t_tup	v_create(double x, double y, double z, int v);
t_tup	v_add(t_tup a, t_tup b);
t_tup	v_substract(t_tup a, t_tup b);
t_tup	v_negate(t_tup a);
t_tup	v_multi(t_tup a, double nb);
double	v_magnitude(t_tup vec);
t_tup	v_normalize(t_tup a);
double	v_dot(t_tup a, t_tup b);
t_tup	v_cross(t_tup a, t_tup b);
t_proj	tick(t_env env, t_proj proj);
int		equal(float a, float b);
#endif
