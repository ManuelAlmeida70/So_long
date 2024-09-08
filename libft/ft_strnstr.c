/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalmeid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 13:41:26 by maalmeid          #+#    #+#             */
/*   Updated: 2024/05/17 18:55:50 by maalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!*little)
		return ((char *)big);
	if (len == 0)
		return (NULL);
	while (big[i] != '\0' && i < len)
	{
		j = 0;
		while ((big[i + j] != '\0') && (little[j] != '\0')
			&& ((i + j) < len) && (big[i + j] == little[j]))
		{
			if (little[j + 1] == '\0')
				return ((char *)&(big[i]));
			j++;
		}
		i++;
	}
	return (NULL);
}
