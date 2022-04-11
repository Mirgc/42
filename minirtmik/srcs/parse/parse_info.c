
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
        t_camera        *new;
        int             i;

        str++;
        new = malloc(sizeof(t_camera) * scene->nb_cam + 1);
        i = -1;
        while (++i < scene->nb_cam)
                new[i] = scene->cam[i];
        ft_skipspace(&str);
        new[i].point = ft_parse_coor(&str);
        ft_skipspace(&str);
        new[i].orient = ft_norm_vec(ft_parse_coor(&str));
        if (new[i].orient.x < -1.0 || new[i].orient.x > 1.0 || new[i].orient.y < -1.0 ||
                        new[i].orient.y > 1.0 || new[i].orient.z < -1.0 || new[i].orient.x > 1.0)
                return (ft_error("Camera orientation out of range."));
        ft_skipspace(&str);
        new[i].fov = ft_atof(&str);
        if (new[i].fov < 0.0 || new[i].fov > 180.0)
                return (ft_error("Camera fov out of range."));
        new[i] = ft_camera(200, 100, new[i].fov);
        ft_print_tup(new[i].orient);
	scene->cam = new;
        scene->nb_cam++;
	free(new);
        return (0);
}

