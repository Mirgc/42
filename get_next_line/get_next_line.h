#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
int     get_next_line(int fd, char **line);
char    *ft_strchr(char *str, int ch);
int     ft_strlen(char *str);
char    *join(char *s1, char *s2);
char    *ft_strdup(char *s1);
#endif
