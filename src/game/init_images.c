/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 19:47:06 by healeksa          #+#    #+#             */
/*   Updated: 2024/06/15 19:47:30 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_images(t_game *game)
{
	int	img_width;
	int	img_height;

	game->img.wall = mlx_xpm_file_to_image(game->mlx_ptr,
			"assets/others/wall.xpm", &img_width, &img_height);
	game->img.floor = mlx_xpm_file_to_image(game->mlx_ptr,
			"assets/others/floor.xpm", &img_width, &img_height);
	game->img.exit = mlx_xpm_file_to_image(game->mlx_ptr,
			"assets/others/exit.xpm", &img_width, &img_height);
	game->img.coin = mlx_xpm_file_to_image(game->mlx_ptr,
			"assets/others/coin.xpm", &img_width, &img_height);
	game->img.enemy1 = mlx_xpm_file_to_image(game->mlx_ptr,
			"assets/ghost/ghost_1.xpm", &img_width, &img_height);
	game->img.enemy2 = mlx_xpm_file_to_image(game->mlx_ptr,
			"assets/ghost/ghost_2.xpm", &img_width, &img_height);
	game->img.player = mlx_xpm_file_to_image(game->mlx_ptr,
			"assets/pacman/pac_right.xpm", &img_width, &img_height);
}
