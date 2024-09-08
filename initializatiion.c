/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializatiion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalmeid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 08:21:34 by maalmeid          #+#    #+#             */
/*   Updated: 2024/08/28 13:36:16 by maalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "minilibx-linux/mlx.h"

void	ft_initialization(t_game *game)
{
	game->mlx = mlx_init();
	if (game->mlx == NULL)
	{
		ft_printf("Error\nErro ao inicializar MiniLibX\n");
		exit(1);
	}
	game->win = mlx_new_window(game->mlx, game->map_width * 50,
			game->map_height * 50, "so_long");
	game->collectible_img = mlx_xpm_file_to_image(game->mlx,
			"images/collectible.xpm", &game->map_width, &game->map_height);
	game->exit_img = mlx_xpm_file_to_image(game->mlx, "images/exit.xpm",
			&game->map_width, &game->map_height);
	game->player_img = mlx_xpm_file_to_image(game->mlx, "images/player.xpm",
			&game->map_width, &game->map_height);
	game->wall_img = mlx_xpm_file_to_image(game->mlx, "images/wall.xpm",
			&game->map_width, &game->map_height);
	game->empty_img = mlx_xpm_file_to_image(game->mlx, "images/empty.xpm",
			&game->map_width, &game->map_height);
	game->move_count = 0;
}
