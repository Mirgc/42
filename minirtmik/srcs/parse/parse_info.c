
int	ft_parse_ambient_light(t_scene scene, char *str)
{
	if (scene.amb.n > 0)
		return (ft_error("Ambient lighting is already declared.\n");
	scene.amb.n++;
	ft_skipspace(&str);
	scene.amb.r = ft_atof(&str);
	if (scene.amb.r < 0.0 || scene.amb.r > 1.0)
		return (ft_error("Ambient lighting ratio out of range.\n");
	ft_skipspace(&str);
	scene.amb.col = ft_get_color(&str);	
	if (scene.amb.col.r == -1)
		return (ft_error("Ambient lighting color out of range.\n");
}
