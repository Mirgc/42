#include <unistd.h>
#include <stdio.h>

void	ft_make_table(int *val);

int	ft_check_val(char *argv, int *val)
{
	int	pos_num;

	pos_num = 0;
	while (*argv && pos_num <= 16)
	{
		if ((*argv >= '1' && *argv <= '4')
			&& (*(argv + 1) == ' ' || *(argv + 1) == 0))
		{
			val[pos_num] = ((int)(*argv - '0'));
			argv++;
			pos_num++;
		}
		if (*argv == ' ' && (*(argv + 1) >= '1' && *(argv + 1) <= '4')
			&& pos_num !=0)
			argv++;
		else if (*argv != 0)
			return (0);
	}
	return (pos_num);
}

int	main(int argc, char **argv)
{
	int	val[16];
	int	len;

	if (argc == 2)
	{
		len = ft_check_val(argv[1], val);
		if (len != 16)
		{
			write(1, "Error\n", 6);
			return (0);
		}
		else
			ft_make_table(&val[0]);
	}
	else
		write(1, "Error\n", 6);
	return (0);
}
