/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 21:06:14 by healeksa          #+#    #+#             */
/*   Updated: 2024/06/18 22:55:21 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	clean_imges(t_game *game)
{
	mlx_destroy_image(game->mlx_ptr, game->img.coin);
	mlx_destroy_image(game->mlx_ptr, game->img.enemy1);
	mlx_destroy_image(game->mlx_ptr, game->img.enemy2);
	mlx_destroy_image(game->mlx_ptr, game->img.exit);
	mlx_destroy_image(game->mlx_ptr, game->img.floor);
	mlx_destroy_image(game->mlx_ptr, game->img.player_down);
	mlx_destroy_image(game->mlx_ptr, game->img.player_up);
	mlx_destroy_image(game->mlx_ptr, game->img.player_left);
	mlx_destroy_image(game->mlx_ptr, game->img.player_right);
	mlx_destroy_image(game->mlx_ptr, game->img.wall);
}

int	close_game(t_game *game)
{
	mlx_clear_window(game->mlx_ptr, game->win_ptr);
	clean_imges(game);
	memory_free(game->game_map);
	ft_free((void *)&game->move_str);
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	exit(0);
	return (0);
}
