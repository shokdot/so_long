/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 21:42:11 by healeksa          #+#    #+#             */
/*   Updated: 2024/06/05 17:55:39 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	parse(int argc, char **argv, t_game *game)
{
	args_validation(argc, argv, game);
	map_parsing(game);
	map_validation(game);
}
