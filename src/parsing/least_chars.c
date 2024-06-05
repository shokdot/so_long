/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   least_chars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 22:25:48 by healeksa          #+#    #+#             */
/*   Updated: 2024/06/05 23:23:22 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	min_elm(t_game *game, char c)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	flag = 0;
	while (game->game_map[i])
	{
		j = 0;
		while (game->game_map[i][j])
		{
			if (game->game_map[i][j] == c && flag)
				return (0);
			else if (game->game_map[i][j] == c && !flag)
				flag = 1;
			j++;
		}
		i++;
	}
	if (!flag)
		return (0);
	return (1);
}

int	least_coin(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	game->coin = 0;
	while (game->game_map[i])
	{
		j = 0;
		while (game->game_map[i][j])
		{
			if (game->game_map[i][j] == 'C')
				game->coin++;
			j++;
		}
		i++;
	}
	if (!game->coin)
		return (0);
	return (1);
}
