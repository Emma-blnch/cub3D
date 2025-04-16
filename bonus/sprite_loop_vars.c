/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_loop_vars.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 09:19:36 by eblancha          #+#    #+#             */
/*   Updated: 2025/04/09 09:19:37 by eblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_draw_sprite_struct(t_draw_sprite *sprite)
{
	sprite->transform_x = 0;
	sprite->transform_y = 0;
	sprite->screen_x = 0;
	sprite->height = 0;
	sprite->width = 0;
	sprite->draw_start_x = 0;
	sprite->draw_start_y = 0;
	sprite->draw_end_x = 0;
	sprite->draw_end_y = 0;
	sprite->column = 0;
}

void	init_sprite_column_vars(t_sprite_column	*vars)
{
	vars->y = 0;
	vars->d = 0;
	vars->tex_x = 0;
	vars->tex_y = 0;
	vars->color = 0;
}
