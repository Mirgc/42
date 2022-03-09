/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pixel_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osurcouf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 14:22:36 by osurcouf          #+#    #+#             */
/*   Updated: 2021/06/30 13:15:05 by osurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** 🦕
**
** function : calculates the color of the result pixel
**
**	1. If the camera ray doesn't hit anything, returns the
**		ambient color by it's light. If it hits an object
**		it goes get the color of that object.
**		Note : object brightness has to be 0.0
**				so that we can store the added light
**				brightness if there's more than 1 light.
**	2. Get the object brightness.
**		Calculate how much light is hitting the object with
**		a ray going from the light to the hit point.
**		Note : If there is more than one light, we'll iterate
**				over all of them, add together their ratios &
**				color, and give it as a result.
**	3. Check if the object is in the shadow or not.
**		If it is, object brightness is 0.0. To check, we send
**		a ray from the hit point to the light. If it hits
**		another object, then it is in the shadows.
**		Note : more advanced raytracing algorithms take into
**				account the color and the distance with this
**				object to determine what color will the final
**				pixel be since in the natural world, the color
**				we see is a result of light bouncing off of
**				everything, basically.
**	4. We calculate the actual color of the pixel.
**		Once we have the brightness ratio of our object color,
**		we need to mix in the object color, the light color, and
**		the ambient color * light.	
**
** 🦕
*/

static bool	in_shadow(t_rt *rt, int k)
{
	t_vec	light_position;
	t_rec	temp;
	float	hit_dist;
	int		i;

	light_position = rt->infos->scene->light[k].point;
	rt->shadow_ray.origin = rt->curr.hit.point;
	rt->shadow_ray.dir = substract(light_position, rt->curr.hit.point);
	rt->curr.dist_max = length(rt->shadow_ray.dir);
	rt->curr.dist_min = rt->curr.dist_max;
	rt->shadow_ray.dir = normalize(rt->shadow_ray.dir);
	i = 0;
	while (i < rt->infos->nb_objs)
	{
		temp.obj = rt->infos->objs[i];
		hit_dist = intersect_obj(&rt->shadow_ray, &temp);
		if (hit_dist > 0.001f && hit_dist < rt->curr.dist_min)
			rt->curr.dist_min = hit_dist;
		i++;
	}
	if (rt->curr.dist_min < rt->curr.dist_max)
		return (true);
	return (false);
}

static float	get_obj_brightness(t_rt *rt, float obj_brightness, int k)
{
	float	light_gain;
	float	light_brightness;
	float	cosine;
	float	ray_distance;

	light_brightness = rt->infos->scene->light[k].bright;
	light_gain = dot_product(rt->curr.hit.normal,
			normalize(rt->light_ray.dir));
	cosine = length(rt->light_ray.dir);
	if (light_gain <= 0.0)
		obj_brightness = 0.0;
	else
	{
		ray_distance = M_PI * cosine;
		obj_brightness = (light_brightness * light_gain * 1000.0f)
			/ ray_distance;
		if (in_shadow(rt, k))
			obj_brightness = 0.0;
	}
	return (obj_brightness);
}

static float	get_obj_color(t_rt *rt, float obj_brightness, t_color ambient)
{
	t_color	light_color;
	t_color	add_brightness;
	t_color	add_previous_light;
	t_color	add_ambient;
	int		k;

	k = 0;
	add_previous_light = set(0, 0, 0);
	while (k < rt->infos->scene->nb_light)
	{
		rt->light_ray.origin = rt->infos->scene->light[k].point;
		rt->light_ray.dir = substract(rt->light_ray.origin, rt->curr.hit.point);
		obj_brightness = get_obj_brightness(rt, obj_brightness, k);
		if (obj_brightness > 1.0)
			obj_brightness = 1.0;
		light_color = rt->infos->scene->light[k].color;
		add_brightness = color_multiply(light_color, obj_brightness);
		add_previous_light = color_add(add_previous_light, add_brightness);
		k++;
	}
	add_ambient = color_add(add_previous_light, ambient);
	rt->curr.obj.color = color_add(rt->curr.obj.color, add_ambient);
	rt->curr.obj.color = convert_to_max(rt->curr.obj.color);
	return (create_color(rt->curr.obj.color));
}

void	get_pixel_color(t_rt *rt)
{
	float	obj_brightness;
	t_color	amb_color;
	t_color	amb_light;

	obj_brightness = 0.0;
	amb_color = rt->infos->scene->amb.color;
	amb_light = color_multiply(amb_color, rt->infos->scene->amb.r);
	if (rt->curr.hit.t > 0.0 && rt->curr.hit.t != INFINITY)
		rt->curr.pix_color = get_obj_color(rt, obj_brightness, amb_light);
	else
		rt->curr.pix_color = create_color(amb_light);
}
