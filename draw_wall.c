/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macastan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 12:48:19 by macastan          #+#    #+#             */
/*   Updated: 2023/12/20 12:48:21 by macastan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lib.h"

void	draw_wall(t_data *data, int i)
{
	int	color;
	int	y;

	get_tex_x(data);
	y = data->draw_start;
	color = 0;
	data->tex_x = (int)(data->wall_x * (double)TEX_WIDTH);
	data->tex_x = TEX_WIDTH - data->tex_x - 1;
	data->text_step = 1.0 * TEX_WIDTH / data->lineheight;
	data->text_pos = (data->draw_start - HEIGHT / 2 + data->lineheight / 2) * data->text_step;
	while (y < data->draw_end)
	{
		data->tex_y = (int)data->text_pos & (TEX_WIDTH - 1);
		data->text_pos += data->text_step;
		if (i >= 0 && y >= 0 && data->tex_x >= 0 && data->tex_y >= 0)
		{
			color = ft_get_pixel(data, data->tex_x, data->tex_y);
			my_mlx_pixel_put(data, i, y, color);
		}
		y++;
	}
}

int	ft_get_pixel(t_data *data, int x, int y)
{
	return (*(unsigned int *)((data->aux->addr + (y * data->aux->line_length) + (x * data->aux->bpp / 8))));
}

void	get_tex_x(t_data *data)
{
	if (data->side == 0)
	{
		data->wall_x = data->p_y + data->pwalldist * data->raydir_y;
		data->wall_x -= floor(data->wall_x);
	}
	if (data->side == 1)
	{
		data->wall_x = data->p_x + data->pwalldist * data->raydir_x;
		data->wall_x -= floor(data->wall_x);
	}
}