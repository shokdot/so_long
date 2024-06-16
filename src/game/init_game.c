/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 17:25:38 by healeksa          #+#    #+#             */
/*   Updated: 2024/06/16 21:45:59 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	draw_init_map(t_game *game)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	j = 0;
// 	while (game->game_map[i])
// 	{
// 		j = 0;
// 		while (game->game_map[i][j])
// 		{
// 			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
// 				game->img.floor, j * SPRITE_WIDTH, i * SPRITE_HEIGHT);
// 			j++;
// 		}
// 		i++;
// 	}
// }

void	init_game(t_game *game)
{
	init_window(game);
	init_images(game);
	init_map(game);
	mlx_hook(game->win_ptr, ON_KEYDOWN, KEY_MASK, hook_handler, game);
	mlx_hook(game->win_ptr, ON_DESTROY, NO_EVENT, close_game, game);
	mlx_loop(game->mlx_ptr);
}
