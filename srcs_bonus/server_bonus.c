/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: defimova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 11:53:06 by defimova          #+#    #+#             */
/*   Updated: 2024/04/07 11:53:08 by defimova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minitalk_bonus.h"

static int	g_clid;

void	eofbyte(unsigned int *power, int *result, int *bit)
{
	if (*result == 0)
	{
		*bit = 0;
		*power = 2147483648;
	}
	else
	{
		ft_putchar(*result);
		*power = 128;
		*bit = 32;
		*result = 0;
	}
}

void	eofclid(int *result, unsigned int *power)
{
	g_clid = *result;
	*result = 0;
	*power = 128;
}

void	sig_to_bin(int sigusrid)
{
	static unsigned int		power = 2147483648;
	static int				result = 0;
	static int				bit = 0;

	if (bit <= 31)
	{
		if (sigusrid == SIGUSR1)
			result += power;
		if (bit == 31)
			eofclid(&result, &power);
		else
			power /= 2;
	}
	if (bit >= 32 && bit <= 39)
	{
		if (sigusrid == SIGUSR1)
			result += power;
		power /= 2;
		kill(g_clid, SIGUSR1);
	}
	bit++;
	if (bit == 40)
		eofbyte(&power, &result, &bit);
}

int	main(void)
{
	ft_printf("%i\n", getpid());
	signal(SIGUSR1, sig_to_bin);
	signal(SIGUSR2, sig_to_bin);
	while (1)
		sleep(1);
	return (0);
}
