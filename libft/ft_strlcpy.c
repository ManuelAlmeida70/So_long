/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalmeid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 08:55:48 by maalmeid          #+#    #+#             */
/*   Updated: 2024/05/18 08:55:58 by maalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize)
{
	size_t	len_src;
	size_t	index;

	index = 0;
	len_src = ft_strlen((char *)src);
	if (dstsize == 0)
		return (len_src);
	while (src[index] && index < dstsize - 1)
	{
		dest[index] = src[index];
		index++;
	}
	dest[index] = '\0';
	return (len_src);
}
