#include "server.h" 

char	c;

/*void	handler_sigusr(int signum)
{
   static int	bits;

   if (signum == SIGUSR1)
   {
   	c ^= 128 >> bits;
   }
   else if (signum == SIGUSR2)
   {
   	c |= 128 >> bits;
   }
   bits++;
   if (bits == 8)
   {
   	write(1, &c, 1);
   	bits = 0;
   	c = 255;
   }
}*/

void	ft_action(int sig, siginfo_t *info, void *context)
{
	static int				i = 0;
	static pid_t			client_pid;
	static int   bits;

	(void)context;
	if (!client_pid)
		client_pid = siginfo->si_pid;

   if (signum == SIGUSR1)
   {
    c ^= 128 >> bits;
   }
   else if (signum == SIGUSR2)
   {
    c |= 128 >> bits;
   }
   bits++;
   if (bits == 8)
   	{
    	write(1, &c, 1);
	    bits = 0;
	    c = 255;
		if (!c)
		{
			kill(client_pid, SIGUSR1);
			return ;
		}
	}
}

int	main(void)
{
   struct sigaction sig;
   pid_t		pid;

   c = 255;
   pid = getpid();
   write(1, "Server PID: ", 12);
   ft_putnbr(pid);
   write(1, "\n", 2);
   sig.sa_flags = SA_SIGINFO;
   sig.sa_sigaction = ft_action;
   sigaction(SIGUSR1, &sig, 0);
   sigaction(SIGUSR2, &sig, 0);
//   signal(SIGUSR1, handler_sigusr);
//   signal(SIGUSR2, handler_sigusr);
   while (1)
   	pause();
}

