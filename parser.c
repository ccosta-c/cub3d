/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <ccosta-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:40:12 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/11/23 14:22:56 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lib.h"

void	parser(t_data *data)
{
	int	fd;

	fd = open(data->info->file_path, O_RDONLY);
	if (fd == -1)
		error_handler(data, -1);
	get_tex_col(data, fd);
	close(fd);
}

void	get_tex_col(t_data *data, int fd)
{
	char	*line;
	int		error;

	error = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		get_textures(data, line);
		if (error == 0)
			error = get_colors(data, line);
		free(line);
	}
	if (error != 0)
	{
		free(line);
		close(fd);
		error_handler(data, error);
	}
	check_textures(data);
	check_colors(data);
}

void	get_textures(t_data *data, char *line)
{
	char	**pp;

	pp = ft_split(line, ' ');
	if (ft_strncmp("NO", pp[0], 2) == 0)
	{
		data->info->no_tex = ft_strtrim(pp[1], "\n");
	}
	if (ft_strncmp("SO", pp[0], 2) == 0)
	{
		data->info->so_tex = ft_strtrim(pp[1], "\n");
	}
	if (ft_strncmp("WE", pp[0], 2) == 0)
	{
		data->info->we_tex = ft_strtrim(pp[1], "\n");
	}
	if (ft_strncmp("EA", pp[0], 2) == 0)
	{
		data->info->ea_tex = ft_strtrim(pp[1], "\n");
	}
	free_array(pp);
}

int	get_colors(t_data	*data, char *line)
{
	char	**rgb;
	char	*colors;

	if (ft_strncmp("F", line, 1) == 0 && data->info->floor_rgb == false)
	{
		colors = ft_strtrim(line, "F ");
		if (colors[0] == '\0' || colors[0] == '\n')
			return (free(colors), -5);
		rgb = ft_split(colors, ',');
		free(colors);
		if (check_numeric(rgb) == -1)
			return (free_array(rgb), -7);
		convert_string_to_rgb(data, rgb, 'F');
		free_array(rgb);
	}
	if (ft_strncmp("C", line, 1) == 0 && data->info->ceiling_rgb == false)
	{
		colors = ft_strtrim(line, "C ");
		if (colors[0] == '\0' || colors[0] == '\n')
			return (free(colors), -4);
		rgb = ft_split(colors, ',');
		free(colors);
		if (check_numeric(rgb) == -1)
			return (free_array(rgb), -7);
		convert_string_to_rgb(data, rgb, 'C');
		free_array(rgb);
	}
	return (0);
}
