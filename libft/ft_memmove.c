/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalmeid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 08:03:16 by maalmeid          #+#    #+#             */
/*   Updated: 2024/05/16 08:31:49 by maalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*p_dest;
	const char	*p_src;

	p_dest = (char *)dest;
	p_src = (const char *)src;
	if (p_dest < p_src)
	{
		while (n--)
		{
			*p_dest++ = *p_src++;
		}
	}
	else
	{
		p_dest += n;
		p_src += n;
		while (n--)
		{
			*(--p_dest) = *(--p_src);
		}
	}
	return (dest);
}
