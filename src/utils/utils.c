/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 18:10:42 by healeksa          #+#    #+#             */
/*   Updated: 2024/06/08 22:15:45 by healeksa         ###   ########.fr       */
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

void	memory_free(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	arr = NULL;
}

int	str_set(char *str, char *set)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (set[j])
		{
			if (str[i] == set[j])
				break ;
			j++;
		}
		if (!set[j])
			return (1);
		i++;
	}
	if (!str[i])
		return (0);
	return (1);
}

void	prt_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		printf("%s\n", map[i]);
		i++;
	}
}
