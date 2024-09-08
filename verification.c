/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verification.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalmeid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 13:08:38 by maalmeid          #+#    #+#             */
/*   Updated: 2024/08/27 14:20:40 by maalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_arguments(int ac)
{
	if (ac != 2)
	{
		ft_printf("Error\nargumentos invalidados\n");
		exit(1);
	}
}

void	ft_verification1(t_game *game)
{
	char	**map;

	map = ft_copy_map(game);
	ft_flood_fill(map, game->player_x, game->player_y);
	if (ft_check_ways(map) == 0)
	{
		ft_free_copy(map);
		ft_printf("Error\no mapa nao e jogavel\n");
		ft_end_game(game);
	}
	ft_free_copy(map);
}

void	ft_verification2(t_game *game)
{
	char	**map;

	map = ft_copy_map(game);
	ft_flood_fill1(map, game->player_x, game->player_y);
	if (ft_check_ways1(map) == 0)
	{
		ft_free_copy(map);
		ft_printf("Error\no mapa nao e jogavel\n");
		ft_end_game(game);
	}
	ft_free_copy(map);
}
