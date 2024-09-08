/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalmeid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 08:21:34 by maalmeid          #+#    #+#             */
/*   Updated: 2024/08/21 12:57:46 by maalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "minilibx-linux/mlx.h"

void	ft_free_map(t_game *game)
{
	int		y;

	y = 0;
	while (game->map[y])
	{
		free(game->map[y]);
		y++;
	}
	free(game->map);
}

void	ft_end_game(t_game *game)
{
	if (game->player_img)
		mlx_destroy_image(game->mlx, game->player_img);
	if (game->wall_img)
		mlx_destroy_image(game->mlx, game->wall_img);
	if (game->exit_img)
		mlx_destroy_image(game->mlx, game->exit_img);
	if (game->collectible_img)
		mlx_destroy_image(game->mlx, game->collectible_img);
	if (game->empty_img)
		mlx_destroy_image(game->mlx, game->empty_img);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
		mlx_destroy_display(game->mlx);
	if (game->map)
		ft_free_map(game);
	free(game->mlx);
	exit (0);
}
