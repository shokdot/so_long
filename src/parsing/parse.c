/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 21:42:11 by healeksa          #+#    #+#             */
/*   Updated: 2024/05/17 21:42:28 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && s1[i] == s2[i])
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

void	check_args(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("Error\n");
		exit(1);
	}
}

void	is_ber(char *path)
{
	if (!(ft_strlen(path) < 5))
		if (!(ft_strcmp(path + (ft_strlen(path) - 4), ".ber")))
			return ;
	printf("Error\n");
	exit(1);
}

void	parse(int argc, char **argv)
{
	char	*map_path;

	map_path = argv[1];
	check_args(argc, argv);
	is_ber(map_path);
}
