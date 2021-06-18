#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
int     check_ch(char *str);
int     get_next_line(int fd, char **line);
int     ft_strlen(char *str);
char    *join(char *s1, char *s2);
char    *ft_strdup(char *s1);
char    *ft_substr(char *s, int start, size_t len);
#endif
