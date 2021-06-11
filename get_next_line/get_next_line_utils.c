#include "get_next_line.h"

void	*ft_memmove(char *dst, char *src, int len)
{
	int	i;

	if (!dst || !src)
		return (NULL);
	if (dst > src)
	{
		i = len - 1;
		while (i >= 0)
		{
			dst[i] = src[i];
			i--;
		}
	}
	else
	{
		i = 0;
		while (i < len)
		{
			dst[i] = src[i];
			i++;
		}
	}
	return (dst);
}
int	ft_strlen(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*join(char *s1, char *s2)
{
	char	*dst;
	int	s1_len;
	int	s2_len;
	int	len_tot;

	if (!s1 && !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	len_tot = s1_len + s2_len + 1;
	dst = malloc(sizeof(char) * len_tot);
	if(!dst)
		return (NULL);
	ft_memmove(dst, s1, s1_len);
	ft_memmove(dst + s1_len, s2, s2_len);
	dst[len_tot -1] = '\0';
	return (dst);
}

int	check_ch(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
