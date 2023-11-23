/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <ccosta-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:56:39 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/11/21 14:28:35 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lib.h"

void	verify_map(t_data	*data)
{
	check_characters(data->og_map, data);
	print_cub_info(data);
}

void	check_characters(char **array, t_data *data)
{
	int		x;
	int		y;

	y = 0;
	while (array[y])
	{
		x = 0;
		while (array[y][x])
		{
			if (!(array[y][x] == '1' || array[y][x] == '0' || array[y][x] == 'N'
				|| array[y][x] == 'S' || array[y][x] == 'W'
				|| array[y][x] == 'E' || array[y][x] == ' '))
				error_handler(data, -10);
			verify_player(data, array[y][x], x, y);
			x++;
		}
		y++;
	}
}

void	verify_player(t_data *data, char letter, int x, int y)
{
	if (letter == 'N' || letter == 'S' || letter == 'W' || letter == 'E')
	{
		if (data->info->player_x != 0 || data->info->player_y != 0)
			error_handler(data, -11);
		data->info->player_x = x;
		data->info->player_y = y;
	}
}
