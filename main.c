/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <ccosta-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:38:59 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/11/14 15:26:50 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lib.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc == 2)
	{
		data = malloc((sizeof (t_data)));
		data->info = malloc(sizeof (t_info));
		if (parser(data, argv[1]) == -1)
			return (-1);
	}
	else
	{
		printf(RED "Error\nPlease include the map file.\n" NRM);
	}
}
