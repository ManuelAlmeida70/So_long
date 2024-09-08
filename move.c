/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalmeid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 11:46:29 by maalmeid          #+#    #+#             */
/*   Updated: 2024/08/23 09:04:22 by maalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "minilibx-linux/mlx.h"

void	ft_move_player(t_game *game, int new_x, int new_y)
{
	char	target_tile;

	if (new_x < 0 || new_x >= game->map_width || new_y < 0
		|| new_y >= game->map_height)
		return ;
	target_tile = game->map[new_y][new_x];
	if (!ft_handle_tile_interaction(game, target_tile))
		return ;
	game->map[game->player_y][game->player_x] = '0';
	game->map[new_y][new_x] = 'P';
	game->player_y = new_y;
	game->player_x = new_x;
	game->move_count++;
	ft_printf("%d\n", game->move_count);
	ft_render(game);
}

void	ft_move_up(t_game *game)
{
	int	x;
	int	y;

	x = game->player_x;
	y = game->player_y - 1;
	ft_move_player(game, x, y);
}

void	ft_move_down(t_game *game)
{
	int	x;
	int	y;

	x = game->player_x;
	y = game->player_y + 1;
	ft_move_player(game, x, y);
}

void	ft_move_left(t_game *game)
{
	int	x;
	int	y;

	x = game->player_x - 1;
	y = game->player_y;
	ft_move_player(game, x, y);
}

void	ft_move_right(t_game *game)
{
	int	x;
	int	y;

	x = game->player_x + 1;
	y = game->player_y;
	ft_move_player(game, x, y);
}
