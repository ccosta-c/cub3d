/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <ccosta-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 15:47:34 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/11/30 16:02:57 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lib.h"

void	put_ceiling_floor(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	init_color(data);
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			if (y <= (HEIGHT / 2))
				my_mlx_pixel_put(data, x, y, data->info->c_color);
			if (y > (HEIGHT / 2))
				my_mlx_pixel_put(data, x, y, data->info->f_color);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img->img, 0, 0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->img->addr + (y * data->img->line_length + x * (data->img->bpp / 8));
	*(unsigned int *)dst = color;
}

void	init_color(t_data *data)
{
	data->info->c_color = (0x010000 * data->info->ceiling_r) + (0x000100 * data->info->ceiling_g) + data->info->ceiling_b;
	data->info->f_color = (0x010000 * data->info->floor_r) + (0x000100 * data->info->floor_g) + data->info->floor_b;
}