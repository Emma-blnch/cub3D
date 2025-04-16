/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblancha <eblancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 12:51:51 by ema_blnch         #+#    #+#             */
/*   Updated: 2025/04/14 08:39:26 by eblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_game	*init_data(int argc)
{
	t_game	*data;

	(void)argc;
	data = malloc(sizeof(t_game));
	if (!data)
		error_exit(NULL, "Struct init failed");
	ft_memset(data, 0, sizeof(t_game));
	data->menu_active = 1;
	data->menu_selection = 0;
	data->is_firing = false;
	data->ammo = 5;
	data->win_width = 1280;
	data->win_height = 720;
	data->z_buffer = malloc(sizeof(float) * data->win_width);
	if (!data->z_buffer)
	{
		error_exit(data, "Could not allocate z_buffer");
	}
	return (data);
}

int	main(int argc, char **argv)
{
	t_game	*data;

	data = NULL;
	if (argc != 2)
		error_exit(data, "Usage: ./cub3d <maps/map.cub>");
	data = init_data(argc);
	validate_file(argv[1], data);
	init_player(&data->player, data);
	init_window(data);
	free_resources(data);
	return (0);
}
