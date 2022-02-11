#include "tuples.h"
#include "ray.h"
#include <math.h>
#include <stdio.h>

t_tup	r_position(t_ray a, float i)
{
	return (v_add(a.ori, v_multi(a.dst, i)));
}

t_inter	r_intersect(t_obj obj, t_ray ray)
{
	t_tup	sp_to_ray;
	double	a;
	double	b;
	double	c;
	double	i;
	t_inter	inter;
	double	s;
	t_tup	p;

	inter.o.id = obj.id;
	p = v_create(0,0,0,1);
	sp_to_ray = v_substract(ray.ori, p);
	a = v_dot(ray.dst, ray.dst);
	b = 2 * v_dot(ray.dst, sp_to_ray);
	c = v_dot(sp_to_ray, sp_to_ray) - 1;
	i = powf(b, 2) - (4 * a * c);
	printf("%f, %f, %f, %f\n", a, b, c, i);
	if (i < 0)
	{
		inter.count = 0;
		return (inter);
	}
	s = sqrtf(i);
	inter.count = 2;
	inter.point[0] = (-b - s) / (2 * a);
	inter.point[1] = (-b + s) / (2 * a);
	return (inter);
}

t_inter	r_intersection(float t, char id)
{
	t_inter	inter;

	inter.t = t;
	inter.o.id = id;
	return (inter);
}


