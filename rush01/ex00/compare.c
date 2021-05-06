#include <stdio.h>
#include <unistd.h>

void	ft_3_2(int i, int table[4][4], int *cont);
void	ft_3_1(int i, int table[4][4], int *cont);
void	ft_2_3(int i, int table[4][4], int *cont);
void	ft_2_2_1(int i, int table[4][4], int *cont);
void	ft_2_2_2(int i, int table[4][4], int *cont);
void	ft_2_1(int i, int table[4][4], int *cont);
void	ft_1_3(int i, int table[4][4], int *cont);
void	ft_1_2(int i, int table[4][4], int *cont);

void	ft_row_1(int *val, int i, int table[4][4], int *cont)
{
	int	j;

	j = 0;
	while (j < 4)
	{
		j++;
		val++;
	}
	if (*val == 4)
	{
		table[i - 9][0] = 4;
		table[i - 9][1] = 3;
		table[i - 9][2] = 2;
		table[i - 9][3] = 1;
		cont++;
	}
	else if (*val == 3 && *cont < 3)
		ft_1_3(i, table, cont);
	else if (*val == 2 && *cont < 2)
		ft_1_2(i, table, cont);
}

void	ft_row_2(int *val, int i, int table[4][4], int *cont)
{
	int	j;

	j = 0;
	while (j < 4)
	{
		j++;
		val++;
	}
	if (*val == 3 && *cont < 3)
		ft_2_3(i, table, cont);
	else if (*val == 2 && *cont < 6)
	{
		if (*cont < 3)
			ft_2_2_1(i, table, cont);
		else
			ft_2_2_2(i, table, cont);
	}
	else if (*val == 1 && *cont < 2)
		ft_2_1(i, table, cont);
}

void	ft_row_3(int *val, int i, int table[4][4], int *cont)
{
	int	j;

	j = 0;
	while (j < 4)
	{
		j++;
		val++;
	}
	if (*val == 2 && *cont < 3)
	{
		ft_3_2(i, table, cont);
		cont++;
	}
	else if (*val == 1 && *cont < 3)
	{
		ft_3_1(i, table, cont);
		cont++;
	}
}

int	ft_row_intro(int *val, int i, int table[4][4], int *cont)
{
	int	j;

	j = 0;
	while (j < i -1)
	{
		j++;
		val++;
	}
	if (*val == 4 && *(val + 4) == 1)
	{
		table[i - 9][0] = 1;
		table[i - 9][1] = 2;
		table[i - 9][2] = 3;
		table[i - 9][3] = 4;
		cont++;
	}
	else if (*val == 3)
		ft_row_3(val, i, table, cont);
	else if (*val == 2)
		ft_row_2(val, i, table, cont);
	else if (*val == 1)
		ft_row_1(val, i, table, cont);
	else
		return (1);
	return (0);
}
