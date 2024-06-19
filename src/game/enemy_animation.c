/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_animation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 19:26:52 by healeksa          #+#    #+#             */
/*   Updated: 2024/06/19 19:29:12 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_animation(t_game *game)
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
			if (game->game_map[i][j] == 'D')
				draw_element(game, i, j, 'D');
			j++;
		}
		i++;
	}
}

int	enemy_animation(t_game *game)
{
	if (game->frame < ANIMATION_SPEED)
		game->enemy_flag = 1;
	else if (game->frame < (ANIMATION_SPEED * 2))
		game->enemy_flag = 2;
	else
		game->frame = 0;
	draw_animation(game);
	game->frame++;
	return (0);
}
