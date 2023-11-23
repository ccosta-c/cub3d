/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <ccosta-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:31:53 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/11/23 11:48:49 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lib.h"

void	get_map_4_checks(t_data *data)
{
	char	*line;
	int		fd;
	int		j;

	j = 1;
	fd = open(data->info->file_path, O_RDONLY);
	data->map = malloc(sizeof (char *) * (data->map_height + 3));
	data->map[0] = malloc(sizeof (char *) * (data->map_width + 3));
	fill_line(data->map[0], 0, data->map_width + 2);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (data->map_found == 0)
			check_line(data, line);
		if (data->map_found == 1)
			write_line_4_checks(data, data->map, line, j++);
		free(line);
	}
	data->map[j] = malloc(sizeof (char *) * (data->map_height + 3));
	fill_line(data->map[j], 0, data->map_width + 2);
	data->map[++j] = NULL;
}

void	write_line_4_checks(t_data *data, char **map, char *line, int j)
{
	int		i;
	int		l;
	char	*new_line;

	i = 0;
	l = 1;
	new_line = ft_strtrim(line, "\n");
	map[j] = malloc(sizeof (char) * data->map_width + 4);
	map[j][0] = ' ';
	while (new_line[i] && i <= data->map_width)
	{
		map[j][l++] = new_line[i++];
	}
	fill_line(map[j], l, data->map_width + 2);
	free(new_line);
}
