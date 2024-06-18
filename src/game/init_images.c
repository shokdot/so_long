/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 19:47:06 by healeksa          #+#    #+#             */
/*   Updated: 2024/06/18 22:26:34 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_enemy(t_game *game, int *img_width, int *img_height)
{
	game->img.enemy1 = mlx_xpm_file_to_image(game->mlx_ptr, ENEMY_1, img_width,
			img_height);
	game->img.enemy2 = mlx_xpm_file_to_image(game->mlx_ptr, ENEMY_2, img_width,
			img_height);
}

void	init_player(t_game *game, int *img_width, int *img_height)
{
	game->img.player_right = mlx_xpm_file_to_image(game->mlx_ptr, PLAYER_RIGHT,
			img_width, img_height);
	game->img.player_left = mlx_xpm_file_to_image(game->mlx_ptr, PLAYER_LEFT,
			img_width, img_height);
	game->img.player_up = mlx_xpm_file_to_image(game->mlx_ptr, PLAYER_UP,
			img_width, img_height);
	game->img.player_down = mlx_xpm_file_to_image(game->mlx_ptr, PLAYER_DOWN,
			img_width, img_height);
}

void	init_others(t_game *game, int *img_width, int *img_height)
{
	game->img.wall = mlx_xpm_file_to_image(game->mlx_ptr, WALL, img_width,
			img_height);
	game->img.floor = mlx_xpm_file_to_image(game->mlx_ptr, FLOOR, img_width,
			img_height);
	game->img.exit = mlx_xpm_file_to_image(game->mlx_ptr, EXIT, img_width,
			img_height);
	game->img.coin = mlx_xpm_file_to_image(game->mlx_ptr, COIN, img_width,
			img_height);
}

void	init_images(t_game *game)
{
	int	img_width;
	int	img_height;

	init_player(game, &img_width, &img_height);
	init_others(game, &img_width, &img_height);
	init_enemy(game, &img_width, &img_height);
}
