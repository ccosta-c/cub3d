/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <ccosta-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 16:48:56 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/11/17 13:59:51 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lib.h"

t_data	*initialize_struct(void)
{
	t_data	*structure;

	structure = malloc((sizeof (t_data)));
	structure->info = malloc(sizeof (t_info));
	structure->textures = malloc(sizeof (t_textures));
	structure->textures->height = 0;
	structure->textures->width = 0;
	structure->info->floor_r = 0;
	structure->info->floor_g = 0;
	structure->info->floor_b = 0;
	structure->info->ceiling_r = 0;
	structure->info->ceiling_g = 0;
	structure->info->ceiling_b = 0;
	structure->info->floor_rgb = false;
	structure->info->ceiling_rgb = false;
    structure->mlx = NULL;
	structure->textures->no = NULL;
	structure->textures->so = NULL;
	structure->textures->ea = NULL;
	structure->textures->we = NULL;
    structure->info->no_tex = NULL;
    structure->info->so_tex = NULL;
    structure->info->ea_tex = NULL;
    structure->info->we_tex = NULL;
	return (structure);
}

void	start_mlx(t_data *data)
{
    data->mlx = mlx_init();
	open_images(data);
}

void	open_images(t_data *data)
{
	data->textures->no = mlx_xpm_file_to_image(data->mlx, data->info->no_tex,
			&data->textures->width, &data->textures->height);
	data->textures->so = mlx_xpm_file_to_image(data->mlx, data->info->so_tex,
			&data->textures->width, &data->textures->height);
	data->textures->ea = mlx_xpm_file_to_image(data->mlx, data->info->ea_tex,
			&data->textures->width, &data->textures->height);
	data->textures->we = mlx_xpm_file_to_image(data->mlx, data->info->we_tex,
			&data->textures->width, &data->textures->height);
	if ((data->textures->no == NULL) || (data->textures->so == NULL)
		|| (data->textures->ea == NULL) || (data->textures->we == NULL))
		error_handler(data, -6);
}
