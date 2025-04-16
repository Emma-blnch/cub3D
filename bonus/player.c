/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblancha <eblancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 12:25:36 by eblancha          #+#    #+#             */
/*   Updated: 2025/04/14 08:43:04 by eblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_player(t_player *player, t_game *game)
{
	player->x = (game->config.player_x + 0.5) * TILE_SIZE;
	player->y = (game->config.player_y + 0.5) * TILE_SIZE;
	if (game->config.player_dir == 'N')
		player->angle = 3 * PI / 2;
	else if (game->config.player_dir == 'S')
		player->angle = PI / 2;
	else if (game->config.player_dir == 'E')
		player->angle = 0;
	else if (game->config.player_dir == 'W')
		player->angle = PI;
	player->key_down = false;
	player->key_left = false;
	player->key_rigth = false;
	player->key_up = false;
	player->left_rotate = false;
	player->right_rotate = false;
}

static void	rotation(t_player *player)
{
	float	angle_speed;

	angle_speed = 0.04f;
	if (player->left_rotate)
		player->angle -= angle_speed;
	if (player->right_rotate)
		player->angle += angle_speed;
	if (player->angle > 2 * PI)
		player->angle -= 2 * PI;
	if (player->angle < 0)
		player->angle += 2 * PI;
}

static void	perpendicular_moves(t_player *player, float *new_x, float *new_y)
{
	int	speed;

	speed = 3;
	if (player->key_up)
	{
		*new_x += cos(player->angle) * speed;
		*new_y += sin(player->angle) * speed;
	}
	if (player->key_down)
	{
		*new_x -= cos(player->angle) * speed;
		*new_y -= sin(player->angle) * speed;
	}
	if (player->key_left)
	{
		*new_y -= cos(player->angle) * speed;
		*new_x += sin(player->angle) * speed;
	}
	if (player->key_rigth)
	{
		*new_y += cos(player->angle) * speed;
		*new_x -= sin(player->angle) * speed;
	}
}

void	move_player(t_player *player, t_game *game)
{
	float	new_x;
	float	new_y;

	new_x = player->x;
	new_y = player->y;
	rotation(player);
	perpendicular_moves(player, &new_x, &new_y);
	if (!is_wall(new_x, player->y, game->config.map)
		&& !is_sprite(new_x, player->y, game->config.map))
		player->x = new_x;
	if (!is_wall(player->x, new_y, game->config.map)
		&& !is_sprite(player->x, new_y, game->config.map))
		player->y = new_y;
}
