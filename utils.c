/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <ccosta-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:54:43 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/11/15 19:13:49 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lib.h"

void	convert_string_to_rgb(t_data *data, char **rgb, char place)
{
	if (place == 'F')
	{
		data->info->floor_r = ft_atoi(rgb[0]);
		data->info->floor_g = ft_atoi(rgb[1]);
		data->info->floor_b = ft_atoi(rgb[2]);
		data->info->floor_rgb = true;
	}
	if (place == 'C')
	{
		data->info->ceiling_r = ft_atoi(rgb[0]);
		data->info->ceiling_g = ft_atoi(rgb[1]);
		data->info->ceiling_b = ft_atoi(rgb[2]);
		data->info->ceiling_rgb = true;
	}
}
