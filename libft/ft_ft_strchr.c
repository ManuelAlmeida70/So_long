/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalmeid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 19:21:23 by maalmeid          #+#    #+#             */
/*   Updated: 2024/06/06 19:21:32 by maalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_ft_strchr(const char *str, int c)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (str[i])
		i++;
	while (i >= j)
	{
		if (str[j] == (char)c)
			return (1);
		j++;
	}
	return (0);
}
