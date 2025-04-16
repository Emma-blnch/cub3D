/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblancha <eblancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 12:12:35 by ema_blnch         #+#    #+#             */
/*   Updated: 2025/04/08 17:06:51 by eblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	encode_rgb(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | b);
}

static void	parse_single_color(char *line, t_game *data, char type)
{
	char	**split;
	int		r;
	int		g;
	int		b;

	line += 2;
	while (*line == ' ')
		line++;
	split = ft_split(line, ',');
	if (!split || !split[0] || !split[1] || !split[2] || split[3])
		error_exit(data, "Invalid RGB format");
	r = ft_atoi(split[0]);
	g = ft_atoi(split[1]);
	b = ft_atoi(split[2]);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		error_exit(data, "RGB value out of range");
	if (type == 'F')
		data->config.floor_color = encode_rgb(r, g, b);
	else if (type == 'C')
		data->config.ceiling_color = encode_rgb(r, g, b);
	else
		error_exit(data, " Unknown color type");
	free_split(split);
}

void	parse_colors(t_game *data, char **lines)
{
	int	i;

	i = 0;
	while (lines[i])
	{
		if (lines[i][0] == '\n' || lines[i][0] == '\0')
		{
			i++;
			continue ;
		}
		if (ft_strchr("01 ", lines[i][0]))
			break ;
		if (ft_strncmp(lines[i], "F ", 2) == 0)
			parse_single_color(lines[i], data, 'F');
		else if (ft_strncmp(lines[i], "C ", 2) == 0)
			parse_single_color(lines[i], data, 'C');
		i++;
	}
}
