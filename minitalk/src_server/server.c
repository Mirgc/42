/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 19:53:37 by migarcia          #+#    #+#             */
/*   Updated: 2021/09/10 19:53:57 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h" 

char	c;

void	ft_action(int sig, siginfo_t *info, void *context)
{
	static pid_t	client_pid;
	static int		bits;

	(void)context;
	if (!client_pid)
		client_pid = info->si_pid;
	if (sig == SIGUSR1)
	{
		c ^= 128 >> bits;
	}
	else if (sig == SIGUSR2)
	{
		c |= 128 >> bits;
	}
	bits++;
	if (bits == 8)
	{
		write(1, &c, 1);
		bits = 0;
		if (!c)
		{
			write(1, "\n", 2);
			kill(client_pid, SIGUSR1);
		}
		c = 0xFF;
	}
	client_pid=0;
}

int	main(void)
{
	struct sigaction	sig;
	pid_t				pid;
	
	c = 0xFF;
	pid = getpid();
	write(1, "Server PID: ", 12);
	ft_putnbr(pid);
	write(1, "\n", 2);
	sig.sa_flags = SA_SIGINFO;
	sig.sa_sigaction = ft_action;
	sigaction(SIGUSR1, &sig, 0);
	sigaction(SIGUSR2, &sig, 0);
	while (1)
		pause();
}

