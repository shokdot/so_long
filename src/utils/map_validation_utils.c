/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 16:55:00 by healeksa          #+#    #+#             */
/*   Updated: 2024/06/08 22:20:43 by healeksa         ###   ########.fr       */
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
	if (!one_exit(game) || !one_start(game) || !least_coin(game))
	{
		memory_free(game->game_map);
		throw_error("Must Be 1 Exit(E), 1 Start(P) and at least 1 Coin (C)");
	}
}

void	is_playible(t_game *game)
{
	char	**map;

	map = cpy_map(game);
	flood_fill(game, game->player_x, game->player_y, map);
	if (game->coin != game->tmp_coins || game->tmp_exit != 1)
	{
		memory_free(game->game_map);
		throw_error("Map is'nt playible");
	}
}
