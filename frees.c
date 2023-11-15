/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <ccosta-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:22:26 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/11/15 19:11:04 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lib.h"

int	error_handler(t_data *data, int i)
{
	if (i == -1)
		printf(RED "Error\n%s" NRM, strerror(errno));
	if (i == -2)
		printf(RED "Error\nColor codes are invalid.\n" NRM);
	if (i == -4)
		printf(RED "Error\nPlease provide the ceiling RGB data.\n" NRM);
	if (i == -5)
		printf(RED "Error\nPlease provide the floor RGB data.\n" NRM);
	free_exit(data);
	exit(i);
}

void	free_exit(t_data *data)
{
	if (data->info->no_tex)
		free(data->info->no_tex);
	if (data->info->so_tex)
		free(data->info->so_tex);
	if (data->info->ea_tex)
		free(data->info->ea_tex);
	if (data->info->we_tex)
		free(data->info->we_tex);
	free(data->info);
	free(data);
}
