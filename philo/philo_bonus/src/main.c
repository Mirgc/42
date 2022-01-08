/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <migarcia@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 17:37:45 by migarcia          #+#    #+#             */
/*   Updated: 2021/12/26 13:09:53 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	fill_sem(t_args *tab)
{
	sem_unlink("/sem_print");
	sem_unlink("/sem_check");
	sem_unlink("/sem_fork");
	tab->print = sem_open("/sem_print", O_CREAT, 0644, 1);
	tab->check = sem_open("/sem_check", O_CREAT, 0644, 1);
	tab->fork = sem_open("/sem_fork", O_CREAT, 0644, tab->n_philos);
	if (tab->print <= 0 || tab->check <= 0 || tab->fork <= 0)
	{
		write(1, "Error: sem_open failed\n", 23);
		exit(1);
	}
}

void	fill_philo(t_args *tab)
{
	int	i;

	tab->philo = malloc(sizeof(t_philo) * tab->n_philos);
	i = -1;
	while (tab->n_philos > ++i)
	{
		tab->philo[i].id = i + 1;
		tab->philo[i].eat_cnt = 0;
		tab->philo[i].last_eat = 0;
		if (i + 1 == tab->n_philos)
			tab->philo[i].r_philo = &tab->philo[0];
		else
			tab->philo[i].r_philo = &tab->philo[i + 1];
		if (i == 0)
			tab->philo[i].l_philo = &tab->philo[tab->n_philos - 1];
		else
			tab->philo[i].l_philo = &tab->philo[i - 1];
		tab->philo[i].tab = tab;
	}
	fill_sem(tab);
}

void	fill_tab(int argc, char **argv, t_args *tab)
{
	tab->t_init = get_time();
	tab->t_start = tab->t_init + 3000;
	tab->n_philos = ft_atoi(argv[1]);
	tab->t_die = ft_atoi(argv[2]);
	tab->t_eat = ft_atoi(argv[3]);
	tab->t_slp = ft_atoi(argv[4]);
	tab->n_eat = -1;
	if (argc == 6)
		tab->n_eat = ft_atoi(argv[5]);
	tab->dead = 0;
	tab->st = 0;
	tab->eaten_all = 0;
	fill_philo(tab);
}

int	main(int argc, char **argv)
{
	t_args		tab;
	int			i;

	if (check_args(argv, argc))
		return (1);
	fill_tab(argc, argv, &tab);
	i = -1;
	while (tab.n_philos > ++i)
	{
		tab.philo[i].pid = fork();
		if (tab.philo[i].pid < 0)
		{
			write(1, "Error: fork failed\n", 19);
			exit(1);
		}
		if (tab.philo[i].pid == 0)
			philo_life((void *)&tab.philo[i]);
	}
	exit_philo(&tab);
	return (0);
}
