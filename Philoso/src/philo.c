#include "../inc/philo.h"

void	check_dead(t_args *tab)
{
	int	i;

	while (!tab->eaten_all)
	{
		i = -1;
		while (!tab->dead && tab->n_philos > ++i)
		{
			pthread_mutex_lock(&tab->check);
			if (get_time() - tab->philo[i].last_eat > (size_t)tab->t_die)
			{
				printf("\033[1;31mPhilo %i: is dead.\n", tab->philo->id);
				tab->dead = 1;
			}
			pthread_mutex_unlock(&tab->check);
			usleep(100);
		}
		if (tab->dead)
			break ;
		i = 0;
		while (tab->n_eat != -1 && tab->n_philos > i
			&& tab->philo[i].eat_cnt >= tab->n_eat)
			i++;
		if (i == tab->n_philos)
			tab->eaten_all = 1;
	}
}

void    philo_eat(t_philo *philo)
{
    t_args	*tab;

	tab = philo->tab;
	pthread_mutex_lock(&philo->fork);
    printf("\033[1;34mPhilo %i: has taken a fork.\n", philo->id);
    if (philo->tab->n_philos == 1)
    {
        //ft_sleep(philo->tab, philo->tab->t_die);
        printf("\033[1;31mPhilo %i: is dead.\n", tab->philo->id);
        pthread_mutex_unlock(&philo->fork);
        philo->tab->dead = 1;
        return ;
    }
    pthread_mutex_lock(&philo->r_philo->fork);
    printf("\033[1;34mPhilo %i: has taken a fork.\n", philo->id);
    pthread_mutex_lock(&tab->check);
    philo->eat_cnt++;
    printf("\033[0mPhilo %i: is eating. \033[1;90m%i\n", philo->id, philo->eat_cnt);
    philo->last_eat = get_time();
    pthread_mutex_unlock(&tab->check);
    //ft_sleep(tab, tab->t_eat);
    pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(&philo->r_philo->fork);
}

void    *philo_life(void *arg)
{
    t_philo     *philo;

    philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		usleep(1000);
	while (!philo->tab->dead && !philo->tab->eaten_all)
	{
		philo_eat(philo);
        if (!philo->tab->dead && !philo->tab->eaten_all)
		    printf("\033[0mPhilo %i: is sleeping.\n", philo->id);
		ft_sleep(philo->tab->t_slp);
        if (!philo->tab->dead && !philo->tab->eaten_all)
	        printf("\033[0mPhilo %i: is thinking.\n", philo->id);
	}
    return (NULL);
}
