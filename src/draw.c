/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsion <nsion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 19:12:17 by lthong            #+#    #+#             */
/*   Updated: 2024/02/01 23:50:03 by nsion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_point(t_cub *cub, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i <= cub->data.map_size)
	{
		j = 0;
		while (j <= cub->data.map_size)
		{
			my_mlx_pixel_put(&cub->img, x + i, y + j, color);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(cub->data.mlx, cub->data.mlx_win,
		cub->img.img, 0, 0);
}

void	draw_player_pos(t_cub *cub, int x, int y, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i <= size)
	{
		j = 0;
		while (j <= size)
		{
			my_mlx_pixel_put(&cub->img, x + i, y + j, rgb(255, 255, 0));
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(cub->data.mlx, cub->data.mlx_win,
		cub->img.img, 0, 0);
}

void	draw_vline(t_cub *cub, int x, int start, int end)
{
	int	y;
	int	color;

	y = start;
	color = get_texel_color(cub->cur_tex, cub->render.tex_x, cub->render.tex_y);
	while (y <= end)
	{
		my_mlx_pixel_put(&cub->img, x, y, color);
		y++;
	}
}

void	draw_map(t_cub *cub)
{
	int	i;
	int	j;

	i = 0;
	while (cub->new_map[i])
	{
		j = 0;
		while (cub->new_map[i][j])
		{
			if (cub->new_map[i][j] == '1')
				draw_point(cub, j * cub->data.map_size, i * cub->data.map_size,
					rgb(255, 255, 255));
			else if (cub->new_map[i][j] == '0')
				draw_point(cub, j * cub->data.map_size, i * cub->data.map_size,
					rgb(0, 0, 0));
			j++;
		}
		i++;
	}
}
