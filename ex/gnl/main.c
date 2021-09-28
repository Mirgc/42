#include "get_next_line.h"
#include <fcntl.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    int             fd;
    int             j;
    char            *line = 0;
    (void)          argc;

    j = 1;
    printf("\n==========================================\n");
    printf("========== TEST 1 : The Alphabet =========\n");
    printf("==========================================\n\n");

    if (!(fd = open(argv[1], O_RDONLY)))
    {
        printf("\nError in open\n");
        return (0);
    }
    while ((line = get_next_line(fd)))
    {
        printf("%s", line);
        free(line);
    }
    printf("%s\n", line);
    free(line);
    close(fd);
}
