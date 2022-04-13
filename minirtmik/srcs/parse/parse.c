/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <migarcia@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 18:12:04 by migarcia          #+#    #+#             */
/*   Updated: 2022/04/06 20:06:13 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../libft/get_next_line.h"
#include "../../includes/algft.h"
#include "./parse.h"
#include <fcntl.h>

int	ft_parsing_type(t_scene *scene, t_camera *c, t_world *world, char *str)
{
	(void) str;
	int	check;

	check = 0;
	if (str[0] == 'A' && ft_isspacetab(str[1]))
		check = ft_parse_ambient_light(scene, str);
	else if (str[0] == 'C' && ft_isspacetab(str[1]))
		check = ft_parse_camera(scene, c, str);
	else if (str[0] == 'L' && ft_isspacetab(str[1]))
		check = ft_parse_light(scene, world, str);
	else if (str[0] == 's' && str[1] == 'p' && ft_isspacetab(str[2]))
		check = ft_parse_sphere(scene, str);
	else if (str[0] == 'p' && str[1] == 'l' && ft_isspacetab(str[2]))
		check = ft_parse_plane(scene, str);
	else if (str[0] == 'c' && str[1] == 'y' && ft_isspacetab(str[2]))
		check = ft_parse_cylinder(scene, str);
	else if (str[0] == '\n')
		return (0);
	else
		return(ft_error("character invalid."));
	return (check);
}

int	ft_parse(t_scene *scene, t_camera *c, t_world *world, char *file)
{
	int		fd;
	char	*line;
	int		check;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (ft_error("Invalid file."));
	check = 0;
	while (check == 0)
	{
		check = get_next_line(fd, &line);
		if (!check)
			break ;
		check = ft_parsing_type(scene, c, world, line);
		free(line);
	}
	if (!check)
		free(line);
	close (fd);
	return (0);
}

int	ft_check_file(t_scene *scene, t_camera *cam, t_world *world, char *file)
{
	int	fd;
	int	len;
	char	*ext;
	int	e_len;
	
	fd = 0;
	e_len = 2;
	ext = ".rt";
	len = ft_strlen(file) - 1;
	/*while (ext[e_len])
	{
		if (len < 1 || ext[e_len] != file[len])
                	ft_exit("Invalid extension file.", 1);
		e_len--;
		len--;
	}*/
	return (ft_parse(scene, cam, world, file));
}
