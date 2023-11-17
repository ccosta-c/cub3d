/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <ccosta-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:38:59 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/11/17 10:10:56 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lib.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc == 2)
	{
		check_extension(argv[1], ".cub");
		data = initialize_struct();
		parser(data, argv[1]);
		start_mlx(data);
		free_exit(data);
	}
	else
	{
		printf(RED "Error\nPlease include the map file.\n" NRM);
	}
}
