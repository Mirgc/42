#include <unistd.h>

int	main(int argc, char **argv)
{
	char line[255] = {0};
	int i;

	if (argc == 3)
	{
		i = 0;
		while(argv[2][i])
		{
			line[(unsigned int)argv[2][i]] = 1;
			i++;
		}
		i = 0;
		while(argv[1][i])
		{
			if(line[(unsigned int)argv[1][i]] == 1)
			{
				write(1, &argv[1][i], 1);
				line[(unsigned int)argv[1][i]] = 2;
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
