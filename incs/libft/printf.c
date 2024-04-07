/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: defimova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 21:20:54 by defimova          #+#    #+#             */
/*   Updated: 2024/01/28 21:20:56 by defimova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_conv(char c, va_list ap)
{
	int	cnt;

	cnt = 0;
	if (c == 'c')
		cnt += ft_putchar(va_arg(ap, int));
	else if (c == 's')
		cnt += ft_putstr(va_arg(ap, char *));
	else if (c == 'p')
		cnt += ft_putp((unsigned long int)va_arg(ap, long long));
	else if ((c == 'd') || (c == 'i'))
		cnt += nbrb((long)va_arg(ap, int), 10, 0);
	else if (c == 'u')
		cnt += nbrb((long)va_arg(ap, unsigned int), 10, 0);
	else if (c == 'x')
		cnt += nbrb((long)va_arg(ap, unsigned int), 16, 0);
	else if (c == 'X')
		cnt += nbrb((long)va_arg(ap, unsigned int), 16, 1);
	else if (c == '%')
		cnt += write(1, &c, 1);
	return (cnt);
}

int	ft_printf(const char *f, ...)
{
	va_list	ap;
	int		cnt;

	va_start(ap, f);
	cnt = 0;
	while (*f)
	{
		if (*f == '%')
			cnt += print_conv(*(++f), ap);
		else
			cnt += write(1, f, 1);
		f++;
	}
	return (cnt);
}
