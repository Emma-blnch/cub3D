/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite_loop.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 09:21:15 by eblancha          #+#    #+#             */
/*   Updated: 2025/04/09 09:29:39 by eblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	sprite_position_from_player(t_game *game,
		float *transform_x, float *transform_y, int *i)
{
	int		sprite_x;
	int		sprite_y;
	float	inv_det;
	float	perp_x;
	float	perp_y;

	sprite_x = game->sprites[*i].x - game->player.x;
	sprite_y = game->sprites[*i].y - game->player.y;
	perp_x = -sin(game->player.angle) * 0.66f;
	perp_y = cos(game->player.angle) * 0.66f;
	inv_det = 1.0f / (perp_x * sin(game->player.angle)
			- cos(game->player.angle) * perp_y);
	*transform_x = inv_det * (sin(game->player.angle)
			* sprite_x - cos(game->player.angle) * sprite_y);
	*transform_y = inv_det * (-perp_y * sprite_x + perp_x * sprite_y);
}

static void	set_draw_sprite_values(t_game *game, t_draw_sprite *sprite)
{
	sprite->screen_x = (int)((game->win_width / 2)
			* (1 + sprite->transform_x / sprite->transform_y));
	sprite->height = (int)(game->win_height / sprite->transform_y * TILE_SIZE);
	sprite->width = (int)(game->win_height / sprite->transform_y * TILE_SIZE);
	sprite->draw_start_y = -sprite->height / 2 + game->win_height / 2;
	if (sprite->draw_start_y < 0)
		sprite->draw_start_y = 0;
	sprite->draw_end_y = sprite->height / 2 + game->win_height / 2;
	if (sprite->draw_end_y >= game->win_height)
		sprite->draw_end_y = game->win_height - 1;
	sprite->draw_start_x = -sprite->width / 2 + sprite->screen_x;
	if (sprite->draw_start_x < 0)
		sprite->draw_start_x = 0;
	sprite->draw_end_x = sprite->width / 2 + sprite->screen_x;
	if (sprite->draw_end_x >= game->win_width)
		sprite->draw_end_x = game->win_width - 1;
	sprite->column = sprite->draw_start_x;
}

static void	put_pixel_in_column(t_game *game, t_draw_sprite *sprite,
		t_sprite_column *vars, int *i)
{
	vars->d = (vars->y * 256) - (game->win_height * 128)
		+ (sprite->height * 128);
	vars->tex_y = ((vars->d * game->sprites[*i].image.height)
			/ sprite->height) / 256;
	vars->color = *(unsigned int *)(game->sprites[*i].image.addr
			+ (vars->tex_y * game->sprites[*i].image.line_length
				+ vars->tex_x * (game->sprites[*i].image.bpp / 8)));
	if ((vars->color & 0x00FFFFFF) != 0)
		put_pixel_to_img(&game->mlx, sprite->column, vars->y, vars->color);
}

static void	loop_through_sprite_columns(t_game *game,
		t_draw_sprite *sprite, int *i)
{
	t_sprite_column	vars;

	init_sprite_column_vars(&vars);
	while (sprite->column < sprite->draw_end_x)
	{
		vars.tex_x = (int)(256 * (sprite->column
					- (-sprite->width / 2 + sprite->screen_x))
				* game->sprites[*i].image.width / sprite->width) / 256;
		if (sprite->transform_y > 0 && sprite->column > 0
			&& sprite->column < game->win_width
			&& sprite->transform_y < game->z_buffer[sprite->column])
		{
			vars.y = sprite->draw_start_y;
			while (vars.y < sprite->draw_end_y)
			{
				put_pixel_in_column(game, sprite, &vars, i);
				vars.y++;
			}
		}
		sprite->column++;
	}
}

void	draw_sprite_loop(t_game *game)
{
	int				i;
	t_draw_sprite	sprite;

	init_draw_sprite_struct(&sprite);
	i = 0;
	while (i < game->sprites_count)
	{
		sprite_position_from_player(game, &sprite.transform_x,
			&sprite.transform_y, &i);
		if (sprite.transform_y <= 0)
		{
			i++;
			continue ;
		}
		set_draw_sprite_values(game, &sprite);
		loop_through_sprite_columns(game, &sprite, &i);
		i++;
	}
}
