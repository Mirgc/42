void	ft_1_3(int i, int table[4][4], int *cont)
{
	if (*cont == 0)
	{
		table[i - 9][1] = 1;
		table[i - 9][2] = 3;
		table[i - 9][3] = 2;
	}
	if (*cont == 1)
	{
		table[i - 9][1] = 2;
		table[i - 9][2] = 3;
		table[i - 9][3] = 1;
	}
	if (*cont == 2)
	{
		table[i - 9][1] = 3;
		table[i - 9][2] = 1;
		table[i - 9][3] = 2;
	}
	table[i - 9][0] = 4;
	cont++;
}

void	ft_1_2(int i, int table[4][4], int *cont)
{
	if (*cont == 0)
	{
		table[i - 9][1] = 1;
		table[i - 9][2] = 2;
		table[i - 9][3] = 3;
	}
	if (*cont == 1)
	{
		table[i - 9][1] = 2;
		table[i - 9][2] = 1;
		table[i - 9][3] = 3;
	}
	table[i - 9][0] = 4;
	cont++;
}
