/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <ccosta-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 09:37:30 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/11/20 11:40:24 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lib.h"

void	get_map(t_data *data)
{
	get_size(data);
	printf("Map Height- %i\n", data->map_height + 1);
	printf("Map Width- %i\n", data->map_width + 1);
	get_map_array(data);
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
	char	*new_line;

	written_stuff = false;
	i = 0;
	l = 0;
	new_line = ft_strtrim(line, "\n");
	data->map[j] = malloc(sizeof (char) * data->map_width + 2);
	while (new_line[i])
	{
		if (written_stuff == false)
		{
			data->map[j][l++] = new_line[i];
			if (new_line[i] != ' ' && new_line[i] != '\t')
				written_stuff = true;
		}
		else
		{
			if (new_line[i] != ' ' && new_line[i] != '\t')
				data->map[j][l++] = new_line[i];
			else
			{
				check_rest_line(data->map[j], new_line, &i, &l);
				break ;
			}
		}
		i++;
	}
	fill_line(data, data->map[j], l);
}

void	check_rest_line(char *array_line, char *line, int *i, int *l)
{
	int	len;
	len = strlen(line);

	while (len > 0)
	{
		if (line[len] != ' ' && line[len] != '\t')
			break ;
		len--;
	}
	while (*i < len || i < data->map_width)
	{
		array_line[*l] = line[*i];
		(*l)++;
		(*i)++;
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
