/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 17:25:38 by healeksa          #+#    #+#             */
/*   Updated: 2024/06/12 17:44:35 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_game(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
	{
		memory_free(game->game_map);
		throw_error("Mlx don't worked correctly");
	}
	game->win_ptr = mlx_new_window(game->mlx_ptr, game->map_width
			* SPRITE_WIDTH, game->map_height * SPRITE_HEIGHT, "so_long");
	if (!game->win_ptr)
	{
		memory_free(game->game_map);
		throw_error("Mlx don't worked correctly");
	}
	mlx_loop(game->mlx_ptr);
}
