/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 17:25:38 by healeksa          #+#    #+#             */
/*   Updated: 2024/06/13 23:57:57 by healeksa         ###   ########.fr       */
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
			"assets/others/floor.xmp", &img_width, &img_height);
	game->img.exit = mlx_xpm_file_to_image(game->mlx_ptr,
			"assets/others/exit.xmp", &img_width, &img_height);
	game->img.coin = mlx_xpm_file_to_image(game->mlx_ptr,
			"assets/others/coin.xpm", &img_width, &img_height);
	game->img.enemy1 = mlx_xpm_file_to_image(game->mlx_ptr,
			"assets/ghost/ghost_1a.xpm", &img_width, &img_height);
	game->img.enemy2 = mlx_xpm_file_to_image(game->mlx_ptr,
			"assets/ghost/ghost_2a.xpm", &img_width, &img_height);
}

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
	init_images(game);
	mlx_loop(game->mlx_ptr);
}
