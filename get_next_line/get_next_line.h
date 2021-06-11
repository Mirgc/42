#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <fcntl.h>
# include <unistd.h>
# include <sys/stat.h>
# include <stdlib.h>
int     get_next_line(int fd, char **line);
int     check_ch(char *str);
int     ft_strlen(char *str);
char    *join(char *s1, char *s2);
#endif
