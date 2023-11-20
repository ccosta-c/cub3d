/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <ccosta-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 09:37:30 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/11/20 10:32:52 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lib.h"

void	get_map(t_data *data)
{
	get_size(data);
	get_map_array(data);
	printf("Map Height- %i\n", data->map_height + 1);
	printf("Map Width- %i\n", data->map_width + 1);
	print_array(data->map);
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
}

void	write_line(t_data *data, char *line, int j)
{
	int		i;
	int		l;
	bool	written_stuff;

	written_stuff = false;
	i = 0;
	l = 0;
	data->map[j] = malloc(sizeof (char) * data->map_width + 2);
	while (line[i])
	{
		if (written_stuff == false)
		{
			data->map[j][l++] = line[i];
			if (line[i] != ' ' && line[i] != '\t')
				written_stuff = true;
		}
		else
		{
			if (line[i] != ' ' && line[i] != '\t')
				data->map[j][l++] = line[i];
			else
				check_rest_line(data->map[j], line, &i, &l);
		}
		i++;
	}
	fill_line(data, data->map[j], l);
}

void	check_rest_line(char *array_line, char *line, int *i, int *l)
{
	int	len;
	len = strlen(line);

	while (len < 0)
	{
		if (line[len] != ' ' && line[len] != '\t')
			break ;
		len--;
	}
	while (*i <= len)
	{
		array_line[*l] = line[*i];
		i++;
	}
}

void	fill_line(t_data *data, char *array_line, int l)
{
	while (l < data->map_width)
	{
		array_line[l] = ' ';
		l++;
	}
	array_line[l] = '\0';
}
