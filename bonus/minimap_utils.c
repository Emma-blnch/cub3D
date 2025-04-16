/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblancha <eblancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 09:31:55 by eblancha          #+#    #+#             */
/*   Updated: 2025/04/09 09:36:57 by eblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	set_color(char **map, int y, int x)
{
	int		color;

	color = -1;
	if (map[y][x] == '1')
		color = 0xe82380;
	else if (map[y][x] == '0' || map[y][x] == '2' || map[y][x] == '4')
		color = 0xFFFFFF;
	else if (map[y][x] == '3')
		color = 0xff8916;
	else if (ft_strchr("NSEW", map[y][x]))
		color = 0xFFFFFF;
	return (color);
}

int	get_mini_tile_size(t_game *game)
{
	int	max_cols;
	int	nb_rows;
	int	tile;
	int	len;
	int	height_tile;

	max_cols = 0;
	nb_rows = 0;
	while (game->config.map[nb_rows])
	{
		len = ft_strlen(game->config.map[nb_rows]);
		if (len > max_cols)
			max_cols = len;
		nb_rows++;
	}
	tile = (int)(game->win_width * 0.2 / max_cols);
	height_tile = (int)(game->win_height * 0.2 / nb_rows);
	if (height_tile < tile)
		tile = height_tile;
	if (tile < 1)
		tile = 1;
	return (tile);
}
