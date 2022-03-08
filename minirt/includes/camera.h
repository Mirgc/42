#ifndef CAMERA_H
# define CAMERA_H

# include "structs.h"

void		print_camera(t_camera cam);
t_camera	set_camera(double hsize, double vsize, float fov);
t_ray		ray_for_pixel(t_camera cam, double px, double py);
#endif
