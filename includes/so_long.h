/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 21:43:21 by healeksa          #+#    #+#             */
/*   Updated: 2024/06/05 23:18:46 by healeksa         ###   ########.fr       */
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

typedef struct s_game
{
	int		map_fd;
	char	*path;
	int		map_width;
	int		map_height;
	char	**game_map;
	int		coin;
}			t_game;

// Main Functions
void		parse(int argc, char **argv, t_game *game);
void		args_validation(int argc, char **argv, t_game *game);
char		**map_parsing(t_game *game);
void		map_validation(t_game *game);

// Wall
int			horizantal_wall(t_game *game);
int			vertical_wall(t_game *game);

int			min_elm(t_game *game, char c);
int			least_coin(t_game *game);

// UTILS
void		throw_error(char *txt);
void		memory_free(char **arr);
int			str_set(char *str, char *set);

#endif
