/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 09:19:20 by eblancha          #+#    #+#             */
/*   Updated: 2025/04/09 09:20:01 by eblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	calculate_sprites_dist(t_game *game)
{
	int		i;
	float	x;
	float	y;

	i = 0;
	x = 0;
	y = 0;
	while (i < game->sprites_count)
	{
		x = game->sprites[i].x - game->player.x;
		y = game->sprites[i].y - game->player.y;
		game->sprites[i].dist = sqrtf(x * x + y * y);
		i++;
	}
}

static void	sort_sprites_dist(t_game *game)
{
	int			i;
	int			j;
	t_sprite	tmp;

	i = 0;
	while (i < game->sprites_count - 1)
	{
		j = 0;
		while (j < game->sprites_count - i - 1)
		{
			if (game->sprites[j].dist < game->sprites[j + 1].dist)
			{
				tmp = game->sprites[j];
				game->sprites[j] = game->sprites[j + 1];
				game->sprites[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	draw_sprites(t_game *game)
{
	calculate_sprites_dist(game);
	sort_sprites_dist(game);
	draw_sprite_loop(game);
}
