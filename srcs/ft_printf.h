/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfujita <hfujita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 20:04:22 by fujitaharuk       #+#    #+#             */
/*   Updated: 2024/08/01 17:53:05 by hfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../srcs/libft/libft.h"
# include <errno.h>
# include <stdarg.h>

int		treat_format(va_list args, char format);
int		print_cnt(va_list args, const char *str);
int		ft_printf(const char *str, ...);
int		printf_putchar(char c);
int		printf_putstr(char *str);
int		printf_putnbr(int nbr);
int		printf_putuint(unsigned int unbr);
int		hex_len(unsigned int num);
void	ft_puthex(unsigned int num, const char format);
int		printf_puthex(unsigned int num, const char format);
int		ptr_len(unsigned long long num);
void	ft_putptr(unsigned long long num);
int		printf_putptr(unsigned long long num);

#endif