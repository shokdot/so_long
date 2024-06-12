/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 22:35:26 by healeksa          #+#    #+#             */
/*   Updated: 2024/06/12 23:40:41 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_size(t_game *game)
{
	if (game->map_width > SCREEN_WIDTH / SPRITE_WIDTH
		|| game->map_height > SCREEN_HEIGHT / SPRITE_HEIGHT)
	{
		memory_free(game->game_map);
		throw_error("Map is too large");
	}
}
