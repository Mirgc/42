#include "get_next_line.h"

char    *ft_substr(char *s, int start, size_t len)
{
        char    *dst;
        int             i;

        dst = (char *) malloc(len * sizeof(char) + 1);
        if (!dst || !s)
                return (NULL);
        if (start >= ft_strlen(s))
                return (dst);
        i = 0;
        while (len --)
        {
                dst[i] = s[start];
                i++;
                start++;
        }
        dst[i] = '\0';
        return (dst);
}

char	*get_str(char *str, char **line, int filed)
{
	char	*dst;
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (i < ft_strlen(str))
	{
		*line = ft_substr(str, 0 , i);
		dst = ft_substr(str, i + 1, ft_strlen(str));
		free(str);
	}
	else if (filed == 0)
	{
		*line = str;
		dst = NULL;
	}
	return (dst);
}

int	get_next_line(int fd, char **line)
{
	int	filed;
	static char	*str;
	char	buff[BUFFER_SIZE + 1];

	if (BUFFER_SIZE <= 0 || fd < 0 || !line) 
		return (-1);
	while ((filed = read(fd, buff, BUFFER_SIZE)))
	{
		if(filed == -1)
			return (-1);
		buff[filed] = '\0';
		if (str)
			str = join(str, buff);
		else
			str = ft_strdup(buff);
		if (check_ch(str))
			break ;
	}
	if (filed == 0 && !str)
	{
		*line = ft_strdup("");
		return (filed);
	}
	str = get_str(str, line, filed);
	if (filed == 0 && !str)
		return (filed);
	return (1);
}
