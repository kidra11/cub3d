/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbach <bbach@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 15:41:31 by bbach             #+#    #+#             */
/*   Updated: 2023/12/30 12:03:40 by bbach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "./includes/mlx/mlx.h"
# include "./includes/libft/libft.h"
# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define ESC 53
# define LEFT 123
# define RIGHT 124
# define PI 3.14159265358979323846
# define FOV 1.04719755119659774615
# define SPEED 0.1
# define ROT_SPEED 0.1
# define SCALE 1
# define SCALE2 0.5
# define SCALE3 0.25
# define SCALE4 0.125
# define SCALE5 0.0625
# define SCALE6 0.03125
# define SCALE7 0.015625
# define SCALE8 0.0078125
# define SCALE9 0.00390625
# define SCALE10 0.001953125
# define SCALE11 0.0009765625
# define SCALE12 0.00048828125


typedef struct	s_data
{
    int     player_pos_x;
    int     player_pos_y;
}				t_data;

typedef struct	s_sprite
{
    
}				t_sprite;

typedef struct s_cub
{
    int         lines_count;
    char        **all;
    char        **map_copy;
    char        **textures_path;
    char        **couleurs_path;
    t_data      data;
    t_sprite    sprite;
}            t_cub;

//main.C
void    init_1(t_cub *cub);
int     main(int ac, char **av);

//check_maps.c

char        *ft_copy(const char *str, int start, int end);
int         count_lines(char *file, t_cub *cub);


void	    init_maps(char *file, t_cub *cub);
void		is_cub_file(t_cub *cub, char *file);
void        get_map(char *file_path, t_cub *cub);
void        elements_in_map(t_cub *cub);

//clean_exit.c

void	clean_exit(char *message, t_cub *cub);

//init_map

void    all_mallc(t_cub *cub);
void    text_map_malloc(t_cub *cub);

#endif
