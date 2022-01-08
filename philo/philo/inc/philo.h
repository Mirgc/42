/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <migarcia@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 13:41:58 by migarcia          #+#    #+#             */
/*   Updated: 2021/12/26 13:42:13 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo
{
	int				id;
	int				eat_cnt;
	size_t			last_eat;
	pthread_mutex_t	fork;
	struct s_philo	*r_philo;
	struct s_philo	*l_philo;
	struct s_args	*tab;
}				t_philo;

typedef struct s_args
{
	int				t_die;
	int				t_eat;
	int				t_slp;
	int				n_eat;
	int				n_philos;
	int				eaten_all;
	int				dead;
	int				st;
	size_t			t_start;
	size_t			t_init;
	t_philo			*philo;
	pthread_mutex_t	print;
	pthread_mutex_t	check;
}				t_args;

int			ft_is_num(char *string);
size_t		get_time(void);
void		ft_sleep(size_t time);
int			ft_atoi(const char *nptr);
void		ft_printf(char *str, t_philo *philo, int eat, int dead);
void		*philo_life(void *arg);
void		check_dead(t_args *tab);
#endif
