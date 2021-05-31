#include "libft.h"
void ft_putnbr_fd(int n, int fd)
{
	char	nb;
	
	if (n == -2147483648)
	{
		write (fd, "-2", 2);
		n = 147483648;
	}
	if (n < 0)
	{
		write (fd, "-", 1);
		n *= -1;
	}
	if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10,fd);
	}
	if (n <= 10)
	{
		nb = n + '0';
                write(fd, &nb, 1);
	}
}
