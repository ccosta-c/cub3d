/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <ccosta-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:39:41 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/11/17 13:54:56 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
# define LIB_H

# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"
# include <stdlib.h>
# include <X11/keysym.h>
# include <stdio.h>
# include <X11/X.h>
# include <unistd.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include <stdbool.h>

# define RED "\033[1;31m"
# define NRM "\033[0;37m"
# define BLD "\033[1;37m"
# define GRN "\033[1;32m"

typedef struct s_info
{
	char	*no_tex;
	char	*so_tex;
	char	*we_tex;
	char	*ea_tex;
	int		floor_r;
	int		floor_g;
	int		floor_b;
	bool	floor_rgb;
	int		ceiling_r;
	int		ceiling_g;
	int		ceiling_b;
	bool	ceiling_rgb;
}			t_info;

typedef struct s_textures
{
	int		height;
	int		width;
	void	*no;
	void	*so;
	void	*we;
	void	*ea;
}			t_textures;

typedef struct s_data
{
	t_info		*info;
	void		*mlx;
	t_textures	*textures;
}				t_data;

///////////////////////parser.c////////////////////////
void	parser(t_data *data, char *path);
void	get_tex_col(t_data *data, int fd);
void	get_textures(t_data *data, char *line);
void	get_colors(t_data	*data, char *line);
void	check_numeric(char **rgb, t_data *data);

///////////////////////checks.c////////////////////////
void	check_colors(t_data *data);
void	check_extension(char *file, char *extension);

////////////////////////utils.c////////////////////////


/////////////////////debugging.c///////////////////////
void	print_cub_info(t_data *data);

///////////////////////frees.c/////////////////////////
int		error_handler(t_data *data, int i);
void	free_exit(t_data *data);
void	free_mlx(t_data *data);

/////////////////////initialize.c//////////////////////
t_data	*initialize_struct(void);
void	start_mlx(t_data *data);
void	open_images(t_data *data);

#endif
