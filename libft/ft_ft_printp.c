/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalmeid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 19:23:19 by maalmeid          #+#    #+#             */
/*   Updated: 2024/06/06 19:23:27 by maalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_ft_printp(unsigned long long int nbr)
{
	int	length;

	length = 0;
	if (nbr == 0)
	{
		write(1, "(nil)", 5);
		return ((length += 5));
	}
	write(1, "0x", 2);
	return ((length += ft_ft_hexadecimal(nbr, "0123456789abcdef") + 2));
}
