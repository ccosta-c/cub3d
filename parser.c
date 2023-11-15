/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <ccosta-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:40:12 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/11/15 19:07:21 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lib.h"

void	parser(t_data *data, char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		error_handler(data, -1);
	get_tex_col(data, fd);
	print_cub_info(data);
	close(fd);
}

void	get_tex_col(t_data *data, int fd)
{
	char	*line;

	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		get_textures(data, line);
		get_colors(data, line);
		free(line);
	}
	check_colors(data);

}

void	get_textures(t_data *data, char *line)
{
	char	**pp;

	pp = NULL;
	if (ft_strncmp("NO", line, 2) == 0)
	{
		pp = ft_split(line, ' ');
		data->info->no_tex = ft_strtrim(pp[1], "\n");
	}
	if (ft_strncmp("SO", line, 2) == 0)
	{
		pp = ft_split(line, ' ');
		data->info->so_tex = ft_strtrim(pp[1], "\n");
	}
	if (ft_strncmp("WE", line, 2) == 0)
	{
		pp = ft_split(line, ' ');
		data->info->we_tex = ft_strtrim(pp[1], "\n");
	}
	if (ft_strncmp("EA", line, 2) == 0)
	{
		pp = ft_split(line, ' ');
		data->info->ea_tex = ft_strtrim(pp[1], "\n");
	}
	if (pp)
		free_array(pp);
}

void	get_colors(t_data	*data, char *line)
{
	char	**rgb;
	char	*colors;

	if (ft_strncmp("F", line, 1) == 0 && data->info->floor_rgb == false)
	{
		colors = ft_strtrim(line, "F ");
		rgb = ft_split(colors, ',');
		free(colors);
		data->info->floor_r = ft_atoi(rgb[0]);
		data->info->floor_g = ft_atoi(rgb[1]);
		data->info->floor_b = ft_atoi(rgb[2]);
		data->info->floor_rgb = true;
		free_array(rgb);
	}
	if (ft_strncmp("C", line, 1) == 0 && data->info->ceiling_rgb == false)
	{
		colors = ft_strtrim(line, "C ");
		rgb = ft_split(colors, ',');
		free(colors);
		data->info->ceiling_r = ft_atoi(rgb[0]);
		data->info->ceiling_g = ft_atoi(rgb[1]);
		data->info->ceiling_b = ft_atoi(rgb[2]);
		data->info->ceiling_rgb = true;
		free_array(rgb);
	}
}
