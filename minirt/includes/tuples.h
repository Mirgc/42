#ifndef TUPLES_H
#define TUPLES_H

typedef struct s_tup
{
	double	x;
	double	y;
	double	z;
	int		w;
}	t_tup;

typedef struct s_proj
{
	t_tup	pos;
	t_tup	vel;
}	t_proj;

typedef struct s_env
{
	t_tup	grav;
	t_tup	wind;
}	t_env;


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
