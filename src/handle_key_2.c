/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbach <bbach@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:29:21 by bbach             #+#    #+#             */
/*   Updated: 2024/01/31 15:32:29 by bbach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	key_move(int keycode, t_cub *cub)
{
	if (keycode == Z || keycode == S || keycode == Q || keycode == D)
	{
		move_1(keycode, cub);
		move_2(keycode, cub);
	}
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
	key_move_end(keycode, cub);
	return (0);
}

void	key_move_end(int keycode, t_cub *cub)
{
    if (keycode == ESC)
		end(cub);
	mlx_clear_window(cub->data.mlx, cub->data.mlx_win);
	put_color_in_game(cub);
	draw_ray(cub);
}