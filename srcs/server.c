#include "../incs/minitalk.h"

void	bin_to_char(char *binchar)
{
	int		i;
	int		power;
	char	bit;
	int		result;

	i = 7;
	while (binchar[i])
	{
		power = 1;
		result = 0;
		while (power < 129)
		{
			bit = binchar[i];
			if (bit == '1')
				result += power;
			power *= 2;
			i--;
		}
		ft_putchar(result);
	}
}

void	sig_to_bin(int sigusrid)
{
	static int	i = 0;
	static char	binchar[8];

	if (sigusrid == SIGUSR1)
		binchar[i] = '1';
	else if (sigusrid == SIGUSR2)
		binchar[i] = '0';
	i++;
	if (i == 8)
	{
		i = 0;
		bin_to_char(binchar);
	}
}

int	main()
{
	ft_printf("%i\n", getpid());
	signal(SIGUSR1, sig_to_bin);
	signal(SIGUSR2, sig_to_bin);
	while (1)
		sleep(1);
	return (0);
}
