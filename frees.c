/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <ccosta-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:22:26 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/11/24 12:24:32 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lib.h"

int	error_handler_checks(t_data *data, int i)
{
	if (i == -1)
		printf(RED "Error\n%s." NRM, strerror(errno));
	if (i == -2)
		printf(RED "Error\nColor codes must be between 0 and 255.\n" NRM);
	if (i == -4)
		printf(RED "Error\nPlease provide the ceiling RGB data.\n" NRM);
	if (i == -5)
		printf(RED "Error\nPlease provide the floor RGB data.\n" NRM);
	if (i == -6)
		printf(RED "Error\nSomething went wrong opening the xpm file.\n" NRM);
	if (i == -7)
		printf(RED "Error\nInvalid RGB color code.\n" NRM);
	if (i == -8)
		printf(RED "Error\nMap not found.\n" NRM);
	if (i == -9)
		printf(RED "Error\nOne of the color numbers missing.\n" NRM);
	if (i == -10)
		printf(RED "Error\nInvalid characters on the og_map.\n" NRM);
	if (i == -11)
		printf(RED "Error\nMore than one player character found.\n" NRM);
	if (i == -12)
		printf(RED "Error\nInvalid Map!\n" NRM);
	free_exit_checks(data);
	exit(i);
}

void	free_exit_checks(t_data *data)
{
	free_mlx_checks(data);
	if (data->info->no_tex)
		free(data->info->no_tex);
	if (data->info->so_tex)
		free(data->info->so_tex);
	if (data->info->ea_tex)
		free(data->info->ea_tex);
	if (data->info->we_tex)
		free(data->info->we_tex);
	free(data->info->file_path);
	free(data->info);
	free(data->img);
	free(data->no);
	free(data->so);
	free(data->we);
	free(data->ea);
	if (data->map)
		free_array(data->map);
	if (data->og_map)
		free_array(data->og_map);
	free(data);
}

void	free_mlx_checks(t_data *data)
{
	if (data->no->img && data->so->img && data->ea->img
		&& data->we->img)
	{
		mlx_destroy_image(data->mlx, data->img->img);
		mlx_destroy_image(data->mlx, data->no->img);
		mlx_destroy_image(data->mlx, data->so->img);
		mlx_destroy_image(data->mlx, data->ea->img);
		mlx_destroy_image(data->mlx, data->we->img);
		if (data->win)
		{
			mlx_destroy_window(data->mlx, data->win);
			free(data->win);
		}
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
}
