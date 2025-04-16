/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblancha <eblancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 12:56:12 by ema_blnch         #+#    #+#             */
/*   Updated: 2025/04/09 09:13:52 by eblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	error_exit(t_game *data, char *message)
{
	if (message)
	{
		printf(R"Error\n"RESET);
		ft_printf(R"%s\n"RESET, message);
	}
	free_resources(data);
	exit(1);
}

void	free_lines(char **lines)
{
	int	i;

	i = 0;
	if (!lines)
		return ;
	while (lines[i])
		free(lines[i++]);
	free(lines);
}

void	free_map(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	free_textures(t_game *data)
{
	if (data->tex.no.img)
		mlx_destroy_image(data->mlx.mlx_ptr, data->tex.no.img);
	if (data->tex.so.img)
		mlx_destroy_image(data->mlx.mlx_ptr, data->tex.so.img);
	if (data->tex.ea.img)
		mlx_destroy_image(data->mlx.mlx_ptr, data->tex.ea.img);
	if (data->tex.we.img)
		mlx_destroy_image(data->mlx.mlx_ptr, data->tex.we.img);
}

void	free_resources(t_game *data)
{
	if (!data)
		return ;
	free(data->config.no_path);
	free(data->config.so_path);
	free(data->config.we_path);
	free(data->config.ea_path);
	free_map(data->config.map);
	if (data->lines)
		free_lines(data->lines);
	free_textures(data);
	if (data->mlx.img)
		mlx_destroy_image(data->mlx.mlx_ptr, data->mlx.img);
	if (data->mlx.win_ptr)
		mlx_destroy_window(data->mlx.mlx_ptr, data->mlx.win_ptr);
	if (data->mlx.mlx_ptr)
	{
		mlx_destroy_display(data->mlx.mlx_ptr);
		free(data->mlx.mlx_ptr);
	}
	free(data);
}
