/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <migarcia@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 17:48:31 by migarcia          #+#    #+#             */
/*   Updated: 2021/12/19 19:48:47 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	ft_printf(char *str, t_philo *philo, int eat)
{
	pthread_mutex_lock(&philo->tab->print);
	if (!philo->tab->dead && !philo->tab->eaten_all)
	{
		if (philo->tab->n_eat != -1 && eat)
		{
			printf("\033[0m[%lu] Philo %i: %s %i\n", 
					get_time() - philo->tab->t_init, philo->id, str, philo->eat_cnt);
		}
		else
		{
				printf("\033[0m[%lu] Philo %i: %s\n",
                        get_time() - philo->tab->t_init, philo->id, str);
		}
	}
	pthread_mutex_unlock(&philo->tab->print);
}
