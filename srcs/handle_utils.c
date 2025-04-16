/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblancha <eblancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 09:55:47 by eblancha          #+#    #+#             */
/*   Updated: 2025/04/06 17:24:22 by eblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	close_window(t_game *data)
{
	error_exit(data, NULL);
	return (0);
}

int	key_press_linux(int keycode, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	return (key_press(keycode, game));
}

int	key_release_linux(int keycode, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	return (key_release(keycode, game));
}
