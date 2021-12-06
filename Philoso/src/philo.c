#include "../inc/philo.h"

void    *philo_life(void *arg)
{
    t_philo     *philo;

    philo = (t_philo *)arg;
	if (philo->id % 2 != 0)
		usleep(100);
	
	pthread_mutex_lock(&philo->fork);
	pthread_mutex_lock(&philo->l_philo->fork);
    printf("Philo %i: has taken a fork.\n", philo->id);
    printf("Philo %i: has taken a fork.\n", philo->id);
    printf("Philo %i: is eating.\n", philo->id);
	pthread_mutex_unlock(&philo->l_philo->fork);
	pthread_mutex_unlock(&philo->fork);

    return (NULL);
}
