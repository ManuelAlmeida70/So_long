/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalmeid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 08:21:34 by maalmeid          #+#    #+#             */
/*   Updated: 2024/08/22 08:50:58 by maalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_height_map(const char *map_path)
{
	char	*line;
	int		height;
	int		fd;

	fd = open(map_path, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error\nErro ao abrir o mapa\n");
		exit(1);
	}
	height = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		height++;
		free(line);
	}
	close(fd);
	return (height);
}

void	ft_read_map(t_game *game, const char *map_path)
{
	int	fd;

	game->map_height = ft_height_map(map_path);
	if (game->map_height == 0)
	{
		ft_printf("Error\no mapa esta vazio\n");
		exit(1);
	}
	game->map = (char **)malloc(sizeof(char *) * (game->map_height + 1));
	if (!game->map)
	{
		ft_printf("Error\nErro ao alocar memoria para o mapa\n");
		return ;
	}
	fd = open(map_path, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error\nErro ao abrir o mapa\n");
		exit(1);
	}
	ft_fill_map(game, fd);
	close(fd);
}

void	ft_fill_map(t_game *game, int fd)
{
	char	*line;
	int		y;
	int		x;

	y = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		game->map[y] = (char *)malloc(sizeof(char) * (ft_sl_strlen(line) + 1));
		x = 0;
		while (line[x] && line[x] != '\n')
		{
			game->map[y][x] = line[x];
			x++;
		}
		game->map[y][x] = '\0';
		y++;
		free(line);
	}
	game->map_width = ft_strlen(game->map[0]);
	game->map[y] = NULL;
}
