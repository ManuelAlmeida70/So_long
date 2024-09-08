/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexadecimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalmeid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 19:17:37 by maalmeid          #+#    #+#             */
/*   Updated: 2024/06/06 19:17:44 by maalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_ft_hexadecimal(unsigned long long int nbr, char *base)
{
	int	length;

	length = 0;
	if (nbr >= 16)
	{
		length += ft_ft_hexadecimal((nbr / 16), base);
		length += ft_ft_hexadecimal((nbr % 16), base);
	}
	else
	{
		write(1, &base[nbr], 1);
		length++;
	}
	return (length);
}
