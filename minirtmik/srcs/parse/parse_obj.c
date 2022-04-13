
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
	sp.s = ft_sphere(ft_point(0, 0, 0), 1.0);
	sp.s.transform = ft_mult_matrix(ft_transla_matrix(org.x, org.y, org.z), ft_scal_matrix(di, di, di));
        ft_skipspace(&str);
	sp.s.mat.color = ft_get_color(&str);
        if (sp.s.mat.color.r == -1)
                return (ft_error("Sphere color out of range."));
	scene->world = ft_add_world(scene->world, sp);
        return (0);
}

int     ft_parse_plane(t_scene *scene, char *str)
{
	t_shape	pl;
	t_tuple	org;
	t_tuple	coor;

        str++;
        str++;
        ft_skipspace(&str);
        org = ft_parse_coor(&str);
        ft_skipspace(&str);
        coor = ft_parse_coor(&str);
        if (coor.x < -1.0 || coor.x > 1.0 || coor.y < -1.0 ||
		coor.y > 1.0 || coor.z < -1.0 || coor.z > 1.0)
                return (ft_error("Plane 3D vector out of range."));
	pl.c = 'p';
	pl.p = ft_plane();
        ft_skipspace(&str);
	pl.p.mat.color = ft_get_color(&str);
        if (pl.p.mat.color.r == -1)
                return (ft_error("Plane color out of range."));
	scene->world = ft_add_world(scene->world, pl);
        return (0);
}

int	ft_parse_cylinder(t_scene *scene, char *str)
{
	t_shape	cy;
	t_tuple	org;
	t_tuple	coor;
	float	di;
	float	hi;

        str++;
        str++;
        ft_skipspace(&str);
        org = ft_parse_coor(&str);
        ft_skipspace(&str);
        coor = ft_parse_coor(&str);
        if (coor.x < -1.0 || coor.x > 1.0 || coor.y < -1.0 ||
		coor.y > 1.0 || coor.z < -1.0 || coor.z > 1.0)
                return (ft_error("Cylinder 3D vector out of range."));
        ft_skipspace(&str);
	di = ft_atof(&str);
        ft_skipspace(&str);
	hi = ft_atof(&str);
	cy.c = 'c';
	pl.cy = ft_cylinder();
        ft_skipspace(&str);
	cy.cy.mat.color = ft_get_color(&str);
        if (pl.cy.mat.color.r == -1)
                return (ft_error("Cylinder color out of range."));
	scene->world = ft_add_world(scene->world, cy);
        return (0);
}
