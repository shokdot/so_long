/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 21:43:21 by healeksa          #+#    #+#             */
/*   Updated: 2024/06/01 19:26:43 by healeksa         ###   ########.fr       */
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
}			t_game;

void		parse(int argc, char **argv, t_game *personaje);

// UTILS
void		throw_error(char *txt);

#endif
