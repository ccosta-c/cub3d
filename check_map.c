/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: logname <logname@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 19:54:10 by logname           #+#    #+#             */
/*   Updated: 2023/11/18 20:54:39 by logname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lib.h"

void    get_map(t_data *data)
{
	get_height(data);
	printf("Map Height- %i\n", data->map_height);
}

void    get_height(t_data *data)
{
	char *line;
	int fd;

	fd = open(data->info->file_path, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (check_line(data, line) == 1 || data->map_start != 0)
		{
			data->map_height++;
		}
		free(line);
	}
	if (data->map_start == 0)
		error_handler(data, -8);
}

int check_line(t_data *data, char *line)
{
    int i;

    i = 0;
    while(line[i])
    {
		if(line[i] == ' ' || line[i] == '\t')
			i++;
        else
		{
			if (line[i] == '1')
				return (1);
			return (0);
		}
        i++;
    }
	return (0);
}