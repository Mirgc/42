#include "../inc/philo.h"

int	check_args(char **argv, int argc)
{
	int	i;

	i = 0;
	if (argc < 5 || argc > 6)
	{
		write(1, "Error: wrong argument number\n", 29);
		return (1);
	}
	while (++i < argc)
	{
		if (argv[i][0] == '-' || ft_is_num(argv[i])
			|| ft_atoi(argv[i]) == 0)
		{
			write(1, "Error: Invalid Arguments\n", 25);
			return (1);
		}
	}
	return (0);
}

void    fill_philo(t_args *tab)
{
    int i;

    tab->philo = malloc(sizeof(t_philo) * tab->n_philos);
    i = -1;
    while (tab->n_philos > ++i)
    {
        tab->philo[i].id = i + 1;
        tab->philo[i].eat_cnt = 0;
        tab->philo[i].last_eat = 0;
    	tab->philo[i].life = tab->t_die;
    	tab->philo[i].die = tab->t_die;
        if (i + 1 == tab->n_philos)
            tab->philo[i].r_philo = &tab->philo[0];
        else
            tab->philo[i].r_philo = &tab->philo[i + 1];
        if (i == 0)
			tab->philo[i].l_philo = &tab->philo[tab->n_philos - 1];
		else
			tab->philo[i].l_philo = &tab->philo[i - 1];
        tab->philo[i].tab = tab;
		pthread_mutex_init(&tab->philo[i].fork, NULL);
	}
    pthread_mutex_init(&tab->print, NULL);
    pthread_mutex_init(&tab->check, NULL);
}

void    fill_tab(int argc, char **argv, t_args *tab)
{
    tab->t_init = get_time();
	tab->n_philos = ft_atoi(argv[1]);
    tab->t_die = ft_atoi(argv[2]);
    tab->t_eat = ft_atoi(argv[3]);
    tab->t_slp = ft_atoi(argv[4]);
    tab->n_eat = -1;
    if (argc == 6)
        tab->n_eat = ft_atoi(argv[5]);
    tab->dead = 0;
    tab->eaten_all = 0;
    fill_philo(tab);
}

int	main(int argc, char **argv)
{
	t_args		tab;
    pthread_t   *tid;
    int         i;

	if (check_args(argv, argc))
		return (1);
	fill_tab(argc, argv, &tab);
    tid = (pthread_t *)malloc(tab.n_philos * sizeof(pthread_t));
    if (!tid)
        return (1);
    i = -1;
    while (tab.n_philos > ++i)
    {
        if (pthread_create(&tid[i], NULL, &philo_life, (void *)&tab.philo[i]))
	    {
	        write(1, "Error: cannot create thread\n", 28);
            free(tab.philo);
            free(tid);
            return (1);
        }
		usleep(1000);
    }
	i = -1;
	while (tab.n_philos > ++i)
		pthread_join(tid[i], NULL);

	return (0);
}
