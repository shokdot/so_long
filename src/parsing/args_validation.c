/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 17:52:15 by healeksa          #+#    #+#             */
/*   Updated: 2024/06/02 21:59:18 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_args(int argc)
{
	if (argc > 2)
		throw_error("Arguments is too many");
	else if (argc < 2)
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

void	args_validation(int argc, char **argv, t_game *game)
{
	game->path = argv[1];
	check_args(argc);
	extension_validation(game);
	path_validation(game);
}
