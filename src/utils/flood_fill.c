/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 18:38:35 by healeksa          #+#    #+#             */
/*   Updated: 2024/06/13 21:10:35 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(t_game *game, int x, int y, char **map)
{
	if (map[x][y] == '1' || map[x][y] == 'X' || map[x][y] == 'D' || x < 0
		|| y < 0 || x >= game->map_height || y >= game->map_width)
		return ;
	if (map[x][y] == 'E')
		game->tmp_exit++;
	else if (map[x][y] == 'C')
		game->tmp_coins++;
	map[x][y] = 'X';
	flood_fill(game, x + 1, y, map);
	flood_fill(game, x, y + 1, map);
	flood_fill(game, x - 1, y, map);
	flood_fill(game, x, y - 1, map);
}
