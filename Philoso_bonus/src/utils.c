#include "../inc/philo.h"

int	ft_is_num(char *string)
{
	int	i;

	i = 0;
	while (string[i] != '\0')
	{
		if (string[i] < '0' || string[i] > '9')
			return (1);
		i++;
    }
    return (0);
}

size_t	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	ft_sleep(size_t time)
{
	size_t	t;

	t = get_time();
	while (1)
	{
		if (get_time() - t >= time)
			break ;
		usleep(100);
	}
}

int ft_atoi(const char *nptr)
{
    long    i;
    long    multi;

    multi = 1;
    while (*nptr == ' ' || *nptr == '\t' || *nptr == '\n' || *nptr == '\r'
        || *nptr == '\v' || *nptr == '\f')
        nptr++;
    if (*nptr == '-' || *nptr == '+')
    {
        if (*nptr == '-')
            multi = -1;
        nptr++;
    }
    i = 0;
    while (*nptr >= 48 && *nptr <= 57)
    {
        i *= 10;
        i += (*nptr - '0');
        nptr++;
    }
    return (i * multi);
}
