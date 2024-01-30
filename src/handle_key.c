/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lthong <lthong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 19:16:42 by lthong            #+#    #+#             */
/*   Updated: 2024/01/30 17:08:01 by lthong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	key_move(int keycode, t_cub *cub)
{
	if (keycode == 13) //w
	{
		cub->player.pos_x += cub->player.pdx;
		cub->player.pos_y += cub->player.pdy;
	}
	else if (keycode == 1) //s
	{
		cub->player.pos_x -= cub->player.pdx;
		cub->player.pos_y -= cub->player.pdy;
	}
	else if (keycode == 0) //a
	{
		cub->player.pos_x += cub->player.pdy;
		cub->player.pos_y -= cub->player.pdx;
	}
	else if (keycode == 2) //d
	{
		cub->player.pos_x -= cub->player.pdy;
		cub->player.pos_y += cub->player.pdx;
	}
	else if (keycode == 123) // <-
	{
		cub->player.pa -= 0.1;
		if (cub->player.pa < 0)
			cub->player.pa += 2 * PI;
		cub->player.pdx = cos(cub->player.pa) * 5;
		cub->player.pdy = sin(cub->player.pa) * 5;
	}
	else if (keycode == 124) // ->
	{
		cub->player.pa += 0.1;
		if (cub->player.pa > 2 * PI)
			cub->player.pa -= 2 * PI;
		cub->player.pdx = cos(cub->player.pa) * 5;
		cub->player.pdy = sin(cub->player.pa) * 5;
	}
	else if (keycode == 53) //esc
	{
		mlx_destroy_window(cub->data.mlx, cub->data.mlx_win);
		exit(0);
	}
	mlx_clear_window(cub->data.mlx, cub->data.mlx_win);
	put_color_in_game(cub);
	draw_ray(cub);
	return (0);
}

int	key_move_release(int keycode, t_cub *cub)
{
	if (keycode == 13)
		cub->player.pos_y -= 0;
	if (keycode == 1)
		cub->player.pos_y += 0;
	if (keycode == 0)
		cub->player.pos_x -= 0;
	if (keycode == 2)
		cub->player.pos_x += 0;
	return (0);
}
