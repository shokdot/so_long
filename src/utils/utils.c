/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 18:10:42 by healeksa          #+#    #+#             */
/*   Updated: 2024/06/01 19:25:01 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	throw_error(char *txt)
{
	ft_putstr_fd("\033[0;31m", 2);
	ft_putendl_fd("Error", 2);
	ft_putstr_fd("\033[0;33m", 2);
	ft_putendl_fd(txt, 2);
	ft_putstr_fd("\033[0m", 2);
	exit(EXIT_FAILURE);
}
