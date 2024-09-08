/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalmeid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 09:58:21 by maalmeid          #+#    #+#             */
/*   Updated: 2024/05/15 10:27:52 by maalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	total_len;

	dest_len = 0;
	src_len = 0;
	total_len = 0;
	while (dest[dest_len])
		dest_len++;
	while (src[total_len])
		total_len++;
	if (size <= dest_len)
		total_len += size;
	else
		total_len += dest_len;
	while (src[src_len] && (dest_len + 1) < size)
	{
		dest[dest_len] = src[src_len];
		dest_len++;
		src_len++;
	}
	dest[dest_len] = '\0';
	return (total_len);
}	
