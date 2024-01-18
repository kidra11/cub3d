/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbach <bbach@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 13:31:46 by bbach             #+#    #+#             */
/*   Updated: 2024/01/17 14:08:53 by bbach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    init_ray(t_cub *cub)
{
    if (cub->data.player == 'N')
    {
        cub->data.player_dir_y = -1;
        cub->data.player_dir_x = 0;
        cub->data.plane_x = 0;
        cub->data.plane_y = 0.66;
    }
    if (cub->data.player == 'S')
    {
        cub->data.player_dir_x = 0;
        cub->data.player_dir_y = 1;
        cub->data.plane_x = 0;
        cub->data.plane_y = -0.66;
    }
    if (cub->data.player == 'E')
    {
        cub->data.player_dir_x = 1;
        cub->data.player_dir_y = 0;
        cub->data.plane_x = 0.66;
        cub->data.plane_y = 0;
    }
    if (cub->data.player == 'W')
    {
        cub->data.player_dir_x = -1;
        cub->data.player_dir_y = 0;
        cub->data.plane_x = -0.66;
        cub->data.plane_y = 0;
    }
}

int	trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}


void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}


void    put_color_in_game(t_cub *cub)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (x < SCREEN_HEIGHT)
	{
		y = 0;
		while (y < SCREEN_WIDTH / 2)
		{
			my_mlx_pixel_put(&cub->img, x, y, trgb(0, cub->data.red_f, cub->data.green_f, cub->data.blue_f));
			y++;
		}
		while (y < SCREEN_WIDTH)
		{
			my_mlx_pixel_put(&cub->img, x, y, trgb(0, cub->data.red_c, cub->data.green_c, cub->data.blue_c));
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(cub->data.mlx, cub->data.mlx_win, cub->img.img, 0, 0);
}
void    fill_it(t_cub *cub)
{
    int x;
    int y;

    x = 32;
    y = 32;
    cub->data.no = mlx_xpm_file_to_image(cub->data.mlx, "img/no.xpm", &x, &y);
    cub->data.so = mlx_xpm_file_to_image(cub->data.mlx, "img/so.xpm", &x, &y);
    cub->data.ea = mlx_xpm_file_to_image(cub->data.mlx, "img/player.xpm", &x, &y);
    cub->data.we = mlx_xpm_file_to_image(cub->data.mlx, "img/we.xpm", &x, &y);
}
