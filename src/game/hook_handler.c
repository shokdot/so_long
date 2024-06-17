/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 21:46:23 by healeksa          #+#    #+#             */
/*   Updated: 2024/06/17 18:49:59 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	hook_handler(int keycode, t_game *game)
{
	if (keycode == UP_KEY)
		move(game->player_x - 1, game->player_y, UP_KEY, game);
	else if (keycode == DOWN_KEY)
		move(game->player_x + 1, game->player_y, DOWN_KEY, game);
	else if (keycode == LEFT_KEY)
		move(game->player_x, game->player_y - 1, LEFT_KEY, game);
	else if (keycode == RIGHT_KEY)
		move(game->player_x, game->player_y + 1, RIGHT_KEY, game);
	else if (keycode == ESC || keycode == Q)
		close_game(game);
	return (0);
}
