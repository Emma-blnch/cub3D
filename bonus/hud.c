/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblancha <eblancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 13:05:00 by eblancha          #+#    #+#             */
/*   Updated: 2025/04/08 10:23:10 by eblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	draw_menu(t_game *game)
{
	if (game->hud.menu_play && game->hud.menu_exit)
	{
		if (game->menu_selection == 1)
		{
			mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win_ptr,
				game->hud.menu_exit, 0, 0);
		}
		else
		{
			mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win_ptr,
				game->hud.menu_play, 0, 0);
		}
	}
	return (0);
}

void	draw_sprite_to_img(t_mlx *dst, t_img *sprite,
			int x_offset, int y_offset)
{
	int		x;
	int		y;
	int		color;
	char	*pixel;

	y = 0;
	while (y < sprite->height)
	{
		x = 0;
		while (x < sprite->width)
		{
			pixel = sprite->addr
				+ (y * sprite->line_length + x * (sprite->bpp / 8));
			color = *(unsigned int *)pixel;
			if ((color & 0x00FFFFFF) != 0)
				put_pixel_to_img(dst, x + x_offset, y + y_offset, color);
			x++;
		}
		y++;
	}
}

void	draw_ammo(t_game *game)
{
	int	i;
	int	spacing;
	int	x_start;
	int	y;
	int	x;

	i = 0;
	spacing = 7;
	x_start = 20;
	y = game->win_height - game->hud.ammo.height - 20;
	while (i < game->ammo)
	{
		x = x_start + i * (game->hud.ammo.width + spacing);
		draw_sprite_to_img(&game->mlx, &game->hud.ammo, x, y);
		i++;
	}
}

void	draw_gun(t_game *game)
{
	int	x;
	int	y;

	x = (game->win_width - game->hud.gun.width) / 2;
	y = game->win_height - game->hud.gun.height;
	if (game->is_firing && game->fire_timer > 0)
	{
		draw_sprite_to_img(&game->mlx, &game->hud.gun_shot, x, y);
		game->fire_timer--;
	}
	else
	{
		draw_sprite_to_img(&game->mlx, &game->hud.gun, x, y);
		game->is_firing = false;
	}
}
