/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalmeid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 19:23:41 by maalmeid          #+#    #+#             */
/*   Updated: 2024/06/06 19:23:49 by maalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_ft_countwordls(int n)
{
	int	wordls;

	wordls = 0;
	if (n < 0)
	{
		wordls++;
		n *= -1;
	}
	if (n == 0)
		wordls++;
	while (n != 0)
	{
		n = n / 10;
		wordls++;
	}
	return (wordls);
}

int	ft_ft_unsigned(unsigned int n)
{
	int	length;
	int	i;

	i = 0;
	length = ft_ft_countwordls(n);
	if (n == 2147483648)
		return (ft_ft_putstr("2147483648"));
	if (n > 9)
	{
		i = i + (n % 10);
		ft_ft_unsigned(n / 10);
		i = i + '0';
		write(1, &i, 1);
		return (length);
	}
	else
	{
		n += '0';
		write(1, &n, 1);
	}
	return (length);
}
