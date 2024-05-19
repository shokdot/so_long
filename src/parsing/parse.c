/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 21:42:11 by healeksa          #+#    #+#             */
/*   Updated: 2024/05/19 22:50:09 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_args(int argc)
{
	if (argc != 2)
		throw_error("Please specify map for game");
}

void	extension_validation(char *path)
{
	if (!(ft_strlen(path) < 4))
		if (!(ft_strcmp(path + (ft_strlen(path) - 4), ".ber")))
			return ;
	throw_error("File is not .ber format");
}

void	path_validation(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		throw_error("Cannot open file");
	close(fd);
}

void	is_rectangular(char *path)
{
	int		fd;
	char	*res;
	size_t	len;

	fd = open(path, O_RDONLY);
	res = get_next_line(fd);
	len = ft_strlen(res);
	while (res && len == ft_strlen(res))
	{
		free(res);
		res = get_next_line(fd);
	}
	if (!res)
		return ;
	throw_error("Lol");
}

void	parse(int argc, char **argv)
{
	check_args(argc);
	extension_validation(argv[1]);
	path_validation(argv[1]);
	is_rectangular(argv[1]);
}
