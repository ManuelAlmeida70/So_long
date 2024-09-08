/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playable.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalmeid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 12:11:36 by maalmeid          #+#    #+#             */
/*   Updated: 2024/08/26 13:53:36 by maalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "minilibx-linux/mlx.h"

char	**ft_copy_map(t_game *game)
{
	char	**map_copy;
	int		y;
	int		x;

	map_copy = (char **)malloc(sizeof(char *) * (game->map_height + 1));
	if (!map_copy)
		return (NULL);
	y = 0;
	while (y < game->map_height)
	{
		map_copy[y] = (char *)malloc(sizeof(char) * (game->map_width + 1));
		if (!map_copy[y])
			return (NULL);
		x = 0;
		while (x < game->map_width)
		{
			map_copy[y][x] = game->map[y][x];
			x++;
		}
		map_copy[y][x] = '\0';
		y++;
	}
	map_copy[y] = NULL;
	return (map_copy);
}

void	ft_flood_fill(char **map, int x, int y)
{
	if (map[y][x] == '1' || map[y][x] == 'F' || map[y][x] == 'E')
		return ;
	map[y][x] = 'F';
	ft_flood_fill(map, x + 1, y);
	ft_flood_fill(map, x - 1, y);
	ft_flood_fill(map, x, y + 1);
	ft_flood_fill(map, x, y - 1);
}

void	ft_flood_fill1(char **map, int x, int y)
{
	if (map[y][x] == '1' || map[y][x] == 'F')
		return ;
	map[y][x] = 'F';
	ft_flood_fill1(map, x + 1, y);
	ft_flood_fill1(map, x - 1, y);
	ft_flood_fill1(map, x, y + 1);
	ft_flood_fill1(map, x, y - 1);
}

void	ft_free_copy(char **map)
{
	int	y;

	y = 0;
	while (map[y])
	{
		if (map[y])
			free(map[y]);
		y++;
	}
	free(map);
}
