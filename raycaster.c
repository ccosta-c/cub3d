/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macastan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 11:51:41 by macastan          #+#    #+#             */
/*   Updated: 2023/12/20 11:51:43 by macastan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lib.h"

void	ray_calculations(t_data *data)
{
	data->camera_x = 2 * data->i / (double)WIDTH - 1;
	data->raydir_x = data->dir_x + data->plane_x * data->camera_x;
	data->raydir_y = data->dir_y + data->plane_y * data->camera_x;
	data->mapx = (int)data->p_x;
	data->mapy = (int)data->p_y;
	if (data->raydir_x == 0)
		data->delta_dist_x = 1e30;
	else
		data->delta_dist_x = fabs(1 / data->raydir_x);
	if (data->raydir_y == 0)
		data->delta_dist_y = 1e30;
	else
		data->delta_dist_y = fabs(1 / data->raydir_y);
	data->hit = 0;
}

void	get_step_sidedist(t_data *data)
{
	if (data->raydir_x < 0)
	{
		data->stepx = -1;
		data->side_dist_x = (data->p_x - data->mapx) * data->delta_dist_x;
	}
	else
	{
		data->stepx = 1;
		data->side_dist_x = (data->mapx + 1.0 - data->p_x) * data->delta_dist_x;
	}
	if (data->raydir_y < 0)
	{
		data->stepy = -1;
		data->side_dist_y = (data->p_y - data->mapy) * data->delta_dist_y;
	}
	else
	{
		data->stepy = 1;
		data->side_dist_y = (data->mapy + 1.0 - data->p_y) * data->delta_dist_y;
	}
}

void	get_hit(t_data *data)
{
	while (data->hit == 0)
	{
		if (data->side_dist_x < data->side_dist_y)
		{
			data->side_dist_x += data->delta_dist_x;
			data->mapx += data->stepx;
			data->side = 0;
		}
		else
		{
			data->side_dist_y += data->delta_dist_y;
			data->mapy += data->stepy;
			data->side = 1;
		}
		if (data->og_map[data->mapy][data->mapx] == '1')
			data->hit = 1;
	}
}

void	get_wall_h(t_data *data)
{
	if (data->side == 0)
		data->pwalldist = (data->side_dist_x - data->delta_dist_x);
	else
		data->pwalldist = (data->side_dist_y - data->delta_dist_y);
	if (data->pwalldist)
		data->lineheight = (int)(HEIGHT / data->pwalldist);
	else
		data->lineheight = HEIGHT;
	data->draw_start = -data->lineheight / 2 + HEIGHT / 2;
	if (data->draw_start < 0)
		data->draw_start = 0;
	data->draw_end = data->lineheight / 2 + HEIGHT / 2;
	if (data->draw_end >= HEIGHT)
		data->draw_end = HEIGHT - 1;
}

void	get_tex_wall(t_data *data)
{
	if (data->side == 1)
	{
		if (data->raydir_y < 0)
			data->aux = data->so;
		else
			data->aux = data->no;
	}
	else
	{
		if (data->raydir_x < 0)
			data->aux = data->ea;
		else
			data->aux = data->we;
	}
}