/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalmeid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 08:21:34 by maalmeid          #+#    #+#             */
/*   Updated: 2024/08/28 13:20:40 by maalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "minilibx-linux/mlx.h"

int	main(int ac, char **av)
{
	char	**map;
	t_game	game;

	ft_arguments(ac);
	ft_extension(av[1]);
	ft_memset(&game, 0, sizeof(t_game));
	ft_read_map(&game, av[1]);
	ft_player_position(&game);
	ft_validate(&game);
	ft_verification1(&game);
	map = ft_copy_map(&game);
	ft_flood_fill1(map, game.player_x, game.player_y);
	if (ft_check_ways1(map) == 0)
	{
		ft_free_copy(map);
		ft_printf("Error\nmapa nao e jogavel\n");
		ft_end_game(&game);
	}
	ft_free_copy(map);
	ft_initialization(&game);
	ft_render(&game);
	mlx_key_hook(game.win, ft_key_hook, &game);
	mlx_hook(game.win, 17, 0, (void *)ft_end_game, &game);
	mlx_loop(game.mlx);
	return (0);
}
