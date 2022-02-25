#include "structs.h"
#include "light.h"
#include "tuples.h"
#include "canvas.h"
#include "matrix.h"
#include "ray.h"

t_world	default_world()
{
	t_world	w;

	w.li = l_point_light(v_create(-10, 10, -10, 1), set_color(1, 1, 1));
	w.s1 = r_create_sphere();
	w.s2 = r_create_sphere();
	w.s1.material.color = set_color(0.8, 1.0, 0.6);
	w.s1.material.diffuse = 0.7;
	w.s1.material.specular = 0.2;
	w.s2.transform = m_scaling(0.5, 0.5, 0.5);
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
	t_color		col;
//	t_comps		comps;
	int			i;

	col = set_color(0, 0, 0);
	i = -1;
	arr = r_intersect_world(w, r);
	if (arr.count == 0)
		return (col);
//	while (++i < 4)
//	{
//		comps = prepare_computations(arr.a[i], r);
//		col = addcolor(col, shade_hit(w, comps));
//	}
	return (col);
}
