/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: logname <logname@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 19:54:10 by logname           #+#    #+#             */
/*   Updated: 2023/11/19 06:08:27 by logname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lib.h"

void	get_size(t_data *data)
{
	char	*line;
	int		fd;

	fd = open(data->info->file_path, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (check_line(data, line) == 1 || data->map_found == 1)
		{
			check_width(data, line);
			data->map_height++;
		}
		free(line);
	}
	close (fd);
	if (data->map_found == 0)
		error_handler_checks(data, -8);
	data->map_found = 0;
}

int	check_line(t_data *data, char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == ' ' || line[i] == '\t')
			i++;
		else
		{
			if (line[i] == '1')
			{
				data->map_found = 1;
				return (1);
			}
			return (0);
		}
		i++;
	}
	return (0);
}

void	check_width(t_data *data, char *line)
{
	int	length;
	int	i;

	i = 0;
	length = 0;
	while (line[i] != '\n' && line[i] != '\0')
	{
		if (line[i] != ' ' && line[i] != '\t')
			length = i;
		i++;
	}
	if (length > data->map_width)
		data->map_width = length;
}
