/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblancha <eblancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 12:34:50 by ema_blnch         #+#    #+#             */
/*   Updated: 2025/04/09 09:39:07 by eblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_valid_map_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\n')
			return (1);
		i++;
	}
	return (0);
}

int	has_wall_start(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '1' || line[i] == '0')
			return (1);
		if (line[i] != ' ')
			return (0);
		i++;
	}
	return (0);
}

bool	is_wall(float px, float py, char **map)
{
	int		x;
	int		y;

	x = px / TILE_SIZE;
	y = py / TILE_SIZE;
	if (y < 0 || x < 0 || map[y] == NULL || x >= (int)ft_strlen(map[y]))
		return (true);
	if (map[y][x] == '1' || map[y][x] == '3')
		return (true);
	return (false);
}

bool	is_sprite(float px, float py, char **map)
{
	int	x;
	int	y;

	x = px / TILE_SIZE;
	y = py / TILE_SIZE;
	if (y < 0 || x < 0 || map[y] == NULL || x >= (int)ft_strlen(map[y]))
		return (true);
	if (map[y][x] == '2')
		return (true);
	return (false);
}
