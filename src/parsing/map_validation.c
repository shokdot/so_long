/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 14:32:27 by healeksa          #+#    #+#             */
/*   Updated: 2024/06/04 19:44:23 by healeksa         ###   ########.fr       */
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
			printf("error\n");
			exit(1);
		}
		i++;
	}
}

void	map_validation(t_game *game)
{
	rectangular(game);
	symbol_check(game);
}
