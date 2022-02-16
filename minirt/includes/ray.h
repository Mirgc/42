#ifndef RAY_H
# define RAY_H

typedef struct s_ray
{
	t_tup	ori;
	t_tup	dir;
} t_ray;

typedef struct s_sphere
{
	t_tup	center;
	char	id;
	float	r;
} t_sphere;

typedef struct s_inter
{
	float		t;
	t_sphere	o;
} t_inter;

typedef struct s_arr_inter
{
	int	count;
	t_inter	*a;
} t_arr_inter;

t_tup		r_position(t_ray a, float i);
t_sphere	r_create_sphere();
t_arr_inter	r_intersect(t_sphere s, t_ray ray);
t_inter		r_intersection(float t, char id);
t_arr_inter	r_intersections(t_inter i1, t_inter i2);
float		hit(t_arr_inter inter);
#endif
