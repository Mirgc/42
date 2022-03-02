#include "structs.h"
#include "matrix.h"
#include "tuples.h"
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

t_ray	ray_for_pixel(t_camera cam, double px, double py)
{
	double	xoffset;
	double	yoffset;
	double	world_x;
	double	world_y;
	t_tup	pixel;
	t_ray	ray;

	xoffset = (px + 0.5) * cam.pixel_size;
	yoffset = (py + 0.5) * cam.pixel_size;
	world_x = cam.hw - xoffset;
	world_y = cam.hh - yoffset;
	pixel = m_multi_tup(m_invertible(cam.transform), v_create(world_x, world_y, -1, 1));
	ray.ori = m_multi_tup(m_invertible(cam.transform), v_create(0, 0, 0, 1));
	ray.dir = v_normalize(v_substract(pixel, ray.ori));
	return (ray);
}
