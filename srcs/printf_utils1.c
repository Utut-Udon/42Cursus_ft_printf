/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fujitaharuki <fujitaharuki@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 05:30:28 by fujitaharuk       #+#    #+#             */
/*   Updated: 2024/06/25 23:52:21 by fujitaharuk      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	printf_putstr(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	printf_putnbr(int nbr)
{
	char	*num;
	int		len;

	num = ft_itoa(nbr);
	if (!num)
		return (0);
	len = printf_putstr(num);
	free(num);
	num = NULL;
	return (len);
}

int	printf_putuint(unsigned int unbr)
{
	char	*num;
	int		len;

	num = ft_itoa(unbr);
	if (!num)
		return (0);
	len = printf_putstr(num);
	free(num);
	num = NULL;
	return (len);
}
