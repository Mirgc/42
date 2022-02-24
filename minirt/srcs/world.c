#include "structs.h"

t_world	default_world()
{
	t_world	w;

	w.li = l_point_light(v_create(-10, 10, -10, 1), set_color(1, 1, 1));
	w.s1 = r_create_sphere();
	w.s2 = r_create_sphere();
	w.s1.m.color = set_color(0.8, 1.0, 0.6);
	w.s1.m.diffuse = 0.7;
	w.s1.m.specular = 0.2;
	w.s2.transform = m_scaling(0.5, 0.5, 0.5);
	return (w);
}
