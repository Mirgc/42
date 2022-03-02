#include "structs.h"
#include "light.h"
#include "tuples.h"
#include "canvas.h"
#include "matrix.h"
#include "ray.h"
#include <stdio.h>
#include <stdlib.h>

t_world	default_world(int nb)
{
	t_world	w;
	int		i;

	w.li = l_point_light(v_create(-10, 10, -10, 1), set_color(1, 1, 1));
	w.nb = nb;
	w.sp = (t_sphere *)malloc(sizeof(t_sphere) * nb);
	i = -1;
	while (++i < nb)
	{
		w.sp[i] = r_create_sphere();
	}
	return (w);
}

t_comps	prepare_computations(t_inter i, t_ray ray)
{
	t_comps		comps;

	comps.t = i.t;
	comps.o = i.o;
	comps.point = r_position(ray, comps.t);
	comps.eyev = v_negate(ray.dir);
	comps.normalv = r_normal_at(comps.o, comps.point);
	if (v_dot(comps.normalv, comps.eyev) < 0)
	{
		comps.inside = 1;
		comps.normalv = v_negate(comps.normalv);
	}
	else
		comps.inside = 0;
	return (comps);
}

t_color	color_at(t_world w, t_ray r)
{
	t_arr_inter	arr;
	t_inter		hit;
	t_color		col;
	t_comps		comps;

	col = set_color(0, 0, 0);
	arr = r_intersect_world(w, r);
	if (arr.count == 0)
		return (col);
	hit = r_hit(arr);
	comps = prepare_computations(hit, r);
	col = shade_hit(w, comps);
	return (col);
}

t_matrix	view_transform(t_tup from, t_tup to, t_tup up)
{
	t_tup		forward;
	t_tup		upn;
	t_tup		left;
	t_tup		true_up;
	t_matrix	orientation;

	forward = v_normalize(v_substract(to, from));
	upn = v_normalize(up);
	left = v_cross(forward, upn);
	true_up = v_cross(left, forward);
	orientation = m_init_with_tuple(left, true_up, v_negate(forward));
	return (m_multi(orientation, m_translation(-from.x, -from.y, -from.z)));	
}
