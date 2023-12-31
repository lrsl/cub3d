/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toteixei <toteixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 12:20:26 by toteixei          #+#    #+#             */
/*   Updated: 2023/12/11 16:09:05 by toteixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "struct.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>

// # include "../mlx_macos/mlx.h"
# include "../mlx_linux/mlx.h"

# define SCREEN_WIDTH 1500
# define S_HEIGHT 900
# define PI 3.1415926535
# define MOTIONNOTIFY 6
# define KEYPRESS 2
# define KEYRELEASE 3

enum
{
	ON_DESTROY = 17,
};

// LINUX KEYS
enum
{
	A_KEY = 97,
	D_KEY = 100,
	W_KEY = 119,
	S_KEY = 115,
	Q_KEY = 113,
	E_KEY = 101,
	ESC = 65307,
	KB_UP = 0xFF52,
	KB_DOWN = 0xFF54,
	KB_RIGHT = 0xFF51,
	KB_LEFT = 0xFF53,
};

// MacOS KEYS
// enum {
// 	A_KEY = 0,
//     D_KEY = 2,
//     W_KEY = 13,
// 	S_KEY = 1,
// 	ESC = 53,
//     Q_KEY = 12,
//     E_KEY = 14,
//     KB_UP = 126,
//     KB_DOWN = 125,
//     KB_RIGHT = 124,
//     KB_LEFT = 123,
// };

int				main(int argc, char **argv);
int				init_textures_bis(t_cub3d *cub3d);
int				init_textures(t_cub3d *cub3d);
void			init_cub3d(t_cub3d *cub3d);
int				init_mlx_settings(t_cub3d *cub3d);

// Parsing functions
t_configuration	*ft_configuration(char *file_path);
t_configuration	*parse_map(int fd, int len);
t_configuration	*fill_config_arg(char **file, int i);
int				parse_line(char *line, t_configuration **config);
t_configuration	*init_config_struct(void);
int				fill_map(char *line, t_configuration **config);
int				fill_element(char *line, t_configuration **config);
void			skip_whitespaces(char *line, int *i);
void			print_map(t_configuration *confi, int **map);
int				fill_element_bis(char *line, t_configuration **config, int *i);
void			fill_floor_ceiling_color(int color[3], char *line, int *i);
int				is_element(char *line);
int				is_map(char *line, t_configuration *config);
int				check_arguments(t_configuration *config);
int				check_map(t_configuration *config);
int				check_xpm_file(t_configuration *config);
int				check_floor_ceiling_color(t_configuration *config);
int				check_missing_argument(t_configuration *config);
int				ft_check_file_path(char *file);
int				flood_fill(t_configuration *config, int **map, int y, int x);
int				**duplicate_map(t_configuration *config);
int				find_player(t_configuration *config);
int				realloc_map(t_configuration **config);
int				check_map_limits(t_configuration *config, int i, int j,
					int **map);
char			*malloc_good_size(char *line, int i, int column);
int				find_file_len(char *path);
int				fill_element_quater(char *line, t_configuration **config,
					int *i);

// Game functions
int				ft_render_game(t_cub3d *cub3d);
void			draw_line(t_cub3d *cub3d, t_point p1, t_point p2);

// Minimap functions
void			ft_print_map(t_cub3d *cub3d);

// Deal key functions
int				deal_key(int key, t_cub3d *cub3d);
int				end_program(t_cub3d *cub3d);
int				deal_mouse(int x, int y, t_cub3d *cub3d);
void			free_config(t_configuration *config);

// Camera functions
void			rotate_left(t_camera *cam, float rot_speed);
void			rotate_right(t_camera *cam, float rot_speed);
void			move_to_the_right(t_cub3d *cub3d);
void			move_to_the_left(t_cub3d *cub3d);
void			move_forward(t_cub3d *cub3d);
void			move_backward(t_cub3d *cub3d);
int				is_wall(float x, float y, t_cub3d *cub3d);

// Raycasting functions
void			render_texture_tree(t_ray ray, t_cub3d *cub3d, int x);
void			set_side_dist(t_ray *ray, t_cub3d *cub3d);
void			set_ray_variables(t_ray *r, t_cub3d *c);
void			ray_side_map(t_ray *ray, t_cub3d *cub3d);
void			draw_rays_3d(t_cub3d *cub3d);

// MLX functions
void			img_pixel_put(int x, int y, unsigned int color, t_cub3d *cub3d);
int				get_color(int *color);

#endif