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

void	send_signals(char *message, int pid)
{
   int	i;
   int	shift;

   shift = -1;
   i = 0;
   while (message[i])
   {
   	while (++shift < 8)
   	{
   		if (message[i] & 128 >> shift)
   		{
   			if (kill(pid, SIGUSR2) == -1)
   				exit(1);
   		}
   		else
   		{
   			if (kill(pid, SIGUSR1) == -1)
   				exit (1);
   		}
   		usleep(3);
   	}
	shift = -1;
   	i++;
   }
}

void recev()
{
	write(1, "Message has been received", 25);
}

int	main(int argc, char *argv[])
{
   int		pid;

   if (argc != 3)
   {
   	write(1, "ERROR - Use:> ./client SERVER_PID MESSAGE\n", 43);
   	return (1);
   }
   signal(SIGUSR1, recev);
   pid = ft_atoi(argv[1]);
   send_signals(argv[2], pid);
   send_signals("\n", pid);
   return (0);
}
