/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsion <nsion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 15:41:31 by bbach             #+#    #+#             */
/*   Updated: 2024/01/27 17:12:35 by nsion            ###   ########.fr       */
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
	void	*mlx_img;
	char	*path;

	char    *addr;
	int     bits_per_pixel;
	int     line_length;
	int     endian;
	int		width;
	int		height;
}               t_img;

typedef struct s_data
{
	double	speed;
	double	rot_speed;
	
	double	plane_x;
	double	plane_y;

	double 	ray_dir_x;
	double 	ray_dir_y;

	double 	delta_dist_x;
	double 	delta_dist_y;
	
	int		step_x;
	int		step_y;

	double	side_dist_x;
	double	side_dist_y;
	
	int		display_width;
	int		display_height;
	
	int		red_f;
	int		green_f;
	int		blue_f;
	
	int		red_c;
	int		green_c;
	int		blue_c;
	
	double	pos_x;
	double	pos_y;

	int		map_x;
	int		map_y;
	
	int		wall_side;
	
	double  cam_x;
	
	double	dir_x;
	double	dir_y;
	
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	
	double	player_pos_x;
	double	player_pos_y;
	double	player_pa;

	char	player;
	
	double	perpwalldist;
	
	double 	wall_x;
	
	int		tex_x;
	int		tex_y;
	
	double	step;
	
	double 	tex_pos;
	
	int		start;
	int		end;
	
	void	*mlx;
	void	*mlx_win;
}				t_data;

typedef struct s_cub
{
	int			lines_count;
	char		**all;
	char		**map;
	char		**new_map;
	char		**tex;
	char		**colors;
	t_data		data;
	t_img		img[5];
}			t_cub;

//ft_hook.c
int		end(t_cub *cub);
int	key_move(int keycode, t_cub *cub);
void	init_key_move(int keycode, t_cub *cub);
int	key_move_release(int keycode, t_cub *cub);

//raycasting.c
void	get_delta_distance(t_cub *cub);
void	get_step(t_cub *cub);
void	define_column(t_cub *cub, int *line_height, int *start, int *end);
void	define_texture(t_cub *cub, int start, int line_height);
int		get_color(t_cub *cub, int x, int y, int i);
void	draw(t_cub *cub, int x, int texture);
void	draw_column(t_cub *cub, int x);
void	raycasting(t_cub *cub);
void	dda(t_cub *cub);
void	init_raycast(t_cub *cub, int x);

//start_gaming.c
void	my_mlx_pixel_put(t_cub *cub, int x, int y, int color);
int		trgb(int t, int r, int g, int b);
void	render_background(t_cub *cub);
int		render(t_cub *cub);
void	init_img(t_cub *cub);
void	init_game_stat(t_cub *cub);
int 	init_game(t_cub *cub);


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

//check_map_1.c
void	flood_the_wall(t_cub *cub);
void	check_map(t_cub *cub);

//check_map_2.c
void	elements_in_map(t_cub *cub);
void	where_is_the_player(t_cub *cub);
void	where_the_player_is_looking_1(t_cub *cub);
void	where_the_player_is_looking_2(t_cub *cub);

//new_map.
int		longest_line(char **map);
char	*fill_the_line(int len);
void	fill_the_map(t_cub *cub);
void	new_map(t_cub *cub);

//stock_elem.c
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