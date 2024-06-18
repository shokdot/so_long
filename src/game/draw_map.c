/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 21:23:49 by healeksa          #+#    #+#             */
/*   Updated: 2024/06/18 20:16:26 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
			draw_element(game, i, j, game->game_map[i][j]);
			j++;
		}
		i++;
	}
}
