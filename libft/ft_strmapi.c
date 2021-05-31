#include "libft.h"
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	int	i;
	
	if(!s)
		return (NULL);
	str = (char *)malloc(ft_strlen(s) * sizeof(char) + 1);
	if (!str)
		return (NULL);
	i = 0;
	while(s[i])
	{
		str[i] = f(i, ((char *)s)[i]);
		i++;
	}
	str[i]='\0';
	return (str);
}
