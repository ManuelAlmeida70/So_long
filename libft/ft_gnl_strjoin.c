/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl_strjoin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalmeid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 10:25:30 by maalmeid          #+#    #+#             */
/*   Updated: 2024/08/21 12:39:51 by maalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_gnl_strjoin(char *s1, const char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	str = (char *)malloc(ft_gnl_strlen(s1) + ft_gnl_strlen(s2) + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		++i;
	}
	j = 0;
	while (s2[j])
	{
		str[i] = s2[j];
		++j;
		++i;
	}
	free(s1);
	str[i] = '\0';
	return (str);
}
