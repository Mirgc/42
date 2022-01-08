/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <migarcia@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 17:37:39 by migarcia          #+#    #+#             */
/*   Updated: 2021/12/26 13:33:59 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
				ft_printf(NULL, tab->philo, 0, 1);
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

void	philo_eat(t_philo *philo)
{
	t_args	*tab;

	tab = philo->tab;
	pthread_mutex_lock(&philo->fork);
	ft_printf("has taken a fork.", philo, 0, 0);
	if (philo->tab->n_philos == 1)
	{
		ft_sleep(philo->tab->t_die);
		ft_printf(NULL, tab->philo, 0, 1);
		pthread_mutex_unlock(&philo->fork);
		philo->tab->dead = 1;
		return ;
	}
	pthread_mutex_lock(&philo->r_philo->fork);
	ft_printf("has taken a fork.", philo, 0, 0);
	pthread_mutex_lock(&tab->check);
	philo->eat_cnt++;
	ft_printf("is eating. \033[1;90m", philo, 1, 0);
	philo->last_eat = get_time();
	pthread_mutex_unlock(&tab->check);
	ft_sleep(tab->t_eat);
	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(&philo->r_philo->fork);
}

void	*philo_life(void *arg)
{
	t_philo	*philo;

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
		ft_printf("is sleeping.", philo, 0, 0);
		ft_sleep(philo->tab->t_slp);
		ft_printf("is thinking.", philo, 0, 0);
	}
	return (NULL);
}
