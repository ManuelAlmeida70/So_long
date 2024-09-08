/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalmeid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 10:13:01 by maalmeid          #+#    #+#             */
/*   Updated: 2024/08/22 10:16:27 by maalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_sl_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	return (i);
}

int	ft_count_elements(t_game *game, char element)
{
	int	y;
	int	x;
	int	count;

	count = 0;
	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (game->map[y][x] != '\0')
		{
			if (game->map[y][x] == element)
				count++;
			x++;
		}
		y++;
	}
	return (count);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		*s1++;
		*s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
