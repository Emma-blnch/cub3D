/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_and_set_textures.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblancha <eblancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 09:32:44 by eblancha          #+#    #+#             */
/*   Updated: 2025/04/09 11:21:42 by eblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	load_texture(t_game *game, t_img *tex, char *path)
{
	tex->img = mlx_xpm_file_to_image(game->mlx.mlx_ptr,
			path, &tex->width, &tex->height);
	if (!tex->img)
		error_exit(game, "Failed to load texture");
	if (tex->width > MAX_TEX_WIDTH || tex->height > MAX_TEX_HEIGHT)
		error_exit(game, "Texture resolution too high");
	tex->addr = mlx_get_data_addr(tex->img, &tex->bpp,
			&tex->line_length, &tex->endian);
}

static void	load_sprites(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->sprites_count)
	{
		if (game->sprites[i].path)
		{
			game->sprites[i].image.img
				= mlx_xpm_file_to_image(game->mlx.mlx_ptr,
					game->sprites[i].path, &game->sprites[i].image.width,
					&game->sprites[i].image.height);
			if (!game->sprites[i].image.img)
				error_exit(game, "Failed to load sprite texture");
			if (game->sprites->image.width > MAX_TEX_WIDTH
				|| game->sprites->image.height > MAX_TEX_HEIGHT)
				error_exit(game, "Sprite resolution too high");
			game->sprites[i].image.addr
				= mlx_get_data_addr(game->sprites[i].image.img,
					&game->sprites[i].image.bpp,
					&game->sprites[i].image.line_length,
					&game->sprites[i].image.endian);
		}
		i++;
	}
}

void	load_textures(t_game *game)
{
	load_texture(game, &game->tex.no, game->config.no_path);
	load_texture(game, &game->tex.so, game->config.so_path);
	load_texture(game, &game->tex.ea, game->config.ea_path);
	load_texture(game, &game->tex.we, game->config.we_path);
	load_texture(game, &game->tex.door, game->config.door_path);
	load_sprites(game);
}

void	load_hud(t_game *game)
{
	game->hud.gun.img = mlx_xpm_file_to_image(game->mlx.mlx_ptr,
			"./textures/hud/gun2.xpm",
			&game->hud.gun.width, &game->hud.gun.height);
	if (!game->hud.gun.img)
		error_exit(game, "Failed to load gun sprite");
	game->hud.gun.addr = mlx_get_data_addr(game->hud.gun.img,
			&game->hud.gun.bpp, &game->hud.gun.line_length,
			&game->hud.gun.endian);
	game->hud.gun_shot.img = mlx_xpm_file_to_image(game->mlx.mlx_ptr,
			"./textures/hud/gun2-shot.xpm",
			&game->hud.gun_shot.width, &game->hud.gun_shot.height);
	if (!game->hud.gun_shot.img)
		error_exit(game, "Failed to load gun shot sprite");
	game->hud.gun_shot.addr = mlx_get_data_addr(game->hud.gun_shot.img,
			&game->hud.gun_shot.bpp, &game->hud.gun_shot.line_length,
			&game->hud.gun_shot.endian);
	game->hud.ammo.img = mlx_xpm_file_to_image(game->mlx.mlx_ptr,
			"./textures/hud/bullet32.xpm",
			&game->hud.ammo.width, &game->hud.ammo.height);
	if (!game->hud.ammo.img)
		error_exit(game, "Failed to load ammo sprite");
	game->hud.ammo.addr = mlx_get_data_addr(game->hud.ammo.img,
			&game->hud.ammo.bpp, &game->hud.ammo.line_length,
			&game->hud.ammo.endian);
}

t_img	*set_textures(t_ray *ray, t_game *game)
{
	t_img	*tex;
	char	c;

	c = game->config.map[ray->map_y][ray->map_x];
	if (c == '3')
		return (&game->tex.door);
	if (ray->side == 0)
	{
		if (ray->dir_x > 0)
			tex = &game->tex.ea;
		else
			tex = &game->tex.we;
	}
	else
	{
		if (ray->dir_y > 0)
			tex = &game->tex.so;
		else
			tex = &game->tex.no;
	}
	return (tex);
}
