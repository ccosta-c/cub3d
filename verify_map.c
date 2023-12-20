/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <ccosta-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:56:39 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/11/30 15:40:09 by ccosta-c         ###   ########.fr       */
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
				error_handler_checks(data, -10);
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
		if (data->p_x != 0 || data->p_y != 0)
			error_handler_checks(data, -11);
		data->p_x = x + 0.5;
		data->p_y = y + 0.5;
		if (letter == 'N')
			fill_player_dir(data, 'N');
		if (letter == 'S')
			fill_player_dir(data, 'S');
		if (letter == 'E')
			fill_player_dir(data, 'E');
		if (letter == 'W')
			fill_player_dir(data, 'W');
	}
}

void	fill_player_dir(t_data *data, char letter)
{
	if (letter == 'N')
	{
		data->dir_x = 0;
		data->dir_y = -1;
		data->plane_x = 0.66;
		data->plane_y = 0;
	}
	if (letter == 'S')
	{
		data->dir_x = 0;
		data->dir_y = 1;
		data->plane_x = -0.66;
		data->plane_y = 0;
	}
	fill_player_dir2(data, letter);
}

void	fill_player_dir2(t_data *data, char letter)
{
	if (letter == 'W')
	{
		data->dir_x = -1;
		data->dir_y = 0;
		data->plane_x = 0;
		data->plane_y = -0.66;
	}
	if (letter == 'E')
	{
		data->dir_x = 1;
		data->dir_y = 0;
		data->plane_x = 0;
		data->plane_y = 0.66;
	}
}
