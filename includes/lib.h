/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <ccosta-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:39:41 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/11/13 12:56:42 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
# define LIB_H

# include "../minilibx-linux/mlx.h"
# include <stdlib.h>
# include <X11/keysym.h>
# include <stdio.h>
# include <X11/X.h>
# include <unistd.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>

# define RED "\033[1;31m"
# define NRM "\033[1;37m"

typedef struct s_info
{
	char	*no_texture;
	char	*so_texture;
	char	*we_texture;
	char	*ea_texture;
	int		floor_r;
	int		floor_g;
	int		floor_b;
	int		ceiling_r;
	int		ceiling_g;
	int		ceiling_b;
}			t_info;

typedef struct s_data
{
	s_info	*info;
}			t_data;

////////////////////get_next_line.c////////////////////
char	*get_next_line(int fd);

///////////////////////parser.c///////////////////////
int		parser(t_data *data, char *path);
int		get_textures(t_data *data, int fd);
void	check_textures(char *line);

////////////////////////utils.c///////////////////////
int		ft_strncmp(const char *str1, const char *str2, size_t n);

#endif
