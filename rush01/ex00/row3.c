void	ft_3_2(int i, int table[4][4], int *cont)
{
	if (*cont == 0)
	{
		table[i - 9][0] = 2;
		table[i - 9][1] = 3;
		table[i - 9][3] = 1;
	}
	if (*cont == 1)
	{
		table[i - 9][0] = 1;
		table[i - 9][1] = 3;
		table[i - 9][3] = 2;
	}
	if (*cont == 2)
	{
		table[i - 9][0] = 1;
		table[i - 9][1] = 2;
		table[i - 9][3] = 3;
	}
	table[i - 9][2] = 4;
	cont++;
}

void	ft_3_1(int i, int table[4][4], int *cont)
{
	if (*cont == 0)
	{
		table[i - 9][0] = 1;
		table[i - 9][1] = 3;
		table[i - 9][2] = 2;
	}
	if (*cont == 1)
	{
		table[i - 9][0] = 2;
		table[i - 9][1] = 1;
		table[i - 9][2] = 3;
	}
	if (*cont ==2)
	{
		table[i - 9][0] = 2;
		table[i - 9][1] = 3;
		table[i - 9][2] = 1;
	}
	table[i - 9][3] = 4;
	cont++;
}
