/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsion <nsion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 16:44:59 by nsion             #+#    #+#             */
/*   Updated: 2024/01/27 17:11:42 by nsion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	end(t_cub *cub)
{
    while (cub->data.mlx)
    {
        mlx_destroy_image(cub->data.mlx, cub->img[0].mlx_img);
        mlx_destroy_image(cub->data.mlx, cub->img[1].mlx_img);
        mlx_destroy_image(cub->data.mlx, cub->img[2].mlx_img);
        mlx_destroy_image(cub->data.mlx, cub->img[3].mlx_img);
        mlx_destroy_image(cub->data.mlx, cub->img[4].mlx_img);
    }
	mlx_loop_end(cub->data.mlx);
	mlx_destroy_window(cub->data.mlx, cub->data.mlx_win);
	mlx_destroy_display(cub->data.mlx);
	free(cub->data.mlx);
	end_exit(cub);
	return (0);
}

int	key_move(int keycode, t_cub *cub)
{
	if (keycode == ESC) //esc
		end(cub);
	if (keycode == Z || keycode == S || keycode == Q || keycode == D)
        init_key_move(keycode, cub);
	if (keycode == LEFT) //LEFT
	{
		cub->data.player_pa -= 0.1;
		if (cub->data.player_pa < 0)
			cub->data.player_pa += 2 * PI;
		cub->data.player_pos_x = cos(cub->data.player_pa) * 5;
		cub->data.player_pos_y = sin(cub->data.player_pa) * 5;
	}
	if (keycode == RIGHT) //RIGHT
	{
		cub->data.player_pa += 0.1;
		if (cub->data.player_pa > 2 * PI)
			cub->data.player_pa -= 2 * PI;
		cub->data.player_pos_x = cos(cub->data.player_pa) * 5;
		cub->data.player_pos_y = sin(cub->data.player_pa) * 5;
	}
	mlx_clear_window(cub->data.mlx, cub->data.mlx_win);
    render(cub);
	return (0);
}

void    init_key_move(int keycode, t_cub *cub)
{
    if (keycode == Z) //z
	{
		cub->data.player_pos_x += cub->data.player_pos_x;
		cub->data.player_pos_y += cub->data.player_pos_y;
	}
	if (keycode == S) //s
	{
		cub->data.player_pos_x -= cub->data.player_pos_x;
		cub->data.player_pos_y -= cub->data.player_pos_y;
	}
	if (keycode == Q) //q
	{
		cub->data.player_pos_x += cub->data.player_pos_y;
		cub->data.player_pos_y -= cub->data.player_pos_x;
	}
	if (keycode == D) //d
	{
		cub->data.player_pos_x -= cub->data.player_pos_y;
		cub->data.player_pos_y += cub->data.player_pos_x;
	}
}
int	key_move_release(int keycode, t_cub *cub)
{
	if (keycode == 13)
		cub->data.player_pos_y -= 0;
	if (keycode == 1)
		cub->data.player_pos_y += 0;
	if (keycode == 0)
		cub->data.player_pos_x -= 0;
	if (keycode == 2)
		cub->data.player_pos_x += 0;
	return (0);
}