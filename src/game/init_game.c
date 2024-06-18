/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 17:25:38 by healeksa          #+#    #+#             */
/*   Updated: 2024/06/18 21:03:45 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_game(t_game *game)
{
	init_window(game);
	init_images(game);
	draw_map(game);
	mlx_string_put(game->mlx_ptr, game->win_ptr, 5, 5, STR_COLOR, "Moves: 0");
	mlx_hook(game->win_ptr, ON_KEYDOWN, KEY_MASK, hook_handler, game);
	mlx_hook(game->win_ptr, ON_DESTROY, NO_EVENT, close_game, game);
	mlx_loop(game->mlx_ptr);
}
