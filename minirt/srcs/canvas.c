
#include "minirt.h"

t_color set_color(double r, double g, double b)
{
	t_color tmp;

	tmp.r = r;
	tmp.g = g;
	tmp.b = b;
	return (tmp);
}

t_color	addcolor(t_color a, t_color b)
{
	t_color	tmp;

	tmp.r = a.r + b.r;
	tmp.g = a.g + b.g;
	tmp.b = a.b + b.b;
	return (tmp);
}

t_color	subcolor(t_color a, t_color b)
{
	t_color	tmp;

	tmp.r = a.r - b.r;
	tmp.g = a.g - b.g;
	tmp.b = a.b - b.b;
	return (tmp);
}

t_color	multicolor(t_color a, int b)
{
	t_color	tmp;

	tmp.r = a.r * b;
	tmp.g = a.g * b;
	tmp.b = a.b * b;
	return (tmp);
}

t_color hadacolor(t_color a, t_color b)
{
	t_color	tmp;

	tmp.r = a.r * b.r;
	tmp.g = a.g * b.g;
	tmp.g = a.b * b.b;
	return (tmp);
}




