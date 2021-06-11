#include "get_next_line.h"

char	*get_line(char *str)
{
	char	*dst;
	int	i;

	if (!str)
		return (NULL);
	i = 0;
	while(str[i] != '\n')
		i++;
	dst = malloc(sizeof(char) * (i + 1));
	if (!dst)
		return (NULL);
	i = 0;
	while(str[i] && str[i] != '\n')
	{
		dst[i] = str[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*get_str(char *str)
{
	char	*dst;
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	dst = malloc(sizeof(char) * (ft_strlen(str) - i) + 1);
	if (!dst)
		return (NULL);
	i++;
	while (str[i])
	{
		dst[j] = str[i];
		j++;
		i++;
	}
	dst[j] = '\0';
	free(str);
	return (dst);
}

int	get_next_line(int fd, char **line)
{
	int	filed;
	static char	*str;
	char	*buff;
	(void)line;

	if (BUFFER_SIZE <= 0 || fd < 0 || !line) 
		return (-1);
	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (-1);
	filed = 1;
	while (!check_ch(str) && filed != 0)
	{
		if((filed = read(fd, buff, BUFFER_SIZE)) == -1)
		{
			free(buff);
			return (-1);
		}
		buff[filed] = '\0';
		str = join(str, buff);
	}
	*line = get_line(str);
	str = get_str(str);
	free(buff);
	if (filed == 0)
		return (0);
	return (1);
}
