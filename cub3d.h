/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathalie <nathalie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 15:41:31 by bbach             #+#    #+#             */
/*   Updated: 2024/01/16 18:19:41 by nathalie         ###   ########.fr       */
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
void	clean_all_exit(char *message, t_cub *cub);
void	clean_exit(char *message, t_cub *cub);
void	end_exit(t_cub *cub);
void	free_tab(char **tab);

//check_colors_1.c
void	two_commas_only(t_cub *cub);
void	check_first_letter(t_cub *cub);
void	three_spaces_only(t_cub *cub);
void	check_format(t_cub *cub);
void	check_colors(t_cub *cub);

//check_colors_2.c
void	get_f_color(t_cub *cub, int i);
void	get_c_color(t_cub *cub, int i);
void	check_if_between_0_255(t_cub *cub);

//check_textures.c
void	check_1st_letter(t_cub *cub);
void	check_texture_path_1(t_cub *cub);
void	get_path_texture(t_cub *cub);
void	check_path_correct(t_cub *cub);
void	check_texture(t_cub *cub);

//check_map.c
void	flood_the_wall(t_cub *cub);
void	check_map(t_cub *cub);

//stock_elem.c
void	elements_in_map(t_cub *cub);
int		count_elem(t_cub *cub, int choise);
void	text_map_malloc(t_cub *cub);
void	stock_elem(t_cub *cub);

//check_syntax.
void	map_end(t_cub *cub);
void	duble(t_cub *cub);
int		find_map(char **str);
void	check_syntax(t_cub *cub);

//stock.c
char	*ft_copy(const char *str, int start, int end);
int		count_lines(char *file);
char	**stock(char *file);

//main.c
void	init_all_val(t_cub *cub);
void	init_file(t_cub *cub, char *file);
void	is_cub_file(char *file);

//testeur.c
void	printf_tab(char **all, char *name);

#endif