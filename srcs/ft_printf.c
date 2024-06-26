/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fujitaharuki <fujitaharuki@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 19:58:53 by fujitaharuk       #+#    #+#             */
/*   Updated: 2024/06/26 00:07:56 by fujitaharuk      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	treat_format(va_list args, char format)
{
	if (format == 'c')
		return (printf_putchar(va_arg(args, int)));
	else if (format == 's')
		return (printf_putstr(va_arg(args, char *)));
	else if (format == 'p')
		return (printf_putptr(va_arg(args, unsigned long long)));
	else if (format == 'd' || format == 'i')
		return (printf_putnbr(va_arg(args, int)));
	else if (format == 'u')
		return (printf_putuint(va_arg(args, unsigned int)));
	else if (format == 'x' || format == 'X')
		return (printf_puthex(va_arg(args, unsigned int), format));
	else if (format == '%')
		return (printf_putchar('%'));
	return (0);
}

int	print_cnt(va_list args, const char *str)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			len += treat_format(args, str[i]);
		}
		else
			len += printf_putchar(str[i]);
		i++;
	}
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		ret;

	va_start(args, str);
	ret = print_cnt(args, str);
	va_end(args);
	return (ret);
}
