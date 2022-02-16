#include "tuples.h"
#include "ray.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

t_tup	r_position(t_ray a, float i)
{
	return (v_add(a.ori, v_multi(a.dir, i)));
}

t_sphere	r_create_sphere()
{
	t_sphere	s;
	
	s.center = v_create(0,0,0,1);
	s.id = 's';
	s.r = 0;
	return (s);
}

t_arr_inter	r_intersect(t_sphere s, t_ray ray)
{
	t_tup		sp_to_ray;
	double	a;
	double	b;
	double	c;
	double	i;
	t_inter	t1;
	t_inter	t2;

	sp_to_ray = v_substract(ray.ori, s.center);
	a = v_dot(ray.dir, ray.dir);
	b = 2 * v_dot(ray.dir, sp_to_ray);
	c = v_dot(sp_to_ray, sp_to_ray) - 1;
	i = powf(b, 2) - (4 * a * c);
	t1.t = 0;
	t1.t = 0;
	if (i < 0)
		return (r_intersections(t1, t2));
	i = sqrtf(i);
	t1 = r_intersection((-b - i) / (2 * a), s.id);
	t2 = r_intersection((-b + i) / (2 * a), s.id);
	
	return (r_intersections(t1, t2));
}

t_inter	r_intersection(float t, char id)
{
	t_inter	inter;

	inter.t = t;
	inter.o.id = id;
	return (inter);
}

t_arr_inter r_intersections(t_inter i1, t_inter i2)
{
	t_arr_inter arr;

	if (i1.t == 0 && i2.t == 0)
	{
		arr.count = 0;
		return (arr);
	}
	arr.a = (t_inter *)malloc(sizeof(t_inter) * 2);
	arr.count = 2;
	arr.a[0] = i1;
	arr.a[1] = i2;
	return(arr);
}

float	r_hit(t_arr_inter inter)
{
	if (inter.a[0].t > 0 && inter.a[1] > 0)
		return (fmin(inter.a[0].t, inter.a[1]));
	if (inter.a[0].t > 0 || inter.a[1] > 0)
		return (fmax(inter.a[0].t, inter.a[1]));
	return(-1);
}

t_ray	r_transform(t_ray a, t_matrix m)
{
	
}

