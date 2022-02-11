#include "tuples.h"
#include "ray.h"
#include <math.h>

t_tup	r_position(t_ray a, float i)
{
	return (v_add(a.ori, v_multi(a.dst, i)));
}

double	r_intersection(t_ray ray, t_tup p)
{
	t_tup	sp_to_ray;
	double	a;
	double	b;
	double	c;
	double	i;
	double	t1;
	double	t2;
	double	s;

	sp_to_ray = v_substract(ray.ori, p);
	a = v_dot(ray.dst, ray.dst);
	b = 2 * v_dot(ray.dst, sp_to_ray);
	c = v_dot(sp_to_ray, sp_to_ray);
	i = pow(b, 2) - (4 * a * c);
	if (i < 0)
		return (-1);
	s = sqrt(i);
        t1 = (-b - s) / (2 * a);
        t2 = (-b + s) / (2 * a);
        if (t1 > 0 && t2 > 0)
		return(fmin(t1, t2));
        if (t1 > 0 || t2 > 0)
		return(fmax(t1, t2));
	return (-1);
}
