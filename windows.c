/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <ccosta-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 11:36:07 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/11/30 16:00:29 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lib.h"

void	start_windows(t_data *data)
{
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "cub3D");
	draw_raycast(data);
	mlx_hook(data->win, DestroyNotify, StructureNotifyMask, &free_exit, data);
	//mlx_loop_hook(data->mlx, game_loop, data);
	mlx_loop(data->mlx);
}

void	draw_raycast(t_data *data)
{
	put_ceiling_floor(data);
	data->i = 0;
	while (data-> i < WIDTH)
	{
		ray_calculations(data);
		get_step_sidedist(data);
		get_hit(data);
		get_wall_h(data);
		get_tex_wall(data);
		draw_wall(data, data->i);
		data->i++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img->img, 0, 0);
}

/*int	game_loop(t_data *data)
{
	//se nao tiver moves
	mlx_destroy_image(data->mlx, data->img->img);
	data->img->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	draw_raycast(data);
	return (0);
}*/
