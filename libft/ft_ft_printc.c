/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalmeid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 19:17:57 by maalmeid          #+#    #+#             */
/*   Updated: 2024/06/06 19:18:05 by maalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_ft_printc(const char *format, int i, int length, va_list list)
{
	if (format[i + 1] == 's')
		return (length += ft_ft_putstr(va_arg(list, char *)));
	else if (format[i + 1] == 'c')
		return ((length += ft_ft_putchar(va_arg(list, int))));
	else if (format[i + 1] == 'i' || format[i + 1] == 'd')
		return ((length += ft_ft_putnbr(va_arg(list, int))));
	else if (format[i + 1] == 'p')
		return ((length += ft_ft_printp(va_arg(list, unsigned long long int))));
	else if (format[i + 1] == 'u')
		return ((length += ft_ft_unsigned(va_arg(list, unsigned int))));
	else if (format[i + 1] == 'x')
		return ((length += ft_ft_hexadecimal(va_arg(list, unsigned int),
					"0123456789abcdef")));
	else if (format[i + 1] == 'X')
		return ((length += ft_ft_hexadecimal(va_arg(list, unsigned int),
					"0123456789ABCDEF")));
	else if (format[i + 1] == '%')
		return ((length += ft_ft_putchar('%')));
	return (length);
}
