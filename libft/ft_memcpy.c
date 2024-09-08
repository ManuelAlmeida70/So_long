/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalmeid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 11:56:49 by maalmeid          #+#    #+#             */
/*   Updated: 2024/05/15 13:06:07 by maalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*ptr_dest;
	const char	*ptr_src;

	ptr_dest = (char *)dest;
	ptr_src = (const char *)src;
	if (n != 0 && dest != src)
	{
		while (n--)
		{
			*ptr_dest++ = *ptr_src++;
		}
	}
	return (dest);
}
