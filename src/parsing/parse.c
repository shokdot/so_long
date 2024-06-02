/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 21:42:11 by healeksa          #+#    #+#             */
/*   Updated: 2024/06/02 22:29:49 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	rectangular(t_game *game, char **tmp_map)
// {
// 	char	*tmp_line;

// 	game->map_height = 0;
// 	tmp_line = get_next_line(game->map_fd);
// 	game->map_width = (int)ft_strlen(tmp_line) - 1;
// 	while (tmp_line && game->map_width == (int)ft_strlen(tmp_line) - 1)
// 	{
// 		game->map_height++;
// 		*tmp_map = ft_join(*tmp_map, tmp_line);
// 		ft_free((void *)&tmp_line);
// 		tmp_line = get_next_line(game->map_fd);
// 	}
// 	if (tmp_line)
// 	{
// 		ft_free((void *)&tmp_line);
// 		throw_error("Map is not rectangular");
// 	}
// }

void	parse(int argc, char **argv, t_game *game)
{
	args_validation(argc, argv, game);
	map_parsing(game);
}

// TO DO
// stuctural reform
// char	**res;
