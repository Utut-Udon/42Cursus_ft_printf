/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfujita <hfujita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 05:30:28 by fujitaharuk       #+#    #+#             */
/*   Updated: 2024/08/19 14:28:00 by hfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_putchar(char c)
{
	return (write(1, &c, 1));
}

int	printf_putstr(char *str)
{
	int	i;
	int	tmp;

	i = 0;
	if (!str)
		str = "(null)";
	while (str[i])
	{
		tmp = write(1, &str[i], 1);
		if (tmp == -1)
			return (-1);
		i++;
	}
	if (errno != 0)
		return (-1);
	return (i);
}

int	printf_putnbr(int nbr)
{
	char	*num;
	int		len;

	num = ft_itoa(nbr);
	if (!num)
		return (-1);
	len = printf_putstr(num);
	free(num);
	num = NULL;
	if (len == -1)
		return (-1);
	return (len);
}

int	printf_putuint(unsigned int unbr)
{
	char	*num;
	int		len;

	num = ft_utoa(unbr);
	if (!num)
		return (-1);
	len = printf_putstr(num);
	free(num);
	num = NULL;
	if (len == -1)
		return (-1);
	return (len);
}
