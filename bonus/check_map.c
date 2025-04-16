/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblancha <eblancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 11:10:27 by ema_blnch         #+#    #+#             */
/*   Updated: 2025/04/09 09:23:26 by eblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	check_map_characters(char **lines, int start, t_game *data)
{
	int	i;
	int	j;
	int	player_count;

	player_count = 0;
	i = start;
	while (lines[i])
	{
		j = 0;
		while (lines[i][j])
		{
			if (!ft_strchr("0123NSEW \n", lines[i][j]))
				error_exit(data, "Invalid character in map");
			if (ft_strchr("NSEW", lines[i][j]))
				player_count++;
			j++;
		}
		i++;
	}
	if (player_count != 1)
		error_exit(data, "Map must contain exactly one player");
}

int	find_map_start_index(char **lines)
{
	int	i;

	i = 0;
	while (lines[i])
	{
		if (is_valid_map_line(lines[i]) && has_wall_start(lines[i]))
			return (i);
		i++;
	}
	return (-1);
}

void	check_map(t_game *data, char **lines)
{
	int	start;

	start = find_map_start_index(lines);
	check_map_characters(lines, start, data);
	check_map_is_closed(lines, start, data);
}
