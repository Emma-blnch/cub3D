/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_config.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblancha <eblancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 15:08:25 by ema_blnch         #+#    #+#             */
/*   Updated: 2025/04/09 08:54:39 by eblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	handle_texture_config(char *line, t_game *data, t_check *check)
{
	if (ft_strncmp(line, "NO ", 3) == 0)
	{
		check_duplicate(&check->found_no, data);
		check_texture_path(line, data, "NO");
	}
	else if (ft_strncmp(line, "SO ", 3) == 0)
	{
		check_duplicate(&check->found_so, data);
		check_texture_path(line, data, "SO");
	}
	else if (ft_strncmp(line, "WE ", 3) == 0)
	{
		check_duplicate(&check->found_we, data);
		check_texture_path(line, data, "WE");
	}
	else if (ft_strncmp(line, "EA ", 3) == 0)
	{
		check_duplicate(&check->found_ea, data);
		check_texture_path(line, data, "EA");
	}
	else
		error_exit(data, "Unknown texture identifier");
}

static void	handle_color_config(char *line, t_game *data, t_check *check)
{
	if (ft_strncmp(line, "F ", 2) == 0)
	{
		check_duplicate(&check->found_f, data);
		check_color_format(line, data, 'F');
	}
	else if (ft_strncmp(line, "C ", 2) == 0)
	{
		check_duplicate(&check->found_c, data);
		check_color_format(line, data, 'C');
	}
	else
		error_exit(data, "Unknown color identifier");
}

static void	handle_config_line(char *line, t_game *data, t_check *check)
{
	if (ft_strncmp(line, "NO ", 3) == 0 || ft_strncmp(line, "SO ", 3) == 0
		|| ft_strncmp(line, "WE ", 3) == 0 || ft_strncmp(line, "EA ", 3) == 0)
		handle_texture_config(line, data, check);
	else if (ft_strncmp(line, "F ", 2) == 0 || ft_strncmp(line, "C ", 2) == 0)
		handle_color_config(line, data, check);
	else
		error_exit(data, "Unknown identifier");
}

void	check_file_config(t_game *data, char **lines)
{
	t_check		check;
	int			i;

	i = 0;
	ft_memset(&check, 0, sizeof(t_check));
	while (lines[i])
	{
		if (ft_str_is_whitespace(lines[i]))
		{
			i++;
			continue ;
		}
		if (ft_strchr(" 01", lines[i][0]))
			break ;
		handle_config_line(lines[i], data, &check);
		i++;
	}
	if (!check.found_no || !check.found_so || !check.found_we
		|| !check.found_ea || !check.found_f || !check.found_c)
	{
		free(lines);
		error_exit(data, "Missing configuration element");
	}
}
