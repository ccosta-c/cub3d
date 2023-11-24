/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <ccosta-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 11:36:07 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/11/24 12:03:18 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lib.h"

void	start_windows(t_data *data)
{
	data->win = mlx_new_window(data->mlx, 860, 860, "cub3D");
	mlx_hook(data->win, DestroyNotify, StructureNotifyMask, &free_exit, data);
	mlx_loop(data->mlx);
}
