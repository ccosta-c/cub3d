/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <ccosta-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 15:47:34 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/11/30 16:02:57 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lib.h"

void	put_ceiling_floor(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < HEIGHT)
	{
		while (x < WIDTH)
		{
			if (y < HEIGHT/2)
				mlx_pixel_put(data->mlx, data->win, x, y, data->)
		}

	}
}
