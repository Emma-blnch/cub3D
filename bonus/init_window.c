/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblancha <eblancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 13:19:57 by ema_blnch         #+#    #+#             */
/*   Updated: 2025/04/08 17:06:49 by eblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	load_menu(t_game *game)
{
	game->hud.menu_play = mlx_xpm_file_to_image(game->mlx.mlx_ptr,
			"./textures/hud/menu_play.xpm",
			&game->hud.menu_play_w, &game->hud.menu_play_h);
	if (!game->hud.menu_play)
		error_exit(game, "Failed to load menu_play background");
	game->hud.menu_exit = mlx_xpm_file_to_image(game->mlx.mlx_ptr,
			"./textures/hud/menu_exit.xpm",
			&game->hud.menu_exit_w, &game->hud.menu_exit_h);
	if (!game->hud.menu_exit)
		error_exit(game, "Failed to load menu_exit background");
}

void	init_window(t_game *game)
{
	game->mlx.mlx_ptr = mlx_init();
	if (!game->mlx.mlx_ptr)
		error_exit(game, "Failed to initiate Minilibx");
	game->mlx.win_ptr = mlx_new_window(game->mlx.mlx_ptr,
			game->win_width, game->win_height, "Cub3D");
	if (!game->mlx.win_ptr)
		error_exit(game, "Failed to create window");
	game->mlx.img = mlx_new_image(game->mlx.mlx_ptr,
			game->win_width, game->win_height);
	game->mlx.addr = mlx_get_data_addr(game->mlx.img,
			&game->mlx.bpp, &game->mlx.line_length, &game->mlx.endian);
	mlx_mouse_hide(game->mlx.mlx_ptr, game->mlx.win_ptr);
	mlx_mouse_move(game->mlx.mlx_ptr, game->mlx.win_ptr,
		game->win_width / 2, game->win_height / 2);
	load_menu(game);
	load_hud(game);
	load_textures(game);
	mlx_hook(game->mlx.win_ptr, 17, 0, close_window, game);
	mlx_hook(game->mlx.win_ptr, 2, 1L << 0, key_press_linux, game);
	mlx_hook(game->mlx.win_ptr, 3, 1L << 1, key_release_linux, game);
	mlx_mouse_hook(game->mlx.win_ptr, mouse_click, game);
	mlx_hook(game->mlx.win_ptr, 6, 1L << 6, mouse_move, game);
	mlx_loop_hook(game->mlx.mlx_ptr, render, game);
	mlx_loop(game->mlx.mlx_ptr);
}
