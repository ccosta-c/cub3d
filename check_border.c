/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_border.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <ccosta-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 18:05:20 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/11/23 12:12:03 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lib.h"

void	check_borders(t_data *data)
{
	int	x;
	int	y;
	
	y = 0;
	data->map_found = 0;
	get_map_4_checks(data);
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == '0' || data->map[y][x] == 'N'
				|| data->map[y][x] == 'S' || data->map[y][x] == 'W'
					|| data->map[y][x] == 'E')
				flood_fill(data->map, data, x, y);
			x++;
		}
		y++;
	}
}

void	flood_fill(char **map, t_data *data, int x, int y)
{
	if (map[y][x] == '1' || map[y][x] == '#' || !map[y][x])
		return ;
	else if (map[y][x] == ' ')
		error_handler_checks(data, -12);
	else
	{
		map[y][x] = '#';
		flood_fill(map, data, (x + 1), y);
		flood_fill(map, data, (x - 1), y);
		flood_fill(map, data, x, (y + 1));
		flood_fill(map, data, x, (y - 1));
	}
}
