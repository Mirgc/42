
#include "../../includes/algft.h"
#include "../../libft/libft.h"
#include "parse.h"
#include <stdio.h>

int     ft_parse_sphere(t_scene *scene, char *str)
{
	t_shape	sp;
	t_tuple	org;
	float	di;

        str++;
        str++;
        ft_skipspace(&str);
        org = ft_parse_coor(&str);
        ft_skipspace(&str);
	di = ft_atof(&str);
	sp.c = 's';
	sp.s = ft_sphere(org, di);
	sp.s.transform = ft_scal_matrix(di, 0.01, di);
        ft_skipspace(&str);
	sp.s.mat.color = ft_get_color(&str);
        if (sp.s.mat.color.r == -1)
                return (ft_error("Sphere color out of range."));
//	sp.s.mat.shininess *= scene->world.light[0].bright;
//	sp.s.mat.ambient *= scene->amb.r;
	scene->world = ft_add_world(scene->world, sp);
        return (0);
}
