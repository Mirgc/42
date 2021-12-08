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
	long			life;
	long			die;
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
	size_t			t_init;
	t_philo			*philo;
	pthread_mutex_t	print;
	pthread_mutex_t	check;
}				t_args;

int		ft_is_num(char *string);
long	get_time(void);
long	ft_sleep(long time);
int		ft_atoi(const char *nptr);
void	*philo_life(void *arg);
#endif
