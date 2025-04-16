/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblancha <eblancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 11:46:50 by ema_blnch         #+#    #+#             */
/*   Updated: 2025/04/09 08:54:01 by eblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_texture_path(char *line, t_game *data, char *id)
{
	char	*path;
	int		fd;

	path = ft_strchr(line, ' ');
	if (!path || !*(path + 1))
	{
		ft_printf("Missing path for %s\n", id);
		error_exit(data, NULL);
	}
	path++;
	while (*path == ' ')
		path++;
	if (!*path)
	{
		ft_printf("Empty path for %s\n", id);
		error_exit(data, NULL);
	}
	path[ft_strlen(path) - 1] = '\0';
	fd = open(path, O_RDONLY);
	if (fd < 0)
		error_exit(data, "Texture path is invalid");
	close(fd);
}

static int	is_valid_rgb_value(char *str)
{
	int	val;

	if (!str || !*str)
		return (0);
	val = ft_atoi(str);
	if (val < 0 || val > 255)
		return (0);
	return (1);
}

void	check_color_format(char *line, t_game *data, char id)
{
	char	**split;
	int		i;

	line += 2;
	split = ft_split(line, ',');
	if (!split)
		error_exit(data, "Failed to split color line");
	i = 0;
	while (split[i])
		i++;
	if (i != 3 || !is_valid_rgb_value(split[0])
		|| !is_valid_rgb_value(split[1])
		|| !is_valid_rgb_value(split[2]))
	{
		free_split(split);
		if (id == 'F')
			error_exit(data, "Invalid floor color");
		else
			error_exit(data, "Invalid ceiling color");
	}
	free_split(split);
}

void	check_duplicate(int *flag, t_game *data)
{
	if (*flag)
	{
		error_exit(data, "Duplicate in file");
	}
	*flag = 1;
}
