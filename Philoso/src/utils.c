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
    printf("time:%li\n", time);
	while (1)
	{
		if (get_time() - t >= time)
			break ;
		usleep(100);
	}
}

int ft_atoi(const char *nptr)
{
    char *str;
    int i;
    int res;

    str = (char *)nptr;
    if (*str < 32 || (*str > 32 && *str < 48) || *str > 57)
        return (0);
    else
    {
        while (*str == 32)
            str++;
        i = 1;
        res = 0;
        while (*str >= 48 && *str <= 57)
        {
            res = (int)*str - '0' *i ;
            i *= 10;
            str++;
        }
        return(res);
    }
}