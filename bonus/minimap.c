/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblancha <eblancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 16:27:23 by ema_blnch         #+#    #+#             */
/*   Updated: 2025/04/08 09:02:28 by eblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_player_minimap(t_game *game)
{
	int	player_x_mini;
	int	player_y_mini;
	int	dx;
	int	dy;
	int	tile_size;

	tile_size = get_mini_tile_size(game);
	player_x_mini = (game->player.x / TILE_SIZE) * tile_size;
	player_y_mini = (game->player.y / TILE_SIZE) * tile_size;
	dy = 0;
	while (dy < tile_size / 2)
	{
		dx = 0;
		while (dx < tile_size / 2)
		{
			put_pixel_to_img(&game->mlx, player_x_mini + dx,
				player_y_mini + dy, 0x0f056b);
			dx++;
		}
		dy++;
	}
}

void	draw_ray_on_minimap(t_game *game, float angle)
{
	float	ray_x;
	float	ray_y;
	float	cos_a;
	float	sin_a;
	int		tile_size;

	ray_x = game->player.x;
	ray_y = game->player.y;
	cos_a = cos(angle);
	sin_a = sin(angle);
	tile_size = get_mini_tile_size(game);
	while (!is_wall(ray_x, ray_y, game->config.map))
	{
		put_pixel_to_img(&game->mlx, (ray_x / TILE_SIZE) * tile_size,
			(ray_y / TILE_SIZE) * tile_size, 0x77b5fe);
		ray_x += cos_a;
		ray_y += sin_a;
	}
}

void	ray_casting_minimap(t_game *game)
{
	float	start_x;
	float	fraction;
	int		i;

	i = 0;
	fraction = PI / 3 / game->win_width;
	start_x = game->player.angle - PI / 6;
	while (i < game->win_width)
	{
		draw_ray_on_minimap(game, start_x);
		start_x += fraction;
		i++;
	}
}

void	draw_square(int x, int y, int color, t_game *game)
{
	int		tile;
	int		dx;
	int		dy;

	tile = get_mini_tile_size(game);
	dy = 0;
	while (dy < tile)
	{
		dx = 0;
		while (dx < tile)
		{
			put_pixel_to_img(&game->mlx, x * tile + dx, y * tile + dy, color);
			dx++;
		}
		dy++;
	}
}

void	draw_minimap(t_game *game)
{
	int		y;
	int		x;
	int		color;

	y = 0;
	while (game->config.map[y])
	{
		x = 0;
		while (x < (int)ft_strlen(game->config.map[y]))
		{
			color = set_color(game->config.map, y, x);
			if (color != -1)
				draw_square(x, y, color, game);
			x++;
		}
		y++;
	}
	draw_player_minimap(game);
	ray_casting_minimap(game);
}
