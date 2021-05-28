#include "libft.h"
void *ft_calloc(size_t n, size_t size)
{
	void *buff;

	if (!(buff = (char *)malloc(n * size)))
		return (0);
	return (ft_memset(buff, '0', size));
}
