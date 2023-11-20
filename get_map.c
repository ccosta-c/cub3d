/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <ccosta-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 09:37:30 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/11/20 12:13:20 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lib.h"

void	get_map(t_data *data)
{
	get_size(data);
	printf("Map Height- %i\n", data->map_height + 1);
	printf("Map Width- %i\n", data->map_width + 1);
	get_map_array(data);
	print_map(data);
}

void	get_map_array(t_data *data)
{
	char	*line;
	int		fd;
	int		j;

	j = 0;
	fd = open(data->info->file_path, O_RDONLY);
	data->map = malloc(sizeof (char *) * (data->map_height + 1));
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (data->map_found == 0)
			check_line(data, line);
		if (data->map_found == 1)
		{
			write_line(data, line, j);
			j++;
		}
		free(line);
	}
	data->map[j] = NULL;
}

void	write_line(t_data *data, char *line, int j)
{
	int		i;
	int		l;
	char	*new_line;

	i = 0;
	l = 0;
	new_line = ft_strtrim(line, "\n");
	data->map[j] = malloc(sizeof (char) * data->map_width + 2);
	while (new_line[i] && i <= data->map_width)
	{
		data->map[j][l++] = new_line[i++];
	}
	fill_line(data, data->map[j], l);
}

void	fill_line(t_data *data, char *array_line, int l)
{
	while (l <= data->map_width)
	{
		array_line[l] = ' ';
		l++;
	}
	array_line[l] = '\0';
}
