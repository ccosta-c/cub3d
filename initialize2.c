/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macastan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:42:35 by macastan          #+#    #+#             */
/*   Updated: 2023/12/18 17:42:38 by macastan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lib.h"

void	init_texture_stuff(t_data *data)
{
	data->img->addr = NULL;
	data->img->height = 0;
	data->img->width = 0;
	data->img->bpp = 0;
	data->img->line_length = 0;
	data->img->endian = 0;
	data->no->addr = NULL;
	data->no->height = 0;
	data->no->width = 0;
	data->no->bpp = 0;
	data->no->line_length = 0;
	data->no->endian = 0;
	data->so->addr = NULL;
	data->so->height = 0;
	data->so->width = 0;
	data->so->bpp = 0;
	data->so->line_length = 0;
	data->so->endian = 0;
	init_texture_stuff2(data);
}

void	init_texture_stuff2(t_data *data)
{
	data->we->addr = NULL;
	data->we->height = 0;
	data->we->width = 0;
	data->we->bpp = 0;
	data->we->line_length = 0;
	data->we->endian = 0;
	data->ea->addr = NULL;
	data->ea->height = 0;
	data->ea->width = 0;
	data->ea->bpp = 0;
	data->ea->line_length = 0;
	data->ea->endian = 0;
}

void	open_addr(t_data *data)
{
	data->img->addr = mlx_get_data_addr(data->img->img, &data->img->bpp, &data->img->line_length, &data->img->endian);
	data->no->addr = mlx_get_data_addr(data->no->img, &data->no->bpp, &data->no->line_length, &data->no->endian);
	data->so->addr = mlx_get_data_addr(data->so->img, &data->so->bpp, &data->so->line_length, &data->so->endian);
	data->we->addr = mlx_get_data_addr(data->we->img, &data->we->bpp, &data->we->line_length, &data->we->endian);
	data->ea->addr = mlx_get_data_addr(data->ea->img, &data->ea->bpp, &data->ea->line_length, &data->ea->endian);
}