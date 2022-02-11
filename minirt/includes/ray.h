#ifndef RAY_H
# define RAY_H

typedef struct s_ray
{
	t_tup	ori;
	t_tup	dst;
} t_ray;

typedef struct s_obj
{
	char	id;
	float	t;
} t_obj;

typedef struct s_inter
{
	int			count;
	float		point[2];
	float		t;
	t_obj		o;
} t_inter;

t_tup	r_position(t_ray a, float i);
t_inter	r_intersect(t_obj o, t_ray ray);
t_inter	r_intersection(float t, char id);
#endif
