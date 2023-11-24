/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <ccosta-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 16:48:56 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/11/24 15:13:19 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lib.h"

t_data	*initialize_struct(char *path)
{
	t_data	*structure;

	structure = malloc((sizeof (t_data)));
	structure->info = initialize_tinfo(path);
	structure->textures = malloc(sizeof (t_textures));
	structure->textures->height = 0;
	structure->textures->width = 0;
	structure->map_height = 0;
	structure->map_width = 0;
	structure->map_found = false;
	structure->win = NULL;
	structure->mlx = NULL;
	structure->textures->no = NULL;
	structure->textures->so = NULL;
	structure->textures->ea = NULL;
	structure->textures->we = NULL;
	structure->og_map = NULL;
	structure->map = NULL;
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
		error_handler_checks(data, -6);
}

t_info	*initialize_tinfo(char *path)
{
	t_info	*structure;

	structure = malloc(sizeof (t_info));
	structure->file_path = ft_strdup(path);
	structure->floor_r = 0;
	structure->floor_g = 0;
	structure->floor_b = 0;
	structure->ceiling_r = 0;
	structure->ceiling_g = 0;
	structure->ceiling_b = 0;
	structure->player_x = 0;
	structure->player_y = 0;
	structure->player_dir_x = 0;
	structure->player_dir_y = 0;
	structure->floor_rgb = false;
	structure->ceiling_rgb = false;
	structure->no_tex = NULL;
	structure->so_tex = NULL;
	structure->ea_tex = NULL;
	structure->we_tex = NULL;
	return (structure);
}
