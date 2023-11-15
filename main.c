/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <ccosta-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:38:59 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/11/15 18:51:01 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lib.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc == 2)
	{
		check_dot_cub(argv[1]);
		data = initialize_struct();
		parser(data, argv[1]);
		free_exit(data);
	}
	else
	{
		printf(RED "Error\nPlease include the map file.\n" NRM);
	}
}
