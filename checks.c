/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalmeid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 14:23:22 by maalmeid          #+#    #+#             */
/*   Updated: 2024/08/27 14:34:04 by maalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_ways(char **map)
{
	int	y;
	int	x;

	if (!map)
		return (0);
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (map[y][x] == 'C')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int	ft_check_ways1(char **map)
{
	int	y;
	int	x;

	if (!map)
		return (0);
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (map[y][x] == 'E')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}
