#ifndef LIGHT_H
#define LIGHT_H

# include "structs.h"

t_light		l_point_light(t_tup pos, t_color col);
t_material	m_create_material();
t_color		lighting(t_material m, t_light li, t_tup point, t_tup eyev, t_tup normalv);

#endif
