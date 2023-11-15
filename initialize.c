/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <ccosta-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 16:48:56 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/11/15 19:04:45 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lib.h"

t_data	*initialize_struct(void)
{
	t_data	*structure;

	structure = malloc((sizeof (t_data)));
	structure->info = malloc(sizeof (t_info));
	structure->info->floor_r = 0;
	structure->info->floor_g = 0;
	structure->info->floor_b = 0;
	structure->info->ceiling_r = 0;
	structure->info->ceiling_g = 0;
	structure->info->ceiling_b = 0;
	structure->info->floor_rgb = false;
	structure->info->ceiling_rgb = false;
	return (structure);
}
