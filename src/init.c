/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsion <nsion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 19:24:58 by lthong            #+#    #+#             */
/*   Updated: 2024/01/22 18:36:25 by nsion            ###   ########.fr       */
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
}

void	init_file(t_cub *cub, char *file)
{
	cub->all = stock(file);
	check_syntax(cub);
	stock_elem(cub);
	check_map(cub);
	check_texture(cub);
	check_colors(cub);
}

void	init_player(t_cub *cub)
{
	cub->player.pos_x = 250;
	cub->player.pos_y = 250;
	cub->player.pa = PI / 2;
	cub->player.pdx = cos(cub->player.pa) * 5;
	cub->player.pdy = sin(cub->player.pa) * 5;
}

void	init_ray(t_cub *cub)
{
	cub->ray.ra = cub->player.pa;
	cub->ray.rx = cos(cub->ray.ra);
	cub->ray.ry = sin(cub->ray.ra);
}
