/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <migarcia@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 17:37:39 by migarcia          #+#    #+#             */
/*   Updated: 2021/12/19 19:48:44 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	check_dead(void *arg)
{
	t_philo	*philo;
	t_args	*tab;

	philo = (t_philo *)arg;
	tab = philo->tab;
	while (1)
	{
		sem_wait(tab->check);
		if (get_time() - philo->last_eat > (size_t)tab->t_die)
		{
			printf("\033[1;31m[%lu] Philo %i: is dead.\n", get_time() - tab->t_init, tab->philo->id);
			sem_wait(tab->print);
			tab->dead = 1;
			exit (1);
		}
		sem_post(tab->check);
		if (tab->dead)
			break ;
		usleep(100);
		if (tab->n_eat != -1 && philo->eat_cnt >= tab->n_eat)
			break ;
	}
	return (NULL);
}

void    philo_eat(t_philo *philo)
{
    t_args	*tab;

	tab = philo->tab;
	sem_wait(philo->tab->fork);
    ft_printf("has taken a fork.", philo, 0);
    if (philo->tab->n_philos == 1)
    {
        ft_sleep(philo->tab->t_die);
		printf("\033[1;31m[%lu] Philo %i: is dead.\n", get_time() - tab->t_init, tab->philo->id);
        sem_post(philo->tab->fork);
        philo->tab->dead = 1;
        return ;
    }
    sem_wait(philo->tab->fork);;
    ft_printf("has taken a fork.", philo, 0);
	sem_wait(philo->tab->check);
    philo->eat_cnt++;
    ft_printf("is eating. \033[1;90m", philo, 1);
    philo->last_eat = get_time();
    sem_post(philo->tab->check);
    ft_sleep(tab->t_eat);
    sem_post(philo->tab->fork);
	sem_post(philo->tab->fork);
}

void    *philo_life(void *arg)
{
    t_philo     *philo;

    philo = (t_philo *)arg;
	while (1)
	{
	   	if (philo->tab->st)
			break ;
	}
	if (philo->id % 2 == 0)
		usleep(1000);
	while (!philo->tab->dead && !philo->tab->eaten_all)
	{
		philo_eat(philo);
		if (tab->n_eat != -1 && philo->eat_cnt >= tab->n_eat)
			break ;
		ft_printf("is sleeping.", philo, 0);
		ft_sleep(philo->tab->t_slp);
		ft_printf("is thinking.", philo, 0);
	}
    return (NULL);
}
