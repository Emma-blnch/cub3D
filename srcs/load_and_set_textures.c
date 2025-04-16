/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_and_set_textures.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblancha <eblancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 10:37:10 by eblancha          #+#    #+#             */
/*   Updated: 2025/04/09 11:11:46 by eblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_img	*set_textures(t_ray *ray, t_game *game)
{
	t_img	*tex;

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

void	load_textures(t_game *game)
{
	load_texture(game, &game->tex.no, game->config.no_path);
	load_texture(game, &game->tex.so, game->config.so_path);
	load_texture(game, &game->tex.ea, game->config.ea_path);
	load_texture(game, &game->tex.we, game->config.we_path);
}
