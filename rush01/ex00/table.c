#include <unistd.h>
#include <stdio.h>

int	ft_row_intro(int *val, int i, int table[4][4], int *cont);

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_table(int table[4][4])
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			ft_putchar((char)(table [i][j] + '0'));
			ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

int	ft_intr_table(int *val, int table[4][4])
{
	int	cont1;
	int	cont2;
	int	cont3;
	int	cont4;
	int	no_print;

	no_print = 0;
	cont1 = 0;
	cont2 = 0;
	cont3 = 0;
	cont4 = 0;
	if (ft_row_intro(val, 9, table, &cont1) == 1)
		return (1);
	if (ft_row_intro(val, 10, table, &cont2) == 1)
		return (1);
	if (ft_row_intro(val, 11, table, &cont3) == 1)
		return (1);
	if (ft_row_intro(val, 12, table, &cont4) == 1)
		return (1);
	return (0);
}

void	ft_make_table(int *val)
{
	int	table [4][4];
	int	i;
	int	j;
	int	no_print;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			table [i][j] = 0;
			j++;
		}
		i++;
	}
	no_print = ft_intr_table(val, table);
	if (no_print == 0)
		ft_print_table(table);
	else
		write(1, "Error\n", 6);
}
