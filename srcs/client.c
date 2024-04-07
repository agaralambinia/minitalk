#include "../incs/minitalk.h"

void	send_binary(char *message, int pidid)
{
	char	letter;
	int		i;
	int		power;

	i = 0;
	while (message[i])
	{
		power = 128;
		letter = message[i];
		while (power > 0)
		{
			if (letter >= power)
			{
				kill(pidid, SIGUSR1);
				letter -= power;
			}
			else
				kill(pidid, SIGUSR2);
			power /= 2;
			usleep(500);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	pidid;

	if (argc != 3)
		return (-1);
	pidid = ft_atoi(argv[1]);
	send_binary(argv[2], pidid);
	return (0);
}
