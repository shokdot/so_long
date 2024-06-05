/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 14:32:27 by healeksa          #+#    #+#             */
/*   Updated: 2024/06/05 23:30:22 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	rectangular(t_game *game)
{
	int	i;
	int	row_size;

	i = 0;
	row_size = 0;
	while (game->game_map[i])
	{
		row_size = ft_strlen(game->game_map[i]);
		if (game->map_width != row_size)
		{
			memory_free(game->game_map);
			throw_error("Map is not rectangular");
		}
		i++;
	}
}

void	symbol_check(t_game *game)
{
	int	i;

	i = 0;
	while (game->game_map[i])
	{
		if (str_set(game->game_map[i], "01CEP"))
		{
			memory_free(game->game_map);
			throw_error("In map has others symbols");
		}
		i++;
	}
}

void	wall_surrounded(t_game *game)
{
	if (!horizantal_wall(game) || !vertical_wall(game))
	{
		memory_free(game->game_map);
		throw_error("Not surrounded with wall");
	}
}

void	least_chars(t_game *game)
{
	if (!min_elm(game, 'E') || !min_elm(game, 'P') || !least_coin(game))
	{
		memory_free(game->game_map);
		throw_error("Must Be 1 Exit(E), 1 Start(P) and at least 1 Coin (C)");
	}
}

void	map_validation(t_game *game)
{
	rectangular(game);
	symbol_check(game);
	wall_surrounded(game);
	least_chars(game);
}
