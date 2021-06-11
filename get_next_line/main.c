#include "get_next_line.h"
#include <fcntl.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*int main(int argc, char **argv)
{
	int	fd;
	char	*line;
	(void)argc;
	int a;

	a = 0;
	line = NULL;
	fd = open(argv[1], O_RDONLY);
	a = get_next_line(fd, &line);
	a = get_next_line(fd, &line);
	close(fd);
	return (0);
}*/


int main()
{
	        int             fd;
        int             i;
        int             j;
        char                    *line = 0;
        char                    *lineadress[66];

        j = 1;
        printf("\n==========================================\n");
        printf("========== TEST 1 : The Alphabet =========\n");
        printf("==========================================\n\n");

        if (!(fd = open("alphabet", O_RDONLY)))
        {
                printf("\nError in open\n");
                return (0);
        }
        while ((i = get_next_line(fd, &line)) > 0)
        {
                printf("|%s\n", line);
                lineadress[j - 1] = line;
                j++;
        }
        printf("|%s\n", line);
        free(line);
        close(fd);

        if (i == -1)
                printf ("\nError in Fonction - Returned -1\n");
        else if (j == 66)
                printf("\nRight number of lines\n");
        else if (j != 66)
                printf("\nNot Good - Wrong Number Of Lines\n");
        while (--j > 0)
                free(lineadress[j - 1]);

}
