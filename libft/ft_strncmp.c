/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalmeid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 08:59:25 by maalmeid          #+#    #+#             */
/*   Updated: 2024/05/18 08:59:35 by maalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while ((i < n - 1) && (*(const unsigned char *)(s1
			+ i) == *(const unsigned char *)(s2 + i))
		&& *(const unsigned char *)(s1 + i) && *(const unsigned char *)(s2 + i))
	{
		i++;
	}
	return ((*(const unsigned char *)(s1 + i)
		-*(const unsigned char *)(s2 + i)));
}
