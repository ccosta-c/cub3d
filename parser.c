/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <ccosta-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:40:12 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/11/15 14:47:01 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lib.h"

int	parser(t_data *data, char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (printf(RED "Error\n%s" NRM, strerror(errno)), -1);
	if (get_textures(data, fd) == -1)
		return (-1);
	return (0);
}

int	get_textures(t_data *data, int fd)
{
	char	*line;

	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		check_textures(data, line);
	}
	return (0);
}

void	check_textures(t_data *data, char *line)
{
	char	**pp;

	if (ft_strncmp("NO", line, 2) == 0)
	{
		pp = ft_split(line, ' ');
		data->info->no_tex = ft_strdup(pp[1]);
	}
	if (ft_strncmp("SO", line, 2) == 0)
	{
		pp = ft_split(line, ' ');
		data->info->no_tex = ft_strdup(pp[1]);
	}
	if (ft_strncmp("WE", line, 2) == 0)
	{
		pp = ft_split(line, ' ');
		data->info->no_tex = ft_strdup(pp[1]);
	}
	if (ft_strncmp("EA", line, 2) == 0)
	{
		pp = ft_split(line, ' ');
		data->info->no_tex = ft_strdup(pp[1]);
	}
	free_array(pp);
}
