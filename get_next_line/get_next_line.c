#include "get_next_line.h"

char    *ft_substr(char *s, int start, size_t len)
{
        char    *dst;
        int             i;

        dst = (char *) malloc(len * sizeof(char) + 1);
        if (!dst)
                return (NULL);
		if (!s)
		{
			free(dst);
			return(NULL);
		}
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

	dst = NULL;
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (i < ft_strlen(str))
	{
		*line = ft_substr(str, 0 , i);
		dst = ft_substr(str, i + 1, ft_strlen(str));
		free (str);
	}
	else if (filed == 0)
		*line = str;
	return (dst);
}

int	get_next_line(int fd, char **line)
{
	int	filed;
	static char	*str;
	char	*buff;

	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (-1);
	while ((filed = read(fd, buff, BUFFER_SIZE)))
	{
		if(filed == -1)
		{
			free(buff);
			return (-1);
		}
		buff[filed] = '\0';
		if (str)
			str = join(str, buff);
		else
			str = ft_strdup(buff);
		if (check_ch(str))
			break ;
	}
	free(buff);
	if (filed == 0 && !str)
	{
		*line = ft_strdup("");
		free(str);
		return (filed);
	}
	str = get_str(str, line, filed);
	if (filed == 0 && !str)
	{
		free(str);
		return (filed);
	}
//	if (buff)
//		free (buff);
	return (1);
}
