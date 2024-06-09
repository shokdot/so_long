/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 18:50:23 by healeksa          #+#    #+#             */
/*   Updated: 2024/06/09 22:00:05 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;
	void	*mlx;
	void	*mlx_win;

	init_struct(&game);
	parse(argc, argv, &game);
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 800, 900, "so_long");
	mlx_loop(mlx);
}
