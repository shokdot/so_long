/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 21:43:21 by healeksa          #+#    #+#             */
/*   Updated: 2024/06/12 23:40:58 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define SCREEN_WIDTH 1920
# define SCREEN_HEIGHT 1080
# define SPRITE_WIDTH 32
# define SPRITE_HEIGHT 32

typedef struct s_game
{
	int		map_fd;
	char	*path;
	int		map_width;
	int		map_height;
	char	**game_map;
	int		coin;
	int		player_x;
	int		player_y;
	int		tmp_exit;
	int		tmp_coins;
	int		player_steps;
	void	*mlx_ptr;
	void	*win_ptr;
}			t_game;

// Main Functions
void		init_struct(t_game *game);
void		parse(int argc, char **argv, t_game *game);

// Parse Functions
void		args_validation(int argc, char **argv, t_game *game);
char		**map_parsing(t_game *game);
void		map_validation(t_game *game);

// Init Game functions
void		init_game(t_game *game);

// Map-Validation Utils

void		rectangular(t_game *game);
void		symbol_check(t_game *game);
void		wall_surrounded(t_game *game);
void		least_chars(t_game *game);
void		is_playible(t_game *game);
int			horizantal_wall(t_game *game);
int			vertical_wall(t_game *game);
int			one_exit(t_game *game);
int			one_start(t_game *game);
int			least_coin(t_game *game);
void		map_size(t_game *game);
void		flood_fill(t_game *game, int x, int y, char **map);

// Utils
void		throw_error(char *txt);
void		memory_free(char **arr);
int			str_set(char *str, char *set);

// void		init_tmp_map(t_game *game, t_tmp *tmp_map, char **map);

void		prt_map(char **map);
char		**cpy_map(t_game *game);

#endif
