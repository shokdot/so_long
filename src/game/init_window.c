/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 19:45:07 by healeksa          #+#    #+#             */
/*   Updated: 2024/06/16 21:44:45 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_window(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
	{
		memory_free(game->game_map);
		throw_error("Mlx doesn't worked correctly");
	}
	game->win_ptr = mlx_new_window(game->mlx_ptr, game->map_width
			* SPRITE_WIDTH, game->map_height * SPRITE_HEIGHT, "so_long");
	if (!game->win_ptr)
	{
		memory_free(game->game_map);
		throw_error("Mlx doesn't worked correctly");
	}
}
