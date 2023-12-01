/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toteixei <toteixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 12:20:26 by toteixei          #+#    #+#             */
/*   Updated: 2023/12/01 15:12:13 by toteixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include <math.h>
# include <unistd.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <fcntl.h>
# include "struct.h"
# include "../mlx_macos/mlx.h"

# define SCREEN_WIDTH 1500
# define SCREEN_HEIGTH 900
# define PI 3.14159265359

enum {
	ON_DESTROY = 17,
};

/*LINUX KEYS
    A_KEY = 97,
    D_KEY = 100,
	W_KEY= 119,
	S_KEY = 115,
	ESC = 65307,
*/
enum {
	A_KEY = 0,
    D_KEY = 2,
    W_KEY = 13,
	S_KEY = 1,
	ESC = 53,
};

int             main(int argc, char **argv);

//Parsing functions
t_configuration *ft_configuration(char *file_path);
void	        skip_whitespaces(char *line, int *i);
void	        print_map(t_configuration *config);

//Game functions
int    ft_render_game(t_cub3d *cub3d);

//Deal key functions
int     deal_key(int key, t_cub3d *cub3d);
int     end_program(t_cub3d *cub3d);

//Camera functions
void    rotate_left(t_camera *cam);
void    rotate_right(t_camera *cam);
void    move_forward(t_camera *cam);
void    move_backward(t_camera *cam);

#endif