/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblancha <eblancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 12:00:43 by ema_blnch         #+#    #+#             */
/*   Updated: 2025/04/09 09:45:20 by eblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	store_player_position(t_game *data)
{
	int		y;
	int		x;
	char	**map;

	map = data->config.map;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (ft_strchr("NSEW", map[y][x]))
			{
				if (data->config.player_dir)
					error_exit(data, "Multiple player positions found");
				data->config.player_x = x;
				data->config.player_y = y;
				data->config.player_dir = map[y][x];
				return ;
			}
			x++;
		}
		y++;
	}
	error_exit(data, "No player position found");
}

void	store_map(t_game *data, char **lines)
{
	int		start;
	int		map_lines;
	int		i;
	int		j;

	start = find_map_start_index(lines);
	map_lines = 0;
	i = start;
	while (lines[i])
	{
		if (!ft_str_is_whitespace(lines[i++]))
			map_lines++;
	}
	data->config.map = malloc(sizeof(char *) * (map_lines + 1));
	if (!data->config.map)
		error_exit(data, "Failed to allocate memory for map");
	i = start;
	j = 0;
	while (lines[i])
	{
		if (!ft_str_is_whitespace(lines[i]))
			data->config.map[j++] = ft_strdup(lines[i]);
		i++;
	}
	data->config.map[j] = NULL;
}

static t_sprite	*init_sprites(t_game *data)
{
	int			x;
	int			y;
	int			sprites_count;
	t_sprite	*sprites;

	y = 0;
	sprites_count = 0;
	while (data->config.map[y])
	{
		x = 0;
		while (x < (int)ft_strlen(data->config.map[y]))
		{
			if (!ft_strncmp("2", data->config.map[y] + x, 1))
				sprites_count++;
			x++;
		}
		y++;
	}
	sprites = malloc(sizeof(t_sprite) * sprites_count);
	if (!sprites)
	{
		error_exit(data, "Failed to allocate memory for sprites");
	}
	return (sprites);
}

void	store_sprites(t_game *data)
{
	int	y;
	int	x;
	int	sprite_nb;

	y = 0;
	sprite_nb = 0;
	data->sprites = init_sprites(data);
	while (data->config.map[y])
	{
		x = 0;
		while (x < (int)ft_strlen(data->config.map[y]))
		{
			if (data->config.map[y][x] == '2')
			{
				data->sprites[sprite_nb].x = (x + 0.5) * TILE_SIZE;
				data->sprites[sprite_nb].y = (y + 0.5) * TILE_SIZE;
				data->sprites[sprite_nb].dist = 0;
				data->sprites[sprite_nb].path = ft_strdup(data->config.sp_path);
				sprite_nb++;
			}
			x++;
		}
		y++;
	}
	data->sprites_count = sprite_nb;
}

void	store_data(t_game *data, char **lines)
{
	parse_textures(data, lines);
	parse_colors(data, lines);
	store_map(data, lines);
	store_player_position(data);
	store_sprites(data);
}
