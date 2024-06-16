/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 21:46:23 by healeksa          #+#    #+#             */
/*   Updated: 2024/06/16 21:52:55 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	hook_handler(int keycode, t_game *game)
{
	if (keycode == ESC || keycode == Q)
		close_game(game);
	return (0);
}
