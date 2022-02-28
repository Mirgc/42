#include "tuples.h"
#include "ray.h"
#include "matrix.h"
#include "light.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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
	s.transform = m_identity();
	s.material = m_create_material();
	return (s);
}

t_ray	r_transform(t_ray a, t_matrix m)
{
	t_ray	tmp;
	
	tmp.ori = m_multi_tup(m, a.ori);
	tmp.dir = m_multi_tup(m, a.dir);
	return (tmp);
}

void	set_transform(t_sphere *s, t_matrix m)
{
	int	w;
	int	h;

	w = -1;
	while (++w < 4)
	{
		h = -1;
		while (++h < 4)
		{
			s->transform.m[w][h] = m.m[w][h];
		}
	}
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
	t_ray	raytr;
	
	raytr = r_transform(ray, m_invertible(s.transform));
	sp_to_ray = v_substract(raytr.ori, s.center);
	a = v_dot(raytr.dir, raytr.dir);
	b = 2 * v_dot(raytr.dir, sp_to_ray);
	c = v_dot(sp_to_ray, sp_to_ray) - 1;
	i = powf(b, 2) - (4 * a * c);
	t1.t = 0;
	t2.t = 0;
	if (i < 0)
		return (r_intersections(t1, t2));
	i = sqrtf(i);
	t1 = r_intersection((-b - i) / (2 * a), s);
	t2 = r_intersection((-b + i) / (2 * a), s);
	return (r_intersections(t1, t2));
}

t_inter	r_intersection(float t, t_sphere o)
{
	t_inter	inter;

	inter.t = t;
	inter.o = o;
	return (inter);
}

t_arr_inter r_intersections(t_inter i1, t_inter i2)
{
	t_arr_inter arr;

	if (i1.t == 0 && i2.t == 0)
		arr.count = 0;
	else
		arr.count = 2;
	arr.a = (t_inter *)malloc(sizeof(t_inter) * 2);
	arr.a[0] = i1;
	arr.a[1] = i2;
	return(arr);
}

void	r_order(t_arr_inter wo, int count)
{
	int		i;
	float	tmp;

	i = -1;
    while ( ++i < count )
    {
        if (wo.a[i].t < wo.a[i-1].t )
        {
            tmp = wo.a[i].t;
            wo.a[i].t = wo.a[i-1].t;
			wo.a[i-1].t = tmp;
			i = 0;
		}
	}
}

t_arr_inter	r_intersect_world(t_world w, t_ray r)
{
	t_arr_inter	wo_arr;
	t_arr_inter	tmp1_arr;
	t_arr_inter	tmp2_arr;

	wo_arr.a = (t_inter *)malloc(sizeof(t_inter) * 4);
	tmp1_arr = r_intersect(w.s1, r);
	tmp2_arr = r_intersect(w.s2, r);
	wo_arr.count = tmp1_arr.count;
	wo_arr.count += tmp2_arr.count;
	wo_arr.a[0] = tmp1_arr.a[0];
	wo_arr.a[1] = tmp1_arr.a[1];
	wo_arr.a[2] = tmp2_arr.a[0];
	wo_arr.a[3] = tmp2_arr.a[1];
	free(tmp1_arr.a);
	free(tmp2_arr.a);
	r_order(wo_arr, 4);
	return (wo_arr);
}

/*float	r_hit(t_arr_inter inter)
{
	if (inter.count != 0)
	{
		if (inter.a[0].t > 0 && inter.a[1].t > 0)
			return(fmin(inter.a[0].t, inter.a[1].t));
		if (inter.a[0].t > 0 || inter.a[1].t > 0)
			return(fmax(inter.a[0].t, inter.a[1].t));
	}
	return(-1);
}*/
t_inter r_hit(t_arr_inter inter)
{
	int     i;
	int     co;

	co = 0;
	i = -1;
	if (inter.count == 0)
		return (inter.a[0]);
	while (++i < inter.count)
	{
		if (inter.a[i].t > 0)
			co++;
	}
	if (co == inter.count)
		return (inter.a[0]);
	else if (co == 0)
		return (inter.a[inter.count]);
	else
		return (inter.a[inter.count -1]);
}

t_tup	r_normal_at(t_sphere s, t_tup p)
{
	t_tup	o_point;
	t_tup	o_normal;
	t_tup	w_normal;

	o_point = m_multi_tup(m_invertible(s.transform), p);
	o_normal = v_substract(o_point, s.center);
	w_normal = m_multi_tup(m_trans(m_invertible(s.transform)), o_normal);
	w_normal.w = 0;
	return(v_normalize(w_normal));
}

t_tup	r_reflect(t_tup t, t_tup p)
{
	double	dot;
	t_tup	mul;

	dot = v_dot(t, p);
	mul = v_multi(p, 2);
	return(v_substract(t, v_multi(mul, dot)));
}
