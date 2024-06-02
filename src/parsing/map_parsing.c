/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 17:53:16 by healeksa          #+#    #+#             */
/*   Updated: 2024/06/02 22:31:12 by healeksa         ###   ########.fr       */
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
	game->game_map = ft_split(tmp_map, ' ');
	return (game->game_map);
}
