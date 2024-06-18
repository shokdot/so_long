/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 18:36:54 by healeksa          #+#    #+#             */
/*   Updated: 2024/06/18 22:21:22 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_struct(t_game *game)
{
	game->map_width = 0;
	game->map_height = 0;
	game->coin = 0;
	game->tmp_exit = 0;
	game->tmp_coins = 0;
	game->player_steps = 0;
	game->move_str = ft_strdup("0");
	game->player_flag = RIGHT_KEY;
}
