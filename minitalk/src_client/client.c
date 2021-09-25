/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 19:54:24 by migarcia          #+#    #+#             */
/*   Updated: 2021/09/11 10:46:04 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

int	ft_atoi(char *str)
{
	int	i;
	int	num;

	i = 1;
	num = 0;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			i *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		num *= 10;
		num += *str - '0';
		str++;
	}
	return (num * i);
}

int	ft_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	i++;
	return (i);
}

void	send_signals(char *message, int pid)
{
	int	i;
	int	len;
	int	bits;

	len = ft_len(message);
	i = -1;
	while (i++ <= len)
	{
		bits = -1;
		while (++bits < 8)
		{
			if (message[i] & 128 >> bits)
			{
				if (kill(pid, SIGUSR2) == -1)
					exit(1);
			}
			else
			{
				if (kill(pid, SIGUSR1) == -1)
					exit (1);
			}
			usleep(100);
		}
	}
}

void	recev(int a)
{
	(void)a;
	write(1, "Message has been received", 26);
	exit (0);
}

int	main(int argc, char *argv[])
{
	int	pid;

	if (argc != 3)
	{
		write(1, "ERROR - Use:> ./client SERVER_PID MESSAGE\n", 43);
		return (1);
	}
	signal(SIGUSR1, recev);
	pid = ft_atoi(argv[1]);
	send_signals(argv[2], pid);
	while (1)
		pause();
	return (0);
}
