/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalmeid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 08:21:34 by maalmeid          #+#    #+#             */
/*   Updated: 2024/08/28 13:37:06 by maalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "minilibx-linux/mlx.h"

int	ft_key_hook(int keycode, t_game *game)
{
	if (keycode == 65307)
		ft_end_game(game);
	if (keycode == 65361 || keycode == 97)
		ft_move_left(game);
	if (keycode == 65362 || keycode == 199)
		ft_move_up(game);
	if (keycode == 65363 || keycode == 100)
		ft_move_right(game);
	if (keycode == 65364 || keycode == 115)
		ft_move_down(game);
	ft_render(game);
	return (0);
}
