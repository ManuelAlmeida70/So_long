/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalmeid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 08:21:34 by maalmeid          #+#    #+#             */
/*   Updated: 2024/08/22 11:24:26 by maalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_is_rectangular(t_game *game)
{
	int	y;

	y = 0;
	while (game->map[y])
	{
		if (game->map_width != ft_strlen(game->map[y]))
		{
			ft_printf("Error\no mapa nao e rectangular\n");
			ft_end_game(game);
		}
		y++;
	}
}

void	ft_is_wall(t_game *game)
{
	int	y;
	int	x;

	x = 0;
	while (game->map[0][x] != '\0')
	{
		if (game->map[0][x] != '1' || game->map[game->map_height - 1][x] != '1')
		{
			ft_printf("Error\no mapa não está cercado por parede\n");
			ft_end_game(game);
		}
		x++;
	}
	y = 0;
	while (y < game->map_height)
	{
		if (game->map[y][0] != '1' || game->map[y][game->map_width - 1] != '1')
		{
			ft_printf("Error\no mapa não está cercado por parede\n");
			ft_end_game(game);
		}
		y++;
	}
}

void	ft_count_player(t_game *game, char element)
{
	int	count_player;

	count_player = ft_count_elements(game, element);
	if (count_player != 1)
	{
		ft_printf("Error\no mapa deve conter apenas um jogador\n");
		ft_end_game(game);
	}
}

void	ft_count_exit_and_collectible(t_game *game)
{
	int	count_exit;
	int	count_collectible;

	count_exit = 0;
	count_collectible = 0;
	count_exit = ft_count_elements(game, 'E');
	if (count_exit != 1)
	{
		ft_printf("Error\no mapa de conter apenas um saida\n");
		ft_end_game(game);
		exit(1);
	}
	game->collectible_count = ft_count_elements(game, 'C');
	if (game->collectible_count == 0)
	{
		ft_printf("Error\no mapa de conter pelo menos um colecionavel\n");
		ft_end_game(game);
	}
}

void	ft_validate(t_game *game)
{
	ft_is_rectangular(game);
	ft_is_wall(game);
	ft_count_exit_and_collectible(game);
	ft_count_player(game, 'P');
}
