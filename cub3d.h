/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lthong <lthong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 15:41:31 by bbach             #+#    #+#             */
/*   Updated: 2024/01/23 20:45:08 by lthong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "./mlx/mlx.h"
# include "./libft/libft.h"
# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define SCREEN_WIDTH 1024
# define SCREEN_HEIGHT 510

# define PI 3.14159265359
# define DR 0.0174533

typedef struct s_img
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_img;

typedef struct s_ray
{
	double		ra;
	double		rx;
	double		ry;
	double		xo;
	double		yo;
	int			mx;
	int			my;
	double		hx;
	double		hy;
	double		dist_h;
	double		vx;
	double		vy;
	double		dist_v;
	double		dist_f;
}				t_ray;

typedef struct s_player
{
	double		pos_x;
	double		pos_y;
	double		pa;
	double		pdx;
	double		pdy;
}				t_player;

typedef struct s_data
{
	void		*mlx;
	void		*mlx_win;
	int			red_f;
	int			green_f;
	int			blue_f;
	int			red_c;
	int			green_c;
	int			blue_c;
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	int			map_size;
	int			map_width;
	int			map_height;
	int			player_pos_x;
	int			player_pos_y;
}				t_data;

typedef struct s_cub
{
	int			lines_count;
	char		**all;
	char		**map;
	char		**tex;
	char		**colors;
	t_player	player;
	t_data		data;
	t_img		img;
	t_ray		ray;
}				t_cub;

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

int		rgb(int r, int g, int b);


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

//init.c
void	init_all_val(t_cub *cub);
void	init_file(t_cub *cub, char *file);
void	init_player(t_cub *cub);
void	init_ray(t_cub *cub);

//handle_key.c
int		key_move(int keycode, t_cub *cub);
int		key_move_release(int keycode, t_cub *cub);

//draw.c
void	my_mlx_pixel_put(t_img *data, int x, int y, int color);
void	draw_map(t_cub *cub);
void	draw_player(t_cub *cub);
void	draw_player_pos(t_cub *cub, int x, int y, int size);
void	draw_point(t_cub *cub, int x, int y, int color);
void	draw_line(t_cub *cub, int x1, int y1, int x2, int y2, int color);
void	draw_thick_line(t_cub *cub, int x1, int y1, int x2, int y2, int thickness, int color);

//raycast1.c
void	draw_ray(t_cub *cub);
void	check_full_rota(t_cub *cub);
double	dist(double ax, double ay, double bx, double by);

//raycast2.c
void	horizontal_check(t_cub *cub, int *dof, double a_tan);
void	horizontal_hit(t_cub *cub, int *dof);
void	vertical_check(t_cub *cub, int *dof, double n_tan);
void	vertical_hit(t_cub *cub, int *dof);
void	closest_ray(t_cub *cub);

//main.c
int		end(t_cub *cub);
int		get_mapx_size(t_cub *cub);
int		get_mapy_size(t_cub *cub);

#endif