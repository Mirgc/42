#ifndef PARSE_H
#define PARSE_H

//PARSE//
int	ft_check_file(t_scene *scene, t_camera *cam, t_world *world, char *file);

//PARSE_UTILS//
void	ft_skipspace(char **str);
int	ft_comma(char **str);
t_color	ft_get_color(char **str);
t_tuple ft_parse_coor(char **str);

//PARSE_INFO//
int     ft_parse_ambient_light(t_scene *scene, char *str);
int     ft_parse_camera(t_scene *scene, t_camera *c, char *str);
int     ft_parse_light(t_scene *scene, t_world *world, char *str);

//PARSE_OBJ//
int	ft_parse_sphere(t_scene *scene, char *str);
int	ft_parse_plane(t_scene *scene, char *str);
int	ft_parse_cylinder(t_scene *scene, char *str);

#endif 
