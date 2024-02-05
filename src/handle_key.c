/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsion <nsion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 19:16:42 by lthong            #+#    #+#             */
/*   Updated: 2024/02/05 14:42:10 by nsion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	move_1(int keycode, t_cub *cub)
{
	double	new_pos_x;
	double	new_pos_y;

	new_pos_x = cub->player.pos_x;
	new_pos_y = cub->player.pos_y;
	if (keycode == Z)
	{
		new_pos_x += cub->player.pdx;
		new_pos_y += cub->player.pdy;
	}
	else if (keycode == S)
	{
		new_pos_x -= cub->player.pdx;
		new_pos_y -= cub->player.pdy;
	}
	if (is_valid_move(cub, new_pos_x, new_pos_y))
	{
		cub->player.pos_x = new_pos_x;
		cub->player.pos_y = new_pos_y;
	}
}

void	move_2(int keycode, t_cub *cub)
{
	double	new_pos_x;
	double	new_pos_y;

	new_pos_x = cub->player.pos_x;
	new_pos_y = cub->player.pos_y;
	if (keycode == Q)
	{
		new_pos_x += cub->player.pdy;
		new_pos_y -= cub->player.pdx;
	}
	else if (keycode == D)
	{
		new_pos_x -= cub->player.pdy;
		new_pos_y += cub->player.pdx;
	}
	if (is_valid_move(cub, new_pos_x, new_pos_y))
	{
		cub->player.pos_x = new_pos_x;
		cub->player.pos_y = new_pos_y;
	}
}

int	is_valid_move(t_cub *cub, double x, double y)
{
	int	map_x;
	int	map_y;

	map_x = (int)(x / cub->data.map_size);
	map_y = (int)(y / cub->data.map_size);
	if (map_x < 0 || map_x >= cub->data.map_width || \
		map_y < 0 || map_y >= cub->data.map_height)
		return (0);
	if (cub->map[map_y][map_x] == '1')
		return (0);
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
	mlx_destroy_image(cub->data.mlx, cub->img.img);
	mlx_destroy_image(cub->data.mlx, cub->cur_tex->img.img);
	if (cub->data.mlx_win && cub->data.mlx)
		mlx_destroy_window(cub->data.mlx, cub->data.mlx_win);
	if (cub->data.mlx)
	{
		mlx_destroy_display(cub->data.mlx);
		mlx_loop_end(cub->data.mlx);
		free(cub->data.mlx);
	}
	end_exit(cub);
	return (0);
}
