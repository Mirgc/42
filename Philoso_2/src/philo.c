#include "../inc/philo.h"

void    *philo_life(void *arg)
{
    t_philo     *philo;

    philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		usleep(100);
	
	philo->life = get_time() + philo->tab->t_die;
	pthread_mutex_lock(&philo->fork);
    printf("[%ld] Philo %i: has taken a fork.\n", philo->life - get_time(), philo->id);
	pthread_mutex_lock(&philo->r_philo->fork);
    printf("[%ld] Philo %i: has taken a fork.\n", philo->life - get_time(), philo->id);
	philo->eat_cnt++;
	philo->die = ft_sleep(philo->tab->t_eat);
    printf("[%ld] Philo %i: is eating. #%i\n", philo->life - philo->die, philo->id, philo->eat_cnt);
	philo->last_eat = get_time();
	pthread_mutex_unlock(&philo->r_philo->fork);
	pthread_mutex_unlock(&philo->fork);

    return (NULL);
}
