/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbach <bbach@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 15:41:31 by bbach             #+#    #+#             */
/*   Updated: 2024/01/31 15:33:30 by bbach            ###   ########.fr       */
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

# define ESC 65307
# define Z 122
# define S 115
# define Q 113
# define D 100
# define RIGHT 65363
# define LEFT 65361

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
	double		line_h;
	double		line_o;
	double		ca;
	int			side;
}				t_ray;

typedef struct s_player
{
	double		pos_x;
	double		pos_y;
	double		pa;
	double		pdx;
	double		pdy;
}				t_player;

typedef struct s_texture
{
	int			width;
	int			height;
	t_img		img;
}				t_texture;

typedef struct s_render
{
	int			tex_col;
	double		tex_x;
	double		tex_y;
}				t_render;

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
	char		player;
}				t_data;

typedef struct s_cub
{
	int			lines_count;
	char		**all;
	char		**map;
	char		**new_map;
	char		**tex;
	char		**colors;
	t_player	player;
	t_data		data;
	t_img		img;
	t_ray		ray;
	t_render	render;
	t_texture	no;
	t_texture	so;
	t_texture	we;
	t_texture	ea;
	t_texture	*cur_tex;
}				t_cub;

//check_colors_1.c
void		two_commas_only(t_cub *cub);
void		check_first_letter(t_cub *cub);
void		three_spaces_only(t_cub *cub);
void		check_format(t_cub *cub);
void		check_colors(t_cub *cub);

//check_colors_2.c
void		get_f_color(t_cub *cub, int i);
void		get_c_color(t_cub *cub, int i);
void		check_if_between_0_255(t_cub *cub);
int			rgb(int r, int g, int b);

//check_map_1.c
void		flood_the_wall(t_cub *cub);
void		check_map(t_cub *cub);

//check_map_2.c
void		elements_in_map(t_cub *cub);
void		where_is_the_player(t_cub *cub);

//check_syntax.
void		map_end(t_cub *cub);
void		duble(t_cub *cub);
int			find_map(char **str);
void		check_syntax(t_cub *cub);

//check_textures.c
void		check_1st_letter(t_cub *cub);
void		check_texture_path_1(t_cub *cub);
void		get_path_texture(t_cub *cub);
void		check_path_correct(t_cub *cub);
void		check_texture(t_cub *cub);

//clean_exit.c
void		clean_all_exit(char *message, t_cub *cub);
void		clean_exit(char *message, t_cub *cub);
void		end_exit(t_cub *cub);
void		free_tab(char **tab);

//draw.c
void		my_mlx_pixel_put(t_img *data, int x, int y, int color);
void		draw_map(t_cub *cub);
void		draw_player_pos(t_cub *cub, int x, int y, int size);
void		draw_point(t_cub *cub, int x, int y, int color);
void		draw_vline(t_cub *cub, int x, int start, int end);

//handle_key.c
void		move_1(int keycode, t_cub *cub);
void		move_2(int keycode, t_cub *cub);
int			is_valid_move(t_cub *cub, double x, double y);
int			key_move_release(int keycode, t_cub *cub);
int			end(t_cub *cub);

//handle_key_2.c

int			key_move(int keycode, t_cub *cub);
void		key_move_end(int keycode, t_cub *cub);

//init.c
void		init_all_val(t_cub *cub);
void		init_file(t_cub *cub, char *file);
void		init_player(t_cub *cub);
void		init_ray(t_cub *cub);
void		init_texture(t_cub *cub);

//main.c
void		is_cub_file(char *file);
int			get_mapx_size(t_cub *cub);
int			get_mapy_size(t_cub *cub);
//new_map.c
int			longest_line(char **map);
char		*fill_the_line(int len);
void		fill_the_map(t_cub *cub);
void		new_map(t_cub *cub);

//raycast1.c
void		render(t_cub *cub, int r);
void		check_full_rota(t_cub *cub);
double		dist(double ax, double ay, double bx, double by);
void		side_texture(t_cub *cub);
void		draw_wall(t_cub *cub, int r);

//raycast2.c
void		horizontal_check(t_cub *cub, int *dof, double a_tan);
void		horizontal_hit(t_cub *cub, int *dof);
void		vertical_check(t_cub *cub, int *dof, double n_tan);
void		vertical_hit(t_cub *cub, int *dof);
void		closest_ray(t_cub *cub);

//render.c
void		draw_ray(t_cub *cub);
int			get_texel_color(t_texture *texture, int x, int y);
void		put_color_in_game(t_cub *cub);
t_texture	load_texture(t_cub *cub, char *xpm_file);

//stock_elem.c
int			count_elem(t_cub *cub, int choise);
void		text_map_malloc(t_cub *cub);
void		stock_elem(t_cub *cub);

//stock.c
char		*ft_copy(const char *str, int start, int end);
int			count_lines(char *file);
char		**stock(char *file);

//testeur.c
void		printf_tab(char **all, char *name);

#endif