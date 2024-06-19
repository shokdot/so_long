/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_element.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 21:13:06 by healeksa          #+#    #+#             */
/*   Updated: 2024/06/19 20:46:13 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_directon(t_game *game, int i, int j)
{
	if (game->player_flag == RIGHT_KEY)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->img.player_right, j * SPRITE_WIDTH, i * SPRITE_HEIGHT);
	else if (game->player_flag == LEFT_KEY)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->img.player_left, j * SPRITE_WIDTH, i * SPRITE_HEIGHT);
	else if (game->player_flag == UP_KEY)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->img.player_up, j * SPRITE_WIDTH, i * SPRITE_HEIGHT);
	else if (game->player_flag == DOWN_KEY)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->img.player_down, j * SPRITE_WIDTH, i * SPRITE_HEIGHT);
}

void	exit_direction(t_game *game, int i, int j)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.exit, j
		* SPRITE_WIDTH, i * SPRITE_HEIGHT);
	if (game->player_flag == RIGHT_KEY)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->img.player_right, j * SPRITE_WIDTH, i * SPRITE_HEIGHT);
	else if (game->player_flag == LEFT_KEY)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->img.player_left, j * SPRITE_WIDTH, i * SPRITE_HEIGHT);
	else if (game->player_flag == UP_KEY)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->img.player_up, j * SPRITE_WIDTH, i * SPRITE_HEIGHT);
	else if (game->player_flag == DOWN_KEY)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->img.player_down, j * SPRITE_WIDTH, i * SPRITE_HEIGHT);
}

static void	enemy(t_game *game, int i, int j)
{
	if (game->enemy_flag == 1)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.enemy1,
			j * SPRITE_WIDTH, i * SPRITE_HEIGHT);
	else if (game->enemy_flag == 2)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.enemy2,
			j * SPRITE_WIDTH, i * SPRITE_HEIGHT);
}

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
		player_directon(game, i, j);
	else if (sprite == 'D')
		enemy(game, i, j);
	else if (sprite == 'Z')
		exit_direction(game, i, j);
}
