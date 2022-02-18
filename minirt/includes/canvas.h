#ifndef CANVAS_H
#define CANVAS_H

# include "structs.h"


t_color		set_color(double r, double g, double b);
t_color		addcolor(t_color a, t_color b);
t_color		subcolor(t_color a, t_color b);
t_color		multicolor(t_color a, int b);
t_color		hadacolor(t_color a, t_color b);

#endif
