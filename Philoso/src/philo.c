#include "../inc/philo.h"

void    *philo_life(void *arg)
{
    t_philo     *philo;

    philo = (t_philo *)arg;
    printf("Philo %i: has taken a fork.\n", philo->id);
    return (NULL);
}