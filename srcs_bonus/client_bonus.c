#include "../incs/minitalk.h"

void	info_func(int sigusrid)
{
	if (sigusrid == SIGUSR1)
		ft_printf("INFO Server received message\n");
}

void	send_clid(unsigned int c, int pidserv)
{
	unsigned int		power;

	power = 2147483648;
	while (power > 0)
	{
		if (c >= power)
		{
			kill(pidserv, SIGUSR1);
			c -= power;
		}
		else
			kill(pidserv, SIGUSR2);
		power /= 2;
		usleep(300);
	}
	usleep(600);
}

void	send_char(unsigned char c, int pidserv)
{
	int		power;

	power = 128;
	while (power > 0)
	{
		if (c >= power)
		{
			kill(pidserv, SIGUSR1);
			c -= power;
		}
		else
			kill(pidserv, SIGUSR2);
		power /= 2;
		usleep(300);
	}
	usleep(600);
}

int	main(int argc, char **argv)
{
	int	pidid;
	int	i;

	i = 0;
	if (argc != 3)
		return (-1);
	signal(SIGUSR1, info_func);
	pidid = ft_atoi(argv[1]);
	send_clid(getpid(), pidid);
	while (argv[2][i])
	{
		send_char(argv[2][i], pidid);
		i++;
	}
	send_char('\0', pidid);
	return (0);
}
