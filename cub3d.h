/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsion <nsion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 16:13:30 by nsion             #+#    #+#             */
/*   Updated: 2023/12/21 17:55:10 by nsion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include <math.h>
# include <string.h>
# include "ft_printf/libftprintf.h"
# include "get_next_line/get_next_line.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_data{
	void	*mlx;
	void	*wi;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
	double	zoom;
	double	offset_x;
	double	offset_y;
	int		choise;
	double	av_x;
	double	av_y;
	int		color;
}				t_data;

//main.c

int	ft_strlen(char *s);
int	is_cub_file(char *file);
char	*hihi(const char *str, int start, int end);
char **stock_file(int fd);
void	init_maps(char *file);

#endif