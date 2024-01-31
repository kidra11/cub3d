/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbach <bbach@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 19:16:42 by lthong            #+#    #+#             */
/*   Updated: 2024/01/31 14:38:58 by bbach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	key_move(int keycode, t_cub *cub)
{
	if (keycode == Z || keycode == S || keycode == Q || keycode == D)
		move(keycode, cub);
	else if (keycode == LEFT)
	{
		cub->player.pa -= 0.1;
		if (cub->player.pa < 0)
			cub->player.pa += 2 * PI;
		cub->player.pdx = cos(cub->player.pa) * 5;
		cub->player.pdy = sin(cub->player.pa) * 5;
	}
	else if (keycode == RIGHT)
	{
		cub->player.pa += 0.1;
		if (cub->player.pa > 2 * PI)
			cub->player.pa -= 2 * PI;
		cub->player.pdx = cos(cub->player.pa) * 5;
		cub->player.pdy = sin(cub->player.pa) * 5;
	}
	else if (keycode == ESC)
		end(cub);
	mlx_clear_window(cub->data.mlx, cub->data.mlx_win);
	put_color_in_game(cub);
	draw_ray(cub);
	return (0);
}
void	move(int keycode, t_cub *cub)
{
	double new_pos_x = cub->player.pos_x;
	double new_pos_y = cub->player.pos_y;

	if (keycode == Z || keycode == S 
	|| keycode == Q || keycode == D)
	{
		new_pos_x += cub->player.pdx;
		new_pos_y += cub->player.pdy;
	}
	if (is_valid_move(cub, new_pos_x, new_pos_y))
	{
		cub->player.pos_x = new_pos_x;
		cub->player.pos_y = new_pos_y;
	}
}

int	is_valid_move(t_cub *cub, double x, double y)
{
	int map_x;
	int map_y;

	map_x = (int)(x / cub->data.map_size);
	map_y = (int)(y / cub->data.map_size);

	if (map_x < 0 || map_x >= cub->data.map_width ||
		map_y < 0 || map_y >= cub->data.map_height)
		return 0;

	if (cub->map[map_y][map_x] == '1')
		return 0;

	return (1);
}

int	key_move_release(int keycode, t_cub *cub)
{
	if (keycode == Z)
		cub->player.pos_y -= 0;
	if (keycode == S)
		cub->player.pos_y += 0;
	if (keycode == Q)
		cub->player.pos_x -= 0;
	if (keycode == D)
		cub->player.pos_x += 0;
	return (0);
}

int	end(t_cub *cub)
{
	while (cub->data.mlx)
	{
		mlx_destroy_image(cub->data.mlx, cub->cur_tex->img.img);
		mlx_destroy_image(cub->data.mlx, cub->no.img.img);
		mlx_destroy_image(cub->data.mlx, cub->so.img.img);
		mlx_destroy_image(cub->data.mlx, cub->we.img.img);
		mlx_destroy_image(cub->data.mlx, cub->ea.img.img);
	}
	mlx_loop_end(cub->data.mlx);
	mlx_destroy_window(cub->data.mlx, cub->data.mlx_win);
	mlx_destroy_display(cub->data.mlx);
	free(cub->data.mlx);
	end_exit(cub);
	return (0);
}
