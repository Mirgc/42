#include "server.h" 

char	c;

void	handler_sigusr(int signum)
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
}

int	main(void)
{
   pid_t		pid;

   c = 255;
   pid = getpid();
   write(1, "Server PID: ", 12);
   ft_putnbr(pid);
   write(1, "\n", 2);
   signal(SIGUSR1, handler_sigusr);
   signal(SIGUSR2, handler_sigusr);
   while (1)
   	pause();
}

