/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 17:25:38 by healeksa          #+#    #+#             */
/*   Updated: 2024/06/15 21:40:24 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*charater_spell(char c, t_game *game)
{
	if (c == '0')
		return (game->img.floor);
	else if (c == '1')
		return (game->img.wall);
	else if (c == 'E')
		return (game->img.exit);
	else if (c == 'C')
		return (game->img.coin);
	else if (c == 'P')
		return (game->img.player);
	else if (c == 'D')
		return (game->img.enemy1);
	return (NULL);
}

void	draw_init_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->game_map[i])
	{
		j = 0;
		while (game->game_map[i][j])
		{
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
				game->img.floor, j * SPRITE_WIDTH, i * SPRITE_HEIGHT);
			j++;
		}
		i++;
	}
}

void	draw_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->game_map[i])
	{
		j = 0;
		while (game->game_map[i][j])
		{
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
				charater_spell(game->game_map[i][j], game), j * SPRITE_WIDTH, i
				* SPRITE_HEIGHT);
			j++;
		}
		i++;
	}
}

void	init_game(t_game *game)
{
	init_window(game);
	init_images(game);
	draw_init_map(game);
	draw_map(game);
	mlx_loop(game->mlx_ptr);
}
