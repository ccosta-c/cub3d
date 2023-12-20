/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <ccosta-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:29:04 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/12/19 12:14:13 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lib.h"

int	free_exit(t_data *data)
{
	free_mlx(data);
	free(data->info->no_tex);
	free(data->info->so_tex);
	free(data->info->ea_tex);
	free(data->info->we_tex);
	free(data->info->file_path);
	free(data->info);
	free(data->img);
	free(data->no);
	free(data->so);
	free(data->we);
	free(data->ea);
	free_array(data->map);
	free_array(data->og_map);
	free(data);
	exit(0);
}

void	free_mlx(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img->img);
	mlx_destroy_image(data->mlx, data->no->img);
	mlx_destroy_image(data->mlx, data->so->img);
	mlx_destroy_image(data->mlx, data->ea->img);
	mlx_destroy_image(data->mlx, data->we->img);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
}
