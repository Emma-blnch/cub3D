/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblancha <eblancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 12:56:12 by ema_blnch         #+#    #+#             */
/*   Updated: 2025/04/09 09:30:43 by eblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	if (data->hud.gun.img)
		mlx_destroy_image(data->mlx.mlx_ptr, data->hud.gun.img);
	if (data->hud.menu_play)
		mlx_destroy_image(data->mlx.mlx_ptr, data->hud.menu_play);
	if (data->hud.menu_exit)
		mlx_destroy_image(data->mlx.mlx_ptr, data->hud.menu_exit);
	if (data->tex.no.img)
		mlx_destroy_image(data->mlx.mlx_ptr, data->tex.no.img);
	if (data->tex.so.img)
		mlx_destroy_image(data->mlx.mlx_ptr, data->tex.so.img);
	if (data->tex.ea.img)
		mlx_destroy_image(data->mlx.mlx_ptr, data->tex.ea.img);
	if (data->tex.we.img)
		mlx_destroy_image(data->mlx.mlx_ptr, data->tex.we.img);
	if (data->tex.door.img)
		mlx_destroy_image(data->mlx.mlx_ptr, data->tex.door.img);
	if (data->hud.gun_shot.img)
		mlx_destroy_image(data->mlx.mlx_ptr, data->hud.gun_shot.img);
	if (data->hud.ammo.img)
		mlx_destroy_image(data->mlx.mlx_ptr, data->hud.ammo.img);
}

void	free_sprites(t_game *data)
{
	int	i;

	i = 0;
	while (i < data->sprites_count)
	{
		if (data->sprites[i].image.img)
			mlx_destroy_image(data->mlx.mlx_ptr, data->sprites[i].image.img);
		free(data->sprites[i].path);
		i++;
	}	
	free(data->sprites);
}

void	free_resources(t_game *data)
{
	if (!data)
		return ;
	free(data->config.no_path);
	free(data->config.so_path);
	free(data->config.we_path);
	free(data->config.ea_path);
	free(data->config.sp_path);
	free(data->config.door_path);
	free_map(data->config.map);
	free_lines(data->lines);
	free_textures(data);
	if (data->sprites)
		free_sprites(data);
	if (data->z_buffer)
		free(data->z_buffer);
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
