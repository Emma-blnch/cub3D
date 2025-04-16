/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblancha <eblancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 08:50:43 by eblancha          #+#    #+#             */
/*   Updated: 2025/04/09 09:40:12 by eblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_ray_struct(t_ray *ray, t_player *player, float angle)
{
	ray->step_x = 0;
	ray->step_y = 0;
	ray->start_x = player->x / TILE_SIZE;
	ray->start_y = player->y / TILE_SIZE;
	ray->map_x = (int)ray->start_x;
	ray->map_y = (int)ray->start_y;
	ray->dir_x = cos(angle);
	ray->dir_y = sin(angle);
	ray->delta_x = fabs(1.0f / ray->dir_x);
	ray->delta_y = fabs(1.0f / ray->dir_y);
	ray->hit = 0;
	ray->side = -1;
}

int	add_shadow(int color, float corrected_dist)
{
	double	shade;
	int		r;
	int		g;
	int		b;

	r = 0;
	g = 0;
	b = 0;
	shade = fmin(1.0, corrected_dist / 900.0);
	r = ((color >> 16) & 0xFF) * (1.0 - shade);
	g = ((color >> 8) & 0xFF) * (1.0 - shade);
	b = (color & 0xFF) * (1.0 - shade);
	color = (r << 16) | (g << 8) | b;
	return (color);
}

void	move_until_wall_is_hit(t_ray *ray, char **map)
{
	while (!ray->hit)
	{
		if (ray->side_x < ray->side_y)
		{
			ray->side_x += ray->delta_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_y += ray->delta_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (is_wall(ray->map_x * TILE_SIZE, ray->map_y * TILE_SIZE, map))
			ray->hit = 1;
	}
}

int	get_tex_x(t_ray *ray, t_img *tex, float wall_hit)
{
	int	tex_x;

	tex_x = (int)(wall_hit * tex->width);
	if (tex_x < 0)
		tex_x = 0;
	if (tex_x >= tex->width)
		tex_x = tex->width - 1;
	if ((ray->side == 0 && ray->dir_x < 0)
		|| (ray->side == 1 && ray->dir_y > 0))
		tex_x = tex->width - tex_x - 1;
	return (tex_x);
}

void	set_values_wall(t_game *game, float *corrected_dist, t_ray *ray)
{
	game->wall.wall_height = (TILE_SIZE * game->win_height) / *corrected_dist;
	game->wall.wall_start = (game->win_height - game->wall.wall_height) / 2;
	if (game->wall.wall_start < 0)
		game->wall.wall_start = 0;
	game->wall.wall_end = game->wall.wall_start + game->wall.wall_height;
	if (game->wall.wall_end > game->win_height)
		game->wall.wall_end = game->win_height;
	game->wall.tex_x = get_tex_x(ray, game->wall.tex, game->wall.wall_hit);
	game->wall.step = 1.0 * game->wall.tex->height / game->wall.wall_height;
	game->wall.tex_pos = (game->wall.wall_start
			- game->win_height / 2 + game->wall.wall_height / 2)
		* game->wall.step;
}
