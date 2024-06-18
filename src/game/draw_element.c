/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_element.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 21:13:06 by healeksa          #+#    #+#             */
/*   Updated: 2024/06/18 20:15:52 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_element(t_game *game, int i, int j, char sprite)
{
	if (sprite == '0')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.floor, j
			* SPRITE_WIDTH, i * SPRITE_HEIGHT);
	else if (sprite == '1')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.wall, j
			* SPRITE_WIDTH, i * SPRITE_HEIGHT);
	else if (sprite == 'E')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.exit, j
			* SPRITE_WIDTH, i * SPRITE_HEIGHT);
	else if (sprite == 'C')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.coin, j
			* SPRITE_WIDTH, i * SPRITE_HEIGHT);
	else if (sprite == 'P')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.player,
			j * SPRITE_WIDTH, i * SPRITE_HEIGHT);
	else if (sprite == 'D')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.enemy1,
			j * SPRITE_WIDTH, i * SPRITE_HEIGHT);
	else if (sprite == 'Z')
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.exit, j
			* SPRITE_WIDTH, i * SPRITE_HEIGHT);
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.player,
			j * SPRITE_WIDTH, i * SPRITE_HEIGHT);
	}
}
