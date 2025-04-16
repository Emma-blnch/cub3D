/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblancha <eblancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 08:50:48 by eblancha          #+#    #+#             */
/*   Updated: 2025/04/09 09:41:27 by eblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_wall_column(t_game *game, float *corrected_dist,
	int i, t_ray *ray)
{
	int		tex_y;
	char	*pixel;
	int		color;

	set_values_wall(game, corrected_dist, ray);
	while (game->wall.wall_start < game->wall.wall_end)
	{
		tex_y = (int)game->wall.tex_pos;
		game->wall.tex_pos += game->wall.step;
		if (tex_y < 0)
			tex_y = 0;
		if (tex_y >= game->wall.tex->height)
			tex_y = game->wall.tex ->height - 1;
		pixel = game->wall.tex ->addr
			+ (tex_y * game->wall.tex ->line_length + game->wall.tex_x
				* (game->wall.tex ->bpp / 8));
		color = add_shadow(*(unsigned int *)pixel, *corrected_dist);
		put_pixel_to_img(&game->mlx, i, game->wall.wall_start, color);
		game->wall.wall_start++;
	}
}

static void	calculate_sides_distances(t_ray *ray)
{
	if (ray->dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_x = (ray->start_x - ray->map_x) * ray->delta_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_x = (ray->map_x + 1.0f - ray->start_x) * ray->delta_x;
	}
	if (ray->dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_y = (ray->start_y - ray->map_y) * ray->delta_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_y = (ray->map_y + 1.0f - ray->start_y) * ray->delta_y;
	}
}

void	draw_ray(t_game *game, float angle, int col, float *perp_ray_dist)
{
	t_ray	ray;
	float	dist;

	init_ray_struct(&ray, &game->player, angle);
	calculate_sides_distances(&ray);
	move_until_wall_is_hit(&ray, game->config.map);
	if (ray.side == 0)
		dist = (ray.side_x - ray.delta_x) * TILE_SIZE;
	else
		dist = (ray.side_y - ray.delta_y) * TILE_SIZE;
	*perp_ray_dist = dist * cos(angle - game->player.angle);
	if (*perp_ray_dist < 1.0f)
		*perp_ray_dist = 1.0f;
	game->wall.tex = set_textures(&ray, game);
	if (ray.side == 0)
		game->wall.wall_hit = ray.start_y + dist / TILE_SIZE * ray.dir_y;
	else
		game->wall.wall_hit = ray.start_x + dist / TILE_SIZE * ray.dir_x;
	game->wall.wall_hit -= floor(game->wall.wall_hit);
	draw_wall_column(game, perp_ray_dist, col, &ray);
}

void	ray_casting(t_game *game)
{
	float	start_angle;
	float	fraction;
	float	perp_ray_dist;
	int		i;

	start_angle = game->player.angle - PI / 6;
	fraction = PI / 3 / game->win_width;
	perp_ray_dist = 0;
	i = 0;
	while (i < game->win_width)
	{
		draw_ray(game, start_angle, i, &perp_ray_dist);
		game->z_buffer[i] = perp_ray_dist;
		start_angle += fraction;
		i++;
	}
}
