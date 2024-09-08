/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalmeid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 08:21:34 by maalmeid          #+#    #+#             */
/*   Updated: 2024/08/28 13:26:39 by maalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "minilibx-linux/mlx.h"

void	ft_render(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map[y] != NULL)
	{
		x = 0;
		while (game->map[y][x] != '\0')
		{
			if (game->map[y][x] == '1')
				ft_put_image(game, x, y, game->wall_img);
			else if (game->map[y][x] == 'P')
				ft_put_image(game, x, y, game->player_img);
			else if (game->map[y][x] == 'E')
				ft_put_image(game, x, y, game->exit_img);
			else if (game->map[y][x] == 'C')
				ft_put_image(game, x, y, game->collectible_img);
			else if (game->map[y][x] == '0')
				ft_put_image(game, x, y, game->empty_img);
			else
				ft_invalid_character(game);
			x++;
		}
		y++;
	}
}

void	ft_put_image(t_game *game, int x, int y, void *img)
{
	mlx_put_image_to_window(game->mlx, game->win, img, x * 50, y * 50);
}

void	ft_invalid_character(t_game *game)
{
	ft_printf("Error\n caracter invalido no mapa\n");
	ft_end_game(game);
}
