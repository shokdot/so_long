/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 17:53:16 by healeksa          #+#    #+#             */
/*   Updated: 2024/06/09 21:36:03 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**map_parsing(t_game *game)
{
	char	*tmp_line;
	char	*tmp_map;

	tmp_line = get_next_line(game->map_fd);
	tmp_map = NULL;
	game->map_height = 0;
	while (tmp_line)
	{
		game->map_height++;
		tmp_map = ft_join(tmp_map, tmp_line);
		ft_free((void *)&tmp_line);
		tmp_line = get_next_line(game->map_fd);
	}
	game->game_map = ft_split(tmp_map, '\n');
	ft_free((void *)&tmp_map);
	if (!game->game_map || !game->game_map[0])
	{
		close(game->map_fd);
		ft_free((void *)&game->game_map);
		throw_error("Map is empty");
	}
	game->map_width = ft_strlen(game->game_map[0]);
	close(game->map_fd);
	return (game->game_map);
}
