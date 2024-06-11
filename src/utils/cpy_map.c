/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpy_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 21:29:54 by healeksa          #+#    #+#             */
/*   Updated: 2024/06/11 22:42:15 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	err(char **map)
{
	memory_free(map);
	throw_error("Can not copy the map");
}

char	**cpy_map(t_game *game)
{
	char	**map;
	int		i;
	int		j;

	map = (char **)malloc((game->map_height + 1) * sizeof(char *));
	if (!map)
		err(game->game_map);
	i = 0;
	while (i < game->map_height)
	{
		map[i] = (char *)malloc((game->map_width + 1) * sizeof(char));
		if (!map[i])
			err(game->game_map);
		j = 0;
		while (j < game->map_width)
		{
			map[i][j] = game->game_map[i][j];
			j++;
		}
		map[i][game->map_width] = '\0';
		i++;
	}
	map[i] = NULL;
	return (map);
}
