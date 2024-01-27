/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_gaming.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbach <bbach@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 14:24:34 by bbach             #+#    #+#             */
/*   Updated: 2024/01/27 16:25:34 by bbach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	my_mlx_pixel_put(t_cub *cub, int x, int y, int color)
{
	char	*pixel;

	if (y < 0 || y > cub->data.display_height - 1 || x < 0
		|| x > cub->data.display_width - 1)
		return ;
	pixel = (cub->img[4].addr + (y * cub->img[4].line_length
				+ x * (cub->img[4].bits_per_pixel / 8)));
	*(int *)pixel = color;
}

int     trgb(int t, int r, int g, int b)
{
    return (t << 24 | r << 16 | g << 8 | b);
}

void    render_background(t_cub *cub)
{
    int x;
    int y;

    x = 0;
    while (x < cub->data.display_width)
    {
        y = 0;
        while (y < cub->data.display_height)
        {
            if (y < cub->data.display_height / 2)
                my_mlx_pixel_put(cub, x, y, trgb(0, cub->data.red_c, cub->data.green_c, cub->data.blue_c));
            else
                my_mlx_pixel_put(cub, x, y, trgb(0, cub->data.red_f, cub->data.green_f, cub->data.blue_f));
            y++;
        }
    ++x;       
    }
}

int    render(t_cub *cub)
{
    render_background(cub);
    raycasting(cub);
    mlx_put_image_to_window(cub->data.mlx, cub->data.mlx_win, cub->img[4].mlx_img, 0, 0);
    return (0);
}

void    init_img(t_cub *cub)
{
    int i;

    i = 0;

    while (i < 4)
    {
        printf("width = %d\n", cub->img[i].width);
        printf("height = %d\n", cub->img[i].height);
        cub->img[i].mlx_img = mlx_xpm_file_to_image(cub->data.mlx, cub->img[i].path, &cub->img[i].width, &cub->img[i].height);
        if (!cub->img[i].mlx_img)
            clean_exit("Error\nInvalid texture path 1", cub);
        i++;
    }
    cub->img[4].mlx_img = mlx_new_image(cub->data.mlx, cub->data.display_width, cub->data.display_height);
    if (!cub->img[4].mlx_img)
        clean_exit("Error\nInvalid texture path 2", cub);
    i = 0;
    while (i < 5)
    {
        cub->img[i].addr = mlx_get_data_addr(cub->img[i].mlx_img, &cub->img[i].bits_per_pixel, &cub->img[i].line_length, &cub->img[i].endian);
        if (!cub->img[i].addr)
            clean_exit("Error\nfailed image", cub);
        i++;
    }
}

void	init_game_stat(t_cub *cub)
{
	cub->data.speed = 0.09;
	cub->data.rot_speed = 0.09;
	cub->data.display_width = 1940;
	cub->data.display_height = 1280;
	if (cub->data.player == 'N')
	{
        cub->data.dir_x = 0;
        cub->data.dir_y = -1;
		cub->data.plane_x = 0.66;
		cub->data.plane_y = 0;
	}
	if (cub->data.player == 'S')
	{
        cub->data.dir_x = 0;
        cub->data.dir_y = 1;
		cub->data.plane_x = -0.66;
		cub->data.plane_y = 0;
	}
	if (cub->data.player == 'W')
	{
        cub->data.dir_x = -1;
        cub->data.dir_y = 0;
		cub->data.plane_x = 0;
		cub->data.plane_y = 0.66;
	}
	if (cub->data.player == 'E')
	{
        cub->data.dir_x = 1;
        cub->data.dir_y = 0;
		cub->data.plane_x = 0;
		cub->data.plane_y = -0.66;
	}
}

int init_game(t_cub *cub)
{
    printf("test 4\n");
    init_game_stat(cub);
    printf("test 5\n");
    cub->data.mlx = mlx_init();
    printf("test 6\n");
    if (!cub->data.mlx)
        clean_exit("Error\nfailed mlx", cub);
    printf("test 7\n");
    cub->data.mlx_win = mlx_new_window(cub->data.mlx, cub->data.display_width, cub->data.display_height, "cub3d");
    printf("test 8\n");
    if (!cub->data.mlx_win)
        clean_exit("Error\nfailed mlx", cub);
    printf("test 9\n");
    init_img(cub);
    printf("test 10\n");
    mlx_loop_hook(cub->data.mlx, &render, cub);
    printf("test 11\n");
    //mlx_loop(cub->data.mlx);
    printf("test 12\n");
    return (0);
}