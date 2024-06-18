/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movment_acts.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 19:41:20 by healeksa          #+#    #+#             */
/*   Updated: 2024/06/18 21:00:51 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	enemy_act(t_game *game)
{
	ft_free((void *)&game->move_str);
	ft_putstr_fd("\033[0;31m", 2);
	ft_putendl_fd("You Lose!", 0);
	ft_putstr_fd("\033[0m", 2);
	close_game(game);
}

void	floor_act(int x, int y, t_game *game)
{
	if (game->game_map[game->player_x][game->player_y] == 'Z')
		game->game_map[game->player_x][game->player_y] = 'E';
	else
		game->game_map[game->player_x][game->player_y] = '0';
	game->game_map[x][y] = 'P';
}

void	coin_act(int x, int y, t_game *game)
{
	if (game->game_map[game->player_x][game->player_y] == 'Z')
		game->game_map[game->player_x][game->player_y] = 'E';
	else
		game->game_map[game->player_x][game->player_y] = '0';
	game->game_map[x][y] = 'P';
	game->coin--;
}

void	exit_act(int x, int y, t_game *game)
{
	if (game->coin == 0)
	{
		ft_free((void *)&game->move_str);
		ft_putstr_fd("\033[0;32m", 2);
		ft_putendl_fd("You Win!", 0);
		ft_putstr_fd("\033[0m", 2);
		close_game(game);
	}
	game->game_map[game->player_x][game->player_y] = '0';
	game->game_map[x][y] = 'Z';
}
