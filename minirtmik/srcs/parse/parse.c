
int	ft_parsing_type(t_scene scene, char *str)
{
	int check;

	check = 0;
	if (str[0] == 'A' && ft_is_spacetab(str[1]))
		check = ft_parse_ambient_light(world, str);
	else if(str[0] == 'C' && ft_is_spacetab(str[1]))
		check = ft_parse_camera(world, str);
	else if(str[0] == 'L' && ft_is_spacetab(str[1]))
		check = ft_parse_light(world, str);
        else if (str[0] == 's' && str[1] == 'p' && ft_is_spacetab(str[2])
		check = ft_parse_sphere(world, str);
        else if (str[0] == 'p' && str[1] == 'l' && ft_is_spacetab(str[2])
		check = ft_parse_plane(world, str);
        else if (str[0] == 'c' && str[1] == 'y' && ft_is_spacetab(str[2])
		check = ft_parse_cylinder(world, str);
        else if (str[0] == '\n')
		return (0);
	else
		check = ft_error("character invalid.\n");
	return (check);
}

int	ft_parse(t_scene scene, char *file)
{
	int	fd;
	char	*line;
	int	check;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (ft_error("Invalid file.\n"));
	check = 0;
	while (check == 0)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		check = ft_parsing_type(scene, line);
		free(line);
	}
	close (fd);
	return (0);
}

int	ft_check_file(t_scene scene, char *file)
{
	int	fd;
	int	len;
	char	*ext;
	int	e_len;
	int	check;
	
	fd = 0;
	e_len = 2;
	ext = ".rt";
	len = ft_strlen(file) - 1;
	while (ext[e_len])
	{
		if (len < 1 || ext[e_len] != file[len])
                	ft_error("Invalid extension file.\n");
		e_len--;
		len--;
	}
	return (ft_parse(scene, file));
}
