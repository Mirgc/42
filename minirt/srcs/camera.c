#include "structs.h"
#include "matrix.h"
#include <math.h>
#include <stdio.h>

void	print_camera(t_camera cam)
{
	printf("-----CAMERA-----\n");
	printf("hsize: %f, vsize: %f, fov: %f\n", cam.hsize, cam.vsize, cam.fov);
	printf("hw: %f, hh: %f, pixel_size: %f\n", cam.hw, cam.hh, cam.pixel_size);
	print_matrix(cam.transform);
	printf("----------------\n");
}

t_camera	set_camera(double hsize, double vsize, double fov)
{
	t_camera	cam;
	double		half_view;
	double		aspect;

	cam.hsize = hsize;
	cam.vsize = vsize;
	cam.fov = fov;
	half_view = tan(cam.fov / 2);
	aspect = cam.hsize / cam.vsize;
	if (aspect >= 1)
	{
		cam.hw = half_view;
		cam.hh = half_view / aspect;
	}
	else
	{
		cam.hw = half_view * aspect;
		cam.hh = half_view;
	}
	cam.pixel_size = (cam.hw * 2) /cam.hsize;
	cam.transform = m_identity();
	return (cam);
}
