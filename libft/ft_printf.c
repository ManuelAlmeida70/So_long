/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalmeid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 19:18:52 by maalmeid          #+#    #+#             */
/*   Updated: 2024/06/06 19:19:00 by maalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(const char *format, ...)
{
	va_list	list;
	int		length;
	int		i;

	va_start(list, format);
	i = 0;
	length = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%' && ft_ft_strchr("cspdiuxX%", format[i + 1]))
		{
			length = ft_ft_printc(format, i, length, list);
			i++;
		}
		else
		{
			length += ft_ft_putchar(format[i]);
		}
		i++;
	}
	va_end(list);
	return (length);
}
