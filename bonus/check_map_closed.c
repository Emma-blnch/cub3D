/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_closed.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblancha <eblancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 11:39:31 by ema_blnch         #+#    #+#             */
/*   Updated: 2025/04/14 08:52:23 by eblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_valid_tile(char c)
{
	return (c == '0' || c == '2' || c == '3'
		|| c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

static int	is_in_bounds(char **map, int i, int j)
{
	return (i >= 0 && map[i] && j >= 0 && j < (int)ft_strlen(map[i]));
}

static bool	is_space(char c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

static int	is_closed_around(char **map, int i, int j)
{
	if (!is_in_bounds(map, i, j) || !is_valid_tile(map[i][j]))
		return (1);
	if (!is_in_bounds(map, i - 1, j) || is_space(map[i - 1][j]))
		return (0);
	if (!is_in_bounds(map, i + 1, j) || is_space(map[i + 1][j]))
		return (0);
	if (!is_in_bounds(map, i, j - 1) || is_space(map[i][j - 1]))
		return (0);
	if (!is_in_bounds(map, i, j + 1) || is_space(map[i][j + 1]))
		return (0);
	return (1);
}

void	check_map_is_closed(char **lines, int start, t_game *data)
{
	int	i;
	int	j;

	i = start;
	while (lines[i])
	{
		j = 0;
		while (lines[i][j])
		{
			if (is_valid_tile(lines[i][j]))
			{
				if (!is_closed_around(lines, i, j))
					error_exit(data, "Map is not closed");
			}
			j++;
		}
		i++;
	}
}
