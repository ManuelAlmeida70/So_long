/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalmeid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 08:21:34 by maalmeid          #+#    #+#             */
/*   Updated: 2024/08/28 13:35:10 by maalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"

typedef struct s_game
{
	void	*mlx;
	void	*win;
	void	*player_img;
	void	*wall_img;
	void	*exit_img;
	void	*collectible_img;
	void	*empty_img;
	char	**map;
	int		map_width;
	int		map_height;
	int		player_x;
	int		player_y;
	int		collectible_count;
	int		move_count;
}	t_game;

//initialization.c
void	ft_initialization(t_game *game);

//map.c
void	ft_read_map(t_game *game, const char *map_path);
void	ft_fill_map(t_game *game, int fd);
int		ft_height_map(const char *map_path);

//free.c
void	ft_end_game(t_game *game);
void	ft_free_map(t_game *game);

//keyboard.c
int		ft_key_hook(int key, t_game *game);

//render.c
void	ft_render(t_game *game);
void	ft_put_image(t_game *game, int x, int y, void *img);
void	ft_invalid_character(t_game *game);

//validate.c
void	ft_is_rectangular(t_game *game);
void	ft_is_wall(t_game *game);
void	ft_count_exit_and_collectible(t_game *game);
void	ft_count_player(t_game *game, char element);
void	ft_validate(t_game *game);

//utils.c
int		ft_sl_strlen(const char *s);
int		ft_count_elements(t_game *game, char element);
int		ft_strcmp(const char *s1, const char *s2);

//player.c
void	ft_player_position(t_game *game);
int		ft_handle_tile_interaction(t_game *game, char target_tile);

//move.c
void	ft_move_player(t_game *game, int new_x, int new_y);
void	ft_move_up(t_game *game);
void	ft_move_down(t_game *game);
void	ft_move_left(t_game *game);
void	ft_move_right(t_game *game);

//playable.c
void	ft_flood_fill(char **map, int x, int y);
void	ft_free_copy(char **map);
void	ft_flood_fill1(char **map, int x, int y);
char	**ft_copy_map(t_game *game);

//checks.c
int		ft_check_ways(char **map);
int		ft_check_ways1(char **map);

//verification.c
void	ft_verification1(t_game *game);
void	ft_verification2(t_game *game);
void	ft_arguments(int ac);

//type.c
char	*ft_check_file_verification1(const char *file_name);
void	ft_type(const char *file_name, const char *extension);
void	ft_extension(const char *s);

#endif
