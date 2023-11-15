/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debugging.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <ccosta-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:53:19 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/11/15 17:11:58 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lib.h"

void	print_cub_info(t_data *data)
{
	printf(GRN"Retrieving textures information:\n"BLD);
	printf("North- %s\n", data->info->no_tex);
	printf("South- %s\n", data->info->so_tex);
	printf("West- %s\n", data->info->we_tex);
	printf("East- %s\n\n", data->info->ea_tex);
	printf("\033[38;2;%i;%i;%im", data->info->floor_r,
		data->info->floor_g, data->info->floor_b);
	printf("Floor Color- (%i,%i,%i)\n"BLD, data->info->floor_r,
		data->info->floor_g, data->info->floor_b);
	printf("\033[38;2;%i;%i;%im", data->info->ceiling_r,
		data->info->ceiling_g, data->info->ceiling_b);
	printf("Ceiling Color- (%i,%i,%i)\n"NRM, data->info->ceiling_r,
		data->info->ceiling_g, data->info->ceiling_b);
}
