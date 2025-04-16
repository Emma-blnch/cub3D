/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblancha <eblancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 13:20:31 by ema_blnch         #+#    #+#             */
/*   Updated: 2025/04/14 08:42:33 by eblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	handle_menu(int keycode, t_game *game)
{
	game->is_firing = false;
	if (keycode == UP || keycode == W)
		game->menu_selection = (game->menu_selection + 1) % 2;
	else if (keycode == DOWN || keycode == S)
		game->menu_selection = (game->menu_selection + 1) % 2;
	else if (keycode == E)
	{
		if (game->menu_selection == 0)
			game->menu_active = 0;
		else
			error_exit(game, NULL);
	}
	else if (keycode == ESC)
		error_exit(game, NULL);
	return (0);
}

int	key_press(int keycode, t_game *game)
{
	if (game->menu_active)
		return (handle_menu(keycode, game));
	if (keycode == W)
		game->player.key_up = true;
	if (keycode == S)
		game->player.key_down = true;
	if (keycode == D)
		game->player.key_rigth = true;
	if (keycode == A)
		game->player.key_left = true;
	if (keycode == LEFT)
		game->player.left_rotate = true;
	if (keycode == RIGHT)
		game->player.right_rotate = true;
	if (keycode == ESC)
		error_exit(game, NULL);
	if (keycode == 114)
	{
		if (game->ammo < 5)
			game->ammo = 5;
	}
	if (keycode == 32)
		open_and_close_doors(game);
	return (0);
}

int	key_release(int keycode, t_game *game)
{
	t_player	*player;

	player = &game->player;
	if (game->menu_active)
		return (0);
	if (keycode == W)
		player->key_up = false;
	if (keycode == S)
		player->key_down = false;
	if (keycode == D)
		player->key_rigth = false;
	if (keycode == A)
		player->key_left = false;
	if (keycode == LEFT)
		player->left_rotate = false;
	if (keycode == RIGHT)
		player->right_rotate = false;
	return (0);
}

int	mouse_click(int button, int x, int y, void *param)
{
	t_game			*game;
	unsigned long	now;

	(void)x;
	(void)y;
	game = (t_game *)param;
	now = get_time_ms();
	if (button == 1 && game->ammo > 0)
	{
		if (now - game->last_shot_time >= 700)
		{
			game->is_firing = true;
			game->fire_timer = 6;
			game->ammo--;
			game->last_shot_time = now;
		}
	}
	return (0);
}

int	mouse_move(int x, int y, t_game *game)
{
	float	angle_speed;
	int		center_x;
	int		delta;

	center_x = game->win_width / 2;
	delta = x - center_x;
	(void)y;
	if (delta != 0)
	{
		angle_speed = 0.0008f;
		game->player.angle += delta * angle_speed;
		if (game->player.angle > 2 * PI)
			game->player.angle -= 2 * PI;
		if (game->player.angle < 0)
			game->player.angle += 2 * PI;
	}
	mlx_mouse_move(game->mlx.mlx_ptr, game->mlx.win_ptr,
		center_x, game->win_height / 2);
	return (0);
}
