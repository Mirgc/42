#ifndef RAY_H
# define RAY_H

typedef struct s_ray
{
	t_tup	ori;
	t_tup	dst;
} t_ray;

typedef struct s_sphere
{
	char	id;
} t_sphere;

typedef struct s_inter
{
	int			count;
	float		point[2];
	t_sphere	s;
}

t_tup	r_position(t_ray a, float i);
#endif
