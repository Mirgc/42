#include "structs.h"
#include "canvas.h"
#include "tuples.h"
#include "math.h"
#include "ray.h"
#include "world.h"
#include "stdio.h"

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

t_color lighting(t_material m, t_light li, t_tup point, t_tup eyev, t_tup normalv, int shadow)
{
	t_color efec;
	t_color	ambient;
	t_color	diffuse;
	t_color	specular;
	t_tup	lightv;
	t_tup	reflectv;
	double	ldotnormal;
	double	rdoteye;
	double	factor;

	efec = hadacolor(m.color, li.intensity);
	lightv = v_normalize(v_substract(li.position, point));
	ambient = multicolor(efec, m.ambient);
	ldotnormal = v_dot(lightv, normalv);
	if (shadow)
	{
		printf("%i\n", shadow);
		return(ambient);
	}
	if (ldotnormal < 0)
	{
		diffuse = set_color(0, 0, 0);
		specular = set_color(0, 0, 0);
	}
	else
	{
		diffuse = multicolor(efec, m.diffuse * ldotnormal);
		reflectv = r_reflect(v_negate(lightv), normalv);
		rdoteye = v_dot(reflectv, eyev);
		if (rdoteye <= 0)
			specular = set_color(0, 0, 0);
		else
		{
			factor = powf(rdoteye, m.shininess);
			specular = multicolor(li.intensity, m.specular * factor); 
		}
	}
	return (addcolor(ambient, addcolor(diffuse, specular)));
}

t_color shade_hit(t_world w, t_comps c)
{
	return (lighting(c.o.sp.material, w.li, c.over_point, c.eyev, c.normalv, is_shadowed(w, c.over_point)));
}

