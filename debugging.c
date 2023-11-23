/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debugging.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <ccosta-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:53:19 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/11/23 11:23:53 by ccosta-c         ###   ########.fr       */
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
	printf(GRN"Retrieving colors information:\n"BLD);
	printf("\033[38;2;%i;%i;%im", data->info->floor_r,
		data->info->floor_g, data->info->floor_b);
	printf("Floor Color- (%i,%i,%i)\n", data->info->floor_r,
		data->info->floor_g, data->info->floor_b);
	printf("\033[38;2;%i;%i;%im", data->info->ceiling_r,
		data->info->ceiling_g, data->info->ceiling_b);
	printf("Ceiling Color- (%i,%i,%i)\n\n"BLD, data->info->ceiling_r,
		data->info->ceiling_g, data->info->ceiling_b);
	printf(GRN"Retrieving og_map information:\n"BLD);
	printf("Map Height: %i\n", data->map_height + 1);
	printf("Map Width: %i\n", data->map_width + 1);
	print_map(data, data->og_map, 2);
}

void	print_map(t_data *data, char **map, int size)
{
	int	i;

	i = 0;
	printf("Map Array:\n");
	line_print_map(data, size);
	while (map[i] != NULL)
	{
		printf(GRY"*"BLD);
		printf("%s", map[i]);
		printf(GRY"*"BLD);
		i++;
		printf("\n");
	}
	line_print_map(data, size);
	printf("" NRM);
}

void	line_print_map(t_data *data, int size)
{
	int	i;

	i = -1;
	while (++i <= data->map_width + size)
		printf(GRY"*");
	printf("\n"BLD);
}
