/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osurcouf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 14:24:46 by osurcouf          #+#    #+#             */
/*   Updated: 2021/06/28 17:37:25 by osurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** 🦕
**
** function : Generate the ray from the camera to the scene
**				and handle all the aspect ratios problems
**
**	In this very important step, we basically create a 2D
**	plane, a matrix, parallel to the 'lense' of the camera.
**	We'll see the 'scene' (or 'world') through its scale.
**	It will allow us to determine the orientation of the
**	ray coming from the camera.
**	
**
**	1. Look-at
**		We create a matrix out of our camera position &
**		orientation. This will set how 'up', 'right',
**		'forward' and 'right' should be understood by it.
**	2. Getting our 2D plane vector
**		We get a unit vector to the right aspect ratio *
**		vertical Field of View
**	3. We get our fully sized scene matrix
**		We scale the unit vector to the whole matrix so
**		that we get the right dimensions.
**	4. We get the orientation of the plane
**		So that it's perpendicular to the camera's orientation.
**	5. We normalize that orientation (always normalize an orient)
**	6. Now we have the origin and orientation of the ray that's
**		gonna hit our pixel.
**
** 🦕
*/

static t_vec	multiply_by_matrix(t_vec ray, t_matrix cam)
{
	t_vec	multi;

	multi.x = ray.x * cam.m[0][0] + ray.y * cam.m[1][0]
		+ ray.z * cam.m[2][0] + cam.m[3][0];
	multi.y = ray.x * cam.m[0][1] + ray.y * cam.m[1][1]
		+ ray.z * cam.m[2][1] + cam.m[3][1];
	multi.z = ray.x * cam.m[0][2] + ray.y * cam.m[1][2]
		+ ray.z * cam.m[2][2] + cam.m[3][2];
	return (multi);
}

static t_matrix	look_at(t_vec cam_origin, t_vec cam_dir)
{
	t_matrix	cam_to_world;
	t_vec		random;
	t_vec		forward;
	t_vec		right;
	t_vec		up;

	random = normalize(create_vec(0.0, 1.0, 0.0));
	forward = normalize(substract(cam_origin, cam_dir));
	right = normalize(cross_product(random, forward));
	up = normalize(cross_product(forward, right));
	cam_to_world.m[0][0] = right.x;
	cam_to_world.m[0][1] = right.y;
	cam_to_world.m[0][2] = right.z;
	cam_to_world.m[1][0] = up.x;
	cam_to_world.m[1][1] = up.y;
	cam_to_world.m[1][2] = up.z;
	cam_to_world.m[2][0] = cam_dir.x;
	cam_to_world.m[2][1] = cam_dir.y;
	cam_to_world.m[2][2] = cam_dir.z;
	cam_to_world.m[3][0] = cam_origin.x;
	cam_to_world.m[3][1] = cam_origin.y;
	cam_to_world.m[3][2] = cam_origin.z;
	return (cam_to_world);
}

static t_vec	get_2D_plane(int x, int y, t_rt *rt)
{
	float	horizontal_fov;
	float	aspect_ratio;
	float	x_ratio;
	float	y_ratio;
	t_vec	res;

	res.x = (float)rt->infos->scene->res.x;
	res.y = (float)rt->infos->scene->res.y;
	horizontal_fov = tan((rt->curr.cam.FOV / 2) * (M_PI / 180));
	aspect_ratio = res.y / res.x;
	x_ratio = ((x + 0.5) / (res.x / 2) - 1) * horizontal_fov;
	y_ratio = (1 - (y + 0.5) / (res.y / 2)) * aspect_ratio * horizontal_fov;
	return (create_vec(x_ratio, y_ratio, 1));
}

void	gen_cam_ray(int x, int y, t_rt *rt)
{
	t_matrix	cam_to_world;
	t_camera	*cam;
	t_vec		unit_vector_2D;
	t_vec		matrix_plane_2D;
	t_vec		orient_plane_2D;

	cam = &rt->curr.cam;
	cam_to_world = look_at(cam->point, cam->orient);
	rt->cam_ray.origin = cam->point;
	unit_vector_2D = get_2D_plane(x, y, rt);
	matrix_plane_2D = multiply_by_matrix(unit_vector_2D, cam_to_world);
	orient_plane_2D = substract(matrix_plane_2D, rt->cam_ray.origin);
	rt->cam_ray.dir = normalize(orient_plane_2D);
}
