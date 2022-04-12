
#include "../../includes/algft.h"
#include "../../libft/libft.h"
#include "parse.h"
#include <stdio.h>

int     ft_parse_ambient_light(t_scene *scene, char *str)
{
        str++;
        if (scene->amb.n > 0)
                return (ft_error("Ambient lighting is already declared."));
        scene->amb.n++;
        ft_skipspace(&str);
        scene->amb.r = ft_atof(&str);
        if (scene->amb.r < 0.0 || scene->amb.r > 1.0)
                return (ft_error("Ambient lighting ratio out of range."));
        ft_skipspace(&str);
        scene->amb.color = ft_get_color(&str);
        if (scene->amb.color.r == -1)
                return (ft_error("Ambient lighting color out of range."));
        return (0);
}

int     ft_parse_camera(t_scene *scene, char *str)
{
	str++;
	if (scene->nb_cam > 0)
                return (ft_error("Camera is already declared."));
	scene->nb_cam++;
        ft_skipspace(&str);
        scene->cam.point = ft_parse_coor(&str);
        ft_skipspace(&str);
//        scene->cam.orient = ft_norm_vec(ft_parse_coor(&str));
        scene->cam.orient = ft_parse_coor(&str);
        if (scene->cam.orient.x < -1.0 || scene->cam.orient.x > 1.0 || scene->cam.orient.y < -1.0 ||
		scene->cam.orient.y > 1.0 || scene->cam.orient.z < -1.0 || scene->cam.orient.z > 1.0)
                return (ft_error("Camera orientation out of range."));
        ft_skipspace(&str);
        scene->cam.fov = ft_atof(&str);
        if (scene->cam.fov < 0.0 || scene->cam.fov > 180.0)
                return (ft_error("Camera fov out of range."));
	scene->cam.trans = ft_view_trans(scene->cam.point, scene->cam.orient, scene->cam.orient);
	return (0);	
}

/*int     ft_parse_light(t_scene *scene, char *str)
{
        t_light	*new;
        int	i;

        new = malloc(sizeof(t_light) * (scene->nb_light + 1));
        i = -1;
        while (++i < scene->nb_light)
	{
		new[i].pos = scene->world.light[i].pos;
		new[i].bright = scene->world.light[i].bright;
		new[i].i = scene->world.light[i].i;
	}
        str++;
        ft_skipspace(&str);
        new[i].pos = ft_parse_coor(&str);
        ft_skipspace(&str);
        new[i].bright = ft_atof(&str);
        if (new[i].bright < 0.0 || new[i].bright > 1.0)
                return (ft_error("Light brightness out of range."));
        ft_skipspace(&str);
        new[i].i = ft_get_color(&str);
        if (new[i].i.r == -1)
                return (ft_error("Light color out of range."));
	free(scene->world.light);
	scene->world.light = new;
        scene->nb_light++;
        return (0);
}*/

int     ft_parse_light(t_scene *scene, char *str)
{
        str++;
        ft_skipspace(&str);
        scene->world.light.pos = ft_parse_coor(&str);
        ft_skipspace(&str);
        scene->world.light.bright = ft_atof(&str);
        if (scene->world.light.bright < 0.0 || scene->world.light.bright > 1.0)
                return (ft_error("Light brightness out of range."));
        ft_skipspace(&str);
        scene->world.light.i = ft_get_color(&str);
        if (scene->world.light.i.r == -1)
                return (ft_error("Light color out of range."));
	return (0);	
}

