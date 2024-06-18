/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 18:33:47 by healeksa          #+#    #+#             */
/*   Updated: 2024/06/18 20:21:18 by healeksa         ###   ########.fr       */
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
	char	*str;

	str = ft_strdup("0");
	printf("%d\n", game->coin);
	if (game->game_map[x][y] == 'D')
		enemy_act(str, game);
	else if (game->game_map[x][y] == '0')
		floor_act(x, y, game);
	else if (game->game_map[x][y] == 'C')
		coin_act(x, y, game);
	else if (game->game_map[x][y] == 'E')
		exit_act(str, x, y, game);
	else
		return ;
	draw_map(game);
	change_player_cords(game, keycode);
	ft_free((void *)&str);
	game->player_steps++;
	str = ft_itoa(game->player_steps);
	mlx_string_put(game->mlx_ptr, game->win_ptr, 5, 5, 0xFFFFFF, "Moves: ");
	mlx_string_put(game->mlx_ptr, game->win_ptr, 73, 5, 0xFFFFFF, str);
}
