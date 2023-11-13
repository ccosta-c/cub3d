/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <ccosta-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:40:12 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/11/13 12:58:28 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lib.h"

int	parser(t_data *data, char *path)
{
	int	fd;

	if (data == NULL)
		;
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

	line = 1;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		check_textures(line);
	}
}

void	check_textures(char *line)
{
	int	i;

	i = 0;
	if (strncmp("NO", line, 2) == 0)
		
}
