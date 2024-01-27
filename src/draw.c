/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lthong <lthong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 19:12:17 by lthong            #+#    #+#             */
/*   Updated: 2024/01/26 19:27:08 by lthong           ###   ########.fr       */
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

void	draw_line(t_cub *cub, int x1, int y1, int x2, int y2, double tex_x, double tex_y, t_texture *texture)
{
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = x1 < x2 ? 1 : -1;
    int sy = y1 < y2 ? 1 : -1;
    int err = dx - dy;

    while (1)
	{
		int color = get_texel_color(texture, tex_x, tex_y);
        mlx_pixel_put(cub->data.mlx, cub->data.mlx_win, x1, y1, color);
        if (x1 == x2 && y1 == y2)
            break;
        int e2 = 2 * err;
        if (e2 > -dy)
		{
            err -= dy;
            x1 += sx;
        }
        if (e2 < dx)
		{
            err += dx;
            y1 += sy;
        }
    }
}

void draw_thick_line(t_cub *cub, int x1, int y1, int x2, int y2, double tex_x, double tex_y, int thickness, t_texture *texture)
{
    for (int i = 0; i < thickness; i++)
    {
        draw_line(cub, x1 + i, y1, x2 + i, y2, tex_x, tex_y, texture);
    }
}

/*void draw_thick_line(t_cub *cub, int x1, int y1, int x2, int y2, int thickness, int color)
{
    for (int i = 0; i < thickness; i++)
    {
        draw_line(cub, x1 + i, y1, x2 + i, y2, color);
    }
}*/

void	draw_map(t_cub *cub)
{
	int	i;
	int	j;

	i = 0;
	while (cub->map[i])
	{
		j = 0;
		while (cub->map[i][j])
		{
			if (cub->map[i][j] == '1')
				draw_point(cub, j * cub->data.map_size, i * cub->data.map_size,
					rgb(255, 255, 255));
			else if (cub->map[i][j] == '0')
				draw_point(cub, j * cub->data.map_size, i * cub->data.map_size,
					rgb(0, 0, 0));
			j++;
		}
		i++;
	}
}

void	draw_player(t_cub *cub)
{
	int	size;

	size = 10;
	draw_player_pos(cub, cub->player.pos_x, cub->player.pos_y, size);
	//draw_line(cub, cub->player.pos_x + size / 2, cub->player.pos_y + size / 2,
	//	cub->player.pos_x + cub->player.pdx * 10,
	//	cub->player.pos_y + cub->player.pdy * 10, rgb(255, 255, 0));
	draw_ray(cub);
}
