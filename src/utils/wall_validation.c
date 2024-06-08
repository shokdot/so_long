/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 18:34:28 by healeksa          #+#    #+#             */
/*   Updated: 2024/06/07 18:38:24 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	vertical_wall(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map_height)
	{
		if (game->game_map[i][0] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < game->map_height)
	{
		if (game->game_map[i][game->map_width - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	horizantal_wall(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map_width)
	{
		if (game->game_map[0][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < game->map_width)
	{
		if (game->game_map[game->map_height - 1][i] != '1')
			return (0);
		i++;
	}
	return (1);
}
