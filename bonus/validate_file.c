/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblancha <eblancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 13:36:11 by ema_blnch         #+#    #+#             */
/*   Updated: 2025/04/09 09:15:58 by eblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_filename(t_game *data, char *filename)
{
	int		i;
	char	*real_filename;

	if (!filename || !*filename)
	{
		error_exit(data, "Empty file name");
	}
	real_filename = filename;
	i = 0;
	while (filename[i])
	{
		if (filename[i] == '/')
			real_filename = &filename[i + 1];
		i++;
	}
	if (real_filename[0] == '.')
		error_exit(data, "Cannot open hidden files");
	i = 0;
	while (filename[i])
		i++;
	i--;
	while (i >= 0 && filename[i] != '.')
		i--;
	if (i < 0 || ft_strcmp(filename + i, ".cub") != 0)
		error_exit(data, "File must have <.cub> extension");
}

char	**read_all_lines(char *filename, t_game *data)
{
	int		fd;
	char	*line;
	char	**lines;
	int		i;

	if (open(filename, __O_DIRECTORY) >= 0)
		error_exit(data, "Cannot open a directory");
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		error_exit(data, "Cannot read file");
	lines = malloc(sizeof(char *) * (MAX_LINES + 1));
	if (!lines)
		error_exit(data, "Malloc failed");
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (i >= MAX_LINES)
			error_exit(data, "File too big");
		lines[i++] = line;
		line = get_next_line(fd);
	}
	lines[i] = NULL;
	close(fd);
	return (lines);
}

void	validate_file(char *filename, t_game *data)
{
	check_filename(data, filename);
	data->lines = read_all_lines(filename, data);
	if (!data->lines || count_lines(data->lines) < 9)
		error_exit(data, "File too short");
	check_file_config(data, data->lines);
	check_map(data, data->lines);
	store_data(data, data->lines);
}
