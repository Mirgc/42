#include "tuples.h"
#include "ray.h"
#include "matrix.h"
#include "light.h"
#include "minirt.h"
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
	return (s);
}

t_plane		r_create_plane()
{
	t_plane	s;
	
	s.center = v_create(0,0,0,1);
	s.id = 'p';
	s.transform = m_identity();
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

float	r_intersect(t_world *wo, t_shape s, t_ray ray)
{
	t_tup		sp_to_ray;
	double	a;
	double	b;
	double	c;
	double	i;
	t_inter	t1;
	t_inter	t2;
	t_arr_inter	arr;
	
	wo->ray_saved = r_transform(ray, m_invertible(s.sp.transform));
	sp_to_ray = v_substract(wo->ray_saved.ori, s.sp.center);
	a = v_dot(wo->ray_saved.dir, wo->ray_saved.dir);
	b = 2 * v_dot(wo->ray_saved.dir, sp_to_ray);
	c = v_dot(sp_to_ray, sp_to_ray) - 1;
	i = powf(b, 2) - (4 * a * c);
	if (i < 0)
		return (-1);
	i = sqrtf(i);
	t1 = r_intersection((-b - i) / (2 * a), s);
	t2 = r_intersection((-b + i) / (2 * a), s);
	arr = r_intersections(*wo, t1, t2);
	wo->arr = arr;
	if (!arr.a)
		free(arr.a);
	return (0);
}

float	r_intersect_plane(t_world *wo, t_shape s, t_ray ray)
{
	float	t;
	t_inter	i;
	t_arr_inter	arr;

	if (fabs(ray.dir.y) < EPSILON)
		return (-1);
	t = -ray.ori.y / ray.dir.y;
	i = r_intersection(t, s);
	arr = r_intersections_plane(*wo, i);
	wo->arr = arr;
	if (!arr.a)
		free(arr.a);
	return (0);
}

t_inter	r_intersection(float t, t_shape o)
{
	t_inter	inter;

	inter.t = t;
	inter.o = o;
	return (inter);
}

/*t_arr_inter r_intersections(t_inter i1, t_inter i2)
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
}*/

t_arr_inter	r_intersections_plane(t_world wo, t_inter i1)
{
        t_arr_inter arr;
        int                     i;

        arr.a = NULL;
		arr.count = wo.arr.count + 1;
        arr.a = (t_inter *)malloc(sizeof(t_inter) * (wo.arr.count + 1));
        i = 0;
        while (i < wo.arr.count)
        {
                arr.a[i] = wo.arr.a[i];
                i++;
        }
        arr.a[wo.arr.count] = i1;
        return(arr);
}

t_arr_inter	r_intersections(t_world wo, t_inter i1, t_inter i2)
{
        t_arr_inter arr;
        int                     i;

        arr.a = NULL;
		arr.count = wo.arr.count + 2;
        arr.a = (t_inter *)malloc(sizeof(t_inter) * (wo.arr.count + 2));
        i = 0;
        while (i < wo.arr.count)
        {
                arr.a[i] = wo.arr.a[i];
                i++;
        }
        arr.a[wo.arr.count] = i1;
        arr.a[wo.arr.count + 1] = i2;
	//return(r_hit(arr));
        //free(wo.arr.a);
        return(arr);
}


float	r_hit(t_arr_inter inter)
{
	float	t;
	int	i;

	t = INFINITY;
	if (inter.count != 0)
	{
		i = 0;
		while (i < inter.count)
		{
			if (inter.a[i].t > 0 && inter.a[i].t < t)
				t = inter.a[i].t;
			i++;
		}
		if (t == INFINITY)
			return (-1);
		return (t);
	}
	return(-1);
}

t_arr_inter     r_intersect_world(t_world w, t_ray r)
{
        int     i;

        i = 0;
        while (i < w.nb)
        {
			if (w.sh[i].id == 1)
	            r_intersect(&w, w.sh[i], r);
			if (w.sh[i].id == 2)
	            r_intersect_plane(&w, w.sh[i], r);
			i++;
        }
	//printf("----%f, %f,\n", w.arr.a[0].t, w.arr.a[1].t);
//      if (w.arr.count)
//              r_order(w.arr, w.arr.count);
        return (w.arr);
}

t_tup	r_normal_at(t_shape s, t_tup p)
{
	t_tup	o_point;
	t_tup	o_normal;
	t_tup	w_normal;

	if (s.id == 1)
	{
		o_point = m_multi_tup(m_invertible(s.sp.transform), p);
		o_normal = v_substract(o_point, s.sp.center);
		w_normal = m_multi_tup(m_trans(m_invertible(s.sp.transform)), o_normal);
	}
	if (s.id == 2)
		return (v_create(0, 1, 0, 1));
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
