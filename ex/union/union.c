int ft_str(char *str)
{
	int i;

	i = 0;
	while(str[i])
		i++;
	return (i);
}

void	ft_compare(char *dst, char *str)
{
	int i;
	int j;
	int k;

	k = 0;
	i = 0;
	while(str[i])
	{
		j = 0;
		while (dst[j])
		{
			if(str[i] == dst[j])
			{
				k = 1;
				break ;
			}
			j++;
			k = 0;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int cont;	
	if (argc == 3)
	{
		ft_compare(dst, argv[1]);
		ft_compare(dst, argv[2]);
		ft_putstr(dst);
	}
	write(1, '\n', 1);
}
