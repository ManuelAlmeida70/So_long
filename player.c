/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalmeid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 14:19:03 by maalmeid          #+#    #+#             */
/*   Updated: 2024/08/22 16:57:35 by maalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "minilibx-linux/mlx.h"

void	ft_player_position(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < ft_strlen(game->map[y]))
		{
			if (game->map[y][x] == 'P')
			{
				game->player_x = x;
				game->player_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

int	ft_handle_tile_interaction(t_game *game, char target_tile)
{
	if (target_tile == '1')
		return (0);
	if (target_tile == 'C')
	{
		game->collectible_count--;
		if (game->collectible_count == 0)
			ft_printf("Todos colecionaveis pego!\n");
	}
	if (target_tile == 'E')
	{
		if (game->collectible_count != 0)
			return (0);
		game->move_count++;
		ft_printf("%d\n", game->move_count);
		ft_printf("JOGO TERMINADO!!!\n");
		ft_end_game(game);
	}
	return (1);
}
