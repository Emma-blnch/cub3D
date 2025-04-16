/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblancha <eblancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 12:52:09 by ema_blnch         #+#    #+#             */
/*   Updated: 2025/04/09 10:50:51 by eblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "struct.h"
# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"
# include "../libft/printf/ft_printf.h"
# include "../libft/get_next_line/get_next_line.h"

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include <stdbool.h>
# include <sys/time.h>

# define MAX_LINES 1024
# define ESC_KEY 65307
# define TILE_SIZE 64
# define MAX_TEX_WIDTH 1024
# define MAX_TEX_HEIGHT 1024

# define PI 3.14159265359

# define RESET		"\033[0m"
# define R		    "\033[31m"
# define G		    "\033[32m"
# define Y		    "\033[33m"
# define B		    "\033[34m"

// TOUCHES MACOS
# define UP 65362
# define W 119
# define DOWN 65364
# define ESC 65307
# define E 101
# define A 97
# define S 115
# define D 100
# define LEFT 65361
# define RIGHT 65363

// Init
t_game			*init_data(int argc);

// Check file
void			validate_file(char *filename, t_game *data);
char			**read_all_lines(char *filename, t_game *data);
void			check_filename(t_game *data, char *filename);
void			check_file_config(t_game *data, char **lines);
void			check_map(t_game *data, char **lines);
void			check_duplicate(int *flag, t_game *data);
void			check_color_format(char *line, t_game *data, char id);
void			check_texture_path(char *line, t_game *data, char *id);
int				find_map_start_index(char **lines);
void			check_map_is_closed(char **lines, int start, t_game *data);

// Store data
void			store_data(t_game *data, char **lines);
void			parse_textures(t_game *data, char **lines);
void			parse_colors(t_game *data, char **lines);
void			store_player_position(t_game *data);

// Window
void			init_window(t_game *game);
void			draw_floor_and_ceiling(t_game *game);

// Menu
int				draw_menu(t_game *game);

// Hud
void			load_hud(t_game *game);
void			draw_ammo(t_game *game);
void			draw_gun(t_game *game);

// Mini-map
int				render(t_game *game);
int				set_color(char **map, int y, int x);
int				get_mini_tile_size(t_game *game);
void			draw_minimap(t_game *game);

// Doors
void			open_and_close_doors(t_game *game);

// Player
void			move_player(t_player *player, t_game *game);
void			init_player(t_player *player, t_game *game);

// Raycasting
void			ray_casting(t_game *game);
void			init_ray_struct(t_ray *ray, t_player *player, float angle);
void			draw_sprites(t_game *game);
void			set_values_wall(t_game *game, float *corrected_dist,
					t_ray *ray);
void			move_until_wall_is_hit(t_ray *ray, char **map);
int				add_shadow(int color, float corrected_dist);
int				get_tex_x(t_ray *ray, t_img *tex, float wall_hit);

// Sprites
void			draw_sprite_loop(t_game *game);
void			init_draw_sprite_struct(t_draw_sprite *sprite);
void			init_sprite_column_vars(t_sprite_column	*vars);

// Events
int				close_window(t_game *data);
int				key_press(int keycode, t_game *game);
int				key_release(int keycode, t_game *game);
int				key_press_linux(int keycode, void *param);
int				key_release_linux(int keycode, void *param);
int				mouse_click(int button, int x, int y, void *param);
int				mouse_move(int x, int y, t_game *game);

// Utils
int				count_lines(char **lines);
int				ft_strcmp(char *s1, char *s2);
int				ft_str_is_whitespace(char *str);
int				is_valid_map_line(char *line);
int				has_wall_start(char *line);
void			put_pixel_to_img(t_mlx *mlx, int x, int y, int color);
void			draw_sprite_to_img(t_mlx *dst, t_img *sprite,
					int x_offset, int y_offset);
void			load_textures(t_game *game);
void			free_split(char **split);
bool			is_wall(float px, float py, char **map);
bool			is_sprite(float px, float py, char **map);
unsigned long	get_time_ms(void);
t_img			*set_textures(t_ray *ray, t_game *game);

// Error and free
void			error_exit(t_game *data, char *message);
void			free_map(char **map);
void			free_resources(t_game *data);
void			free_lines(char **lines);

#endif
