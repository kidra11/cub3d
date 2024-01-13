/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathalie <nathalie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 15:41:31 by bbach             #+#    #+#             */
/*   Updated: 2024/01/13 17:47:21 by nathalie         ###   ########.fr       */
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

typedef struct s_data
{
	int		red_f;
	int		green_f;
	int		blue_f;
	int		red_c;
	int		green_c;
	int		blue_c;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		player_pos_x;
	int		player_pos_y;
}				t_data;

typedef struct s_cub
{
	int			lines_count;
	char		**all;
	char		**map;
	char		**tex;
	char		**colors;
	t_data		data;
}			t_cub;

//clean_exit.c
void	clean_exit(char *message, t_cub *cub);

//check_syntax.c
void	duble(t_cub *cub);
int		find_map(char **str);
void	check_syntax(t_cub *cub);

//check_map.c
void	check_map(t_cub *cub);

//stock.c
char	*ft_copy(const char *str, int start, int end);
int		count_lines(char *file);
char	**stock(char *file);

//main.c
void	init_file(char *file);
void	is_cub_file(char *file);

//testeur.c
void	printf_tab(char **all, char *name);

#endif