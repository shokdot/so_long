/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 17:53:16 by healeksa          #+#    #+#             */
/*   Updated: 2024/06/12 23:36:51 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_doubles(char *tmp_map)
{
	int	i;

	i = 0;
	if (!tmp_map)
	{
		ft_free((void *)&tmp_map);
		throw_error("Map is empty");
	}
	while (tmp_map[i])
	{
		if (tmp_map[0] == '\n' || (tmp_map[i] == '\n'
				&& tmp_map[i + 1] == '\n'))
		{
			ft_free((void *)&tmp_map);
			throw_error("Many new lines in map");
		}
		i++;
	}
}

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
	check_doubles(tmp_map);
	game->game_map = ft_split(tmp_map, '\n');
	ft_free((void *)&tmp_map);
	game->map_width = ft_strlen(game->game_map[0]);
	close(game->map_fd);
	return (game->game_map);
}
