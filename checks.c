/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <ccosta-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 17:43:54 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/11/23 13:49:33 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lib.h"

void	check_colors(t_data *data)
{
	if (data->info->ceiling_rgb == false)
		error_handler_checks(data, -4);
	if (data->info->floor_rgb == false)
		error_handler_checks(data, -5);
	if ((data->info->floor_r == -1) || (data->info->floor_g == -1)
		|| (data->info->floor_b == -1) || (data->info->ceiling_r == -1)
		|| (data->info->ceiling_g == -1) || (data->info->ceiling_b == -1))
		error_handler_checks(data, -9);
	if ((data->info->floor_r < 0 || data->info->floor_r > 255)
		|| (data->info->floor_g < 0 || data->info->floor_g > 255)
		|| (data->info->floor_b < 0 || data->info->floor_b > 255)
		|| (data->info->ceiling_r < 0 || data->info->ceiling_r > 255)
		|| (data->info->ceiling_g < 0 || data->info->ceiling_g > 255)
		|| (data->info->ceiling_b < 0 || data->info->ceiling_b > 255))
		error_handler_checks(data, -2);
}

void	check_extension(char *file, char *extension)
{
	int	i;

	i = ft_strlen(file);
	i -= 4;
	if (ft_strncmp(&file[i], extension, 4) == 0)
		return ;
	ft_printf(RED "ERROR!\nWrong extension!\n" NRM);
	exit(-3);
}

void	check_textures(t_data *data)
{
	if (!*data->info->no_tex)
		printf(RED "Error\nNorth texture is missing.\n" NRM);
	if (!*data->info->so_tex)
		printf(RED "Error\nSouth texture is missing.\n" NRM);
	if (!*data->info->ea_tex)
		printf(RED "Error\nEast texture is missing.\n" NRM);
	if (!*data->info->we_tex)
		printf(RED "Error\nWest texture is missing.\n" NRM);
	if (!*(data->info->no_tex) || !*(data->info->so_tex)
		|| !*(data->info->ea_tex) || !*(data->info->we_tex))
		error_handler_checks(data, 0);
}

int	check_numeric(char **rgb)
{
	int	i;
	int	j;

	i = 0;
	while (i < 3)
	{
		j = 0;
		while (rgb[i][j])
		{
			if ((!((rgb[i][j] >= '0') && (rgb[i][j] <= '9')))
				&& (rgb[i][j] != ' ') && (rgb[i][j] != '-')
					&& (rgb[i][j] != '\n'))
			{
				return (-1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
