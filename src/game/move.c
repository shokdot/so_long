/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 18:33:47 by healeksa          #+#    #+#             */
/*   Updated: 2024/06/17 23:45:59 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	change_player_cords(t_game *game, int keycode)
{
	if (keycode == UP_KEY)
		game->player_x--;
	else if (keycode == DOWN_KEY)
		game->player_x++;
	else if (keycode == LEFT_KEY)
		game->player_y--;
	else if (keycode == RIGHT_KEY)
		game->player_y++;
}

void	move(int x, int y, int keycode, t_game *game)
{
	static int	coins = 0;

	if (game->game_map[x][y] == '1')
		return ;
	else if (game->game_map[x][y] == 'C')
	{
		coins++;
		game->game_map[x][y] = 'P';
		game->game_map[game->player_x][game->player_y] = '0';
	}
	else if (game->game_map[x][y] == 'D')
	{
		ft_putstr_fd("\033[0;31m", 2);
		ft_putendl_fd("You Lose!", 0);
		ft_putstr_fd("\033[0m", 2);
		close_game(game);
	}
	else if (game->game_map[x][y] == '0')
	{
		game->game_map[game->player_x][game->player_y] = '0';
		game->game_map[x][y] = 'P';
		// printf("%c\n", game->game_map[game->player_x][game->player_x]);
		if (game->game_map[game->player_x][game->player_x] == 'E')
		{
			printf("EXitit vra em\n");
			// 	game->game_map[game->player_x][game->player_y] = 'E';
		}
		// else
		// {
		// 	game->game_map[game->player_x][game->player_y] = '0';
		// }
	}
	else if (game->game_map[x][y] == 'E')
	{
		game->game_map[game->player_x][game->player_y] = '0';
		game->game_map[x][y] = 'P';
	}
	init_map(game);
	change_player_cords(game, keycode);
	game->player_steps++;
}
