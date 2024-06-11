/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 14:32:27 by healeksa          #+#    #+#             */
/*   Updated: 2024/06/11 22:34:50 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_validation(t_game *game)
{
	rectangular(game);
	symbol_check(game);
	wall_surrounded(game);
	least_chars(game);
	map_size(game);
	is_playible(game);
}
