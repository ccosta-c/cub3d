/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <ccosta-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 17:43:54 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/11/17 10:11:05 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lib.h"

void	check_colors(t_data *data)
{
	if ((data->info->floor_r < 0 || data->info->floor_r > 255)
		|| (data->info->floor_g < 0 || data->info->floor_g > 255)
		|| (data->info->floor_b < 0 || data->info->floor_b > 255)
		|| (data->info->ceiling_r < 0 || data->info->ceiling_r > 255)
		|| (data->info->ceiling_g < 0 || data->info->ceiling_g > 255)
		|| (data->info->ceiling_b < 0 || data->info->ceiling_b > 255))
		error_handler(data, -2);
	if (data->info->ceiling_rgb == false)
		error_handler(data, -4);
	if (data->info->floor_rgb == false)
		error_handler(data, -5);
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
