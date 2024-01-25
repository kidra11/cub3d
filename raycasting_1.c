/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbach <bbach@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 13:31:46 by bbach             #+#    #+#             */
/*   Updated: 2024/01/25 14:15:39 by bbach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    init_img(t_img *img)
{
    img->img = NULL;
    img->addr = NULL;
    img->bits_per_pixel = 0;
    img->line_length = 0;
    img->endian = 0;
}

void    init_data(t_data *data)
{
   init_img(&data->no_img);
   init_img(&data->so_img);
   init_img(&data->ea_img);
   init_img(&data->we_img);
}
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
void    get_image_and_get_adress(t_cub *cub)
{
    int x;
    int y;

    x = 64;
    y = 64;
    cub->data.no_img.img = mlx_xpm_file_to_image(cub->data.mlx, "img/no.xpm", &x, &y);
    cub->data.so_img.img = mlx_xpm_file_to_image(cub->data.mlx, "img/so.xpm", &x, &y);
    cub->data.ea_img.img = mlx_xpm_file_to_image(cub->data.mlx, "img/ea.xpm", &x, &y);
    cub->data.we_img.img = mlx_xpm_file_to_image(cub->data.mlx, "img/we.xpm", &x, &y);

    if (!cub->data.no_img.img || !cub->data.so_img.img || !cub->data.ea_img.img || !cub->data.we_img.img)
    {
        printf("Error\nWrong texture path\n");
        exit(0);
    }

    cub->data.no_img.addr = mlx_get_data_addr(cub->data.no_img.img, &cub->data.no_img.bits_per_pixel, &cub->data.no_img.line_length, &cub->data.no_img.endian);
    cub->data.so_img.addr = mlx_get_data_addr(cub->data.so_img.img, &cub->data.so_img.bits_per_pixel, &cub->data.so_img.line_length, &cub->data.so_img.endian);
    cub->data.ea_img.addr = mlx_get_data_addr(cub->data.ea_img.img, &cub->data.ea_img.bits_per_pixel, &cub->data.ea_img.line_length, &cub->data.ea_img.endian);
    cub->data.we_img.addr = mlx_get_data_addr(cub->data.we_img.img, &cub->data.we_img.bits_per_pixel, &cub->data.we_img.line_length, &cub->data.we_img.endian);
}

int	trgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}


void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}


void    put_color_in_game(t_cub *cub)
{
	int x;
	int y;

	x = 0;
	y = 0;
    init_data(&cub->data);
    init_ray(cub);
    get_image_and_get_adress(cub);
	while (x < SCREEN_HEIGHT)
	{
		y = 0;
		while (y < SCREEN_WIDTH / 2)
		{
			    my_mlx_pixel_put(cub->img, x, y, trgb( cub->data.red_f, cub->data.green_f, cub->data.blue_f));
            y++;
		}
		while (y < SCREEN_WIDTH)
		{
			my_mlx_pixel_put(cub->img, x, y, trgb( cub->data.red_c, cub->data.green_c, cub->data.blue_c));
			y++;
		}
		x++;
	}
    mlx_put_image_to_window(cub->data.mlx, cub->data.mlx_win, cub->img->img, 600, 600); 
    printf("player_dir_x = %f\n", cub->data.player_dir_x);
    rendering(cub);
	//mlx_put_image_to_window(cub->data.mlx, cub->data.mlx_win, cub->img->img, 0, 0);
}

// void	put_color_in_game(t_cub *cub)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (i < 600)
// 	{
// 		j = 0;
// 		while (j < 600)
// 		{
// 			if (i < 600 / 2)
// 				my_mlx_pixel_put(cub->img, j, i, trgb(0, 0, 0, 255));
// 			else
// 				my_mlx_pixel_put(cub->img, j, i, trgb(0, 255, 0, 0));
// 			j++;
// 		}
// 		i++;
// 	}
//     //mlx_put_image_to_window(cub->data.mlx, cub->data.mlx_win, cub->img->img, 0, 0);
// }