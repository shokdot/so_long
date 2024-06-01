/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 21:42:11 by healeksa          #+#    #+#             */
/*   Updated: 2024/06/01 19:29:38 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_args(int argc)
{
	if (argc != 2)
		throw_error("Please specify map for game");
}

void	extension_validation(t_game *game)
{
	if (!(ft_strlen(game->path) < 4))
		if (!(ft_strcmp(game->path + (ft_strlen(game->path) - 4), ".ber")))
			return ;
	throw_error("File is not .ber format");
}

void	path_validation(t_game *game)
{
	game->map_fd = open(game->path, O_RDONLY);
	if (game->map_fd < 0)
		throw_error("Cannot open file");
}

void	rectangular(t_game *game, char **tmp_map)
{
	char	*tmp_line;

	game->map_height = 0;
	tmp_line = get_next_line(game->map_fd);
	game->map_width = (int)ft_strlen(tmp_line) - 1;
	while (tmp_line && game->map_width == (int)ft_strlen(tmp_line) - 1)
	{
		game->map_height++;
		*tmp_map = ft_join(*tmp_map, tmp_line);
		ft_free((void *)&tmp_line);
		tmp_line = get_next_line(game->map_fd);
	}
	if (tmp_line)
	{
		ft_free((void *)&tmp_line);
		throw_error("Map is not rectangular");
	}
}

void	parse(int argc, char **argv, t_game *game)
{
	char	*tmp_map;
	int		i;

	// TO DO
	// stuctural reform
	// char	**res;
	game->path = argv[1];
	check_args(argc);
	extension_validation(game);
	path_validation(game);
	rectangular(game, &tmp_map);
	printf("%s", tmp_map);
}
