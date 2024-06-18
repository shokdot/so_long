/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 21:43:21 by healeksa          #+#    #+#             */
/*   Updated: 2024/06/18 21:03:35 by healeksa         ###   ########.fr       */
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

# define ON_KEYDOWN 2
# define KEY_MASK 1

# define ON_DESTROY 17
# define NO_EVENT 0

# define STR_COLOR 0xFFFFFF

# define WALL "assets/others/wall.xpm"
# define FLOOR "assets/others/floor.xpm"
# define EXIT "assets/others/exit.xpm"
# define COIN "assets/others/coin.xpm"
# define ENEMY_1 "assets/ghost/ghost_1.xpm"
# define ENEMY_2 "assets/ghost/ghost_2.xpm"
# define PLAYER "assets/pacman/pac_right.xpm"

# ifdef __linux__
#  define UNAME "Linux"
#  define UP_KEY 65362
#  define DOWN_KEY 65364
#  define LEFT_KEY 65361
#  define RIGHT_KEY 6536
#  define ESC 65307

# elif defined(__APPLE__)
#  define UNAME "Darwin"
#  define UP_KEY 126
#  define DOWN_KEY 125
#  define LEFT_KEY 123
#  define RIGHT_KEY 124
#  define ESC 53

# else
#  define UP_KEY 0
#  define DOWN_KEY 0
#  define LEFT_KEY 0
#  define RIGHT_KEY 0

# endif

typedef struct s_img
{
	void	*wall;
	void	*floor;
	void	*exit;
	void	*coin;
	void	*player;
	void	*enemy1;
	void	*enemy2;
}			t_img;

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
	t_img	img;
	char	*move_str;
}			t_game;

// Main Functions
void		init_struct(t_game *game);
void		parse(int argc, char **argv, t_game *game);
void		init_game(t_game *game);

// Parse Functions
void		args_validation(int argc, char **argv, t_game *game);
char		**map_parsing(t_game *game);
void		map_validation(t_game *game);

// Init Game Functions
void		init_window(t_game *game);
void		init_images(t_game *game);

// Map Validation Utils

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
char		**cpy_map(t_game *game);

// Game Functions
void		draw_element(t_game *game, int i, int j, char sprite);
void		draw_map(t_game *game);
int			close_game(t_game *game);

// Hooks
int			hook_handler(int keycode, t_game *game);

// Movement
void		move(int x, int y, int keycode, t_game *game);

// Movment actions
void		enemy_act(t_game *game);
void		floor_act(int x, int y, t_game *game);
void		coin_act(int x, int y, t_game *game);
void		exit_act(int x, int y, t_game *game);
// Utils
void		throw_error(char *txt);
void		memory_free(char **arr);
int			str_set(char *str, char *set);
void		prt_map(char **map);

#endif

// void		init_tmp_map(t_game *game, t_tmp *tmp_map, char **map);
