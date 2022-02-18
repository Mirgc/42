#include "structs.h"
#include "canvas.h"

t_light	l_point_light(t_tup pos, t_color col)
{
	t_light	li;

	li.position = pos;
	li.intensity = col;
	return(li);
}

t_material	m_create_material()
{
	t_material tmp;

	tmp.color = set_color(1, 1, 1);
	tmp.ambient = 0.1;
	tmp.diffuse = 0.9;
	tmp.specular = 0.9;
	tmp.shininess= 200.0;
	return (tmp);
}

