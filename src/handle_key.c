/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsion <nsion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 19:16:42 by lthong            #+#    #+#             */
/*   Updated: 2024/01/30 19:08:58 by nsion            ###   ########.fr       */
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
	if (keycode == Z)
	{
		cub->player.pos_x += cub->player.pdx;
		cub->player.pos_y += cub->player.pdy;
	}
	else if (keycode == S)
	{
		cub->player.pos_x -= cub->player.pdx;
		cub->player.pos_y -= cub->player.pdy;
	}
	else if (keycode == Q)
	{
		cub->player.pos_x += cub->player.pdy;
		cub->player.pos_y -= cub->player.pdx;
	}
	else if (keycode == D)
	{
		cub->player.pos_x -= cub->player.pdy;
		cub->player.pos_y += cub->player.pdx;
	}
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
