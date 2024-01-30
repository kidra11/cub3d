/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsion <nsion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 19:24:58 by lthong            #+#    #+#             */
/*   Updated: 2024/01/30 19:08:20 by nsion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_all_val(t_cub *cub)
{
	cub->lines_count = 0;
	cub->all = NULL;
	cub->colors = NULL;
	cub->tex = NULL;
	cub->map = NULL;
	cub->new_map = NULL;
	cub->data.map_size = 64;
	cub->data.map_width = 0;
	cub->data.map_height = 0;
	cub->data.no = NULL;
	cub->data.so = NULL;
	cub->data.we = NULL;
	cub->data.ea = NULL;
	cub->data.player_pos_x = 0;
	cub->data.player_pos_y = 0;
	cub->data.red_f = 0;
	cub->data.green_f = 0;
	cub->data.blue_f = 0;
	cub->data.red_c = 0;
	cub->data.green_c = 0;
	cub->data.blue_c = 0;
	cub->cur_tex = NULL;
}

void	init_file(t_cub *cub, char *file)
{
	cub->all = stock(file);
	check_syntax(cub);
	stock_elem(cub);
	check_map(cub);
	check_texture(cub);
	check_colors(cub);
	init_player(cub);
}

void	init_player(t_cub *cub)
{
	cub->player.pos_x = cub->data.player_pos_x * \
		cub->data.map_size + cub->data.map_size / 2;
	cub->player.pos_y = cub->data.player_pos_y * \
		cub->data.map_size + cub->data.map_size / 2;
	if (cub->data.player == 'N')
		cub->player.pa = 3 * PI / 2;
	else if (cub->data.player == 'S')
		cub->player.pa = PI / 2;
	else if (cub->data.player == 'W')
		cub->player.pa = PI;
	else if (cub->data.player == 'E')
		cub->player.pa = 0;
	cub->player.pdx = cos(cub->player.pa) * 5;
	cub->player.pdy = sin(cub->player.pa) * 5;
}

void	init_ray(t_cub *cub)
{
	cub->ray.ra = cub->player.pa;
	cub->ray.rx = cos(cub->ray.ra);
	cub->ray.ry = sin(cub->ray.ra);
	cub->ray.xo = 0;
	cub->ray.yo = 0;
	cub->ray.mx = 0;
	cub->ray.my = 0;
	cub->ray.hx = 0;
	cub->ray.hy = 0;
	cub->ray.dist_h = 1000000000;
	cub->ray.vx = 0;
	cub->ray.vy = 0;
	cub->ray.dist_v = 1000000000;
	cub->ray.dist_f = 1;
	cub->ray.line_h = 0;
	cub->ray.line_o = 0;
	cub->ray.ca = 0;
	cub->ray.side = 0;
}

void	init_texture(t_cub *cub)
{
	cub->render.tex_col = 0;
	cub->render.tex_x = 0;
	cub->render.tex_y = 0;
	cub->no = load_texture(cub, cub->data.no);
	cub->so = load_texture(cub, cub->data.so);
	cub->we = load_texture(cub, cub->data.we);
	cub->ea = load_texture(cub, cub->data.ea);
}
