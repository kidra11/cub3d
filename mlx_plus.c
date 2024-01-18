/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_plus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathalie <nathalie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 13:47:03 by nathalie          #+#    #+#             */
/*   Updated: 2024/01/18 17:06:07 by nathalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
    int i;
    int j;

    i = 0;
    j = 0;
    while (i < SCREEN_HEIGHT)
    {
        while (j < SCREEN_WIDTH)
        {
            my_mlx_pixel_put(&cub->img, i, j, trgb (0, 255, 0, 0));
            j++;
        }
        j = 0;
        i++;
    }
}

void	set_cub_env(t_cub *cub)
{
	cub->mlx = mlx_init();
	cub->mlx_win = mlx_new_window(cub->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "cub3D");
	cub->img.img = mlx_new_image(cub->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	cub->img.addr = mlx_get_data_addr(cub->img.img, &cub->img.bits_per_pixel, &cub->img.line_length, &cub->img.endian);
	put_color_in_game(cub);
	//mlx_key_hook(cub->mlx_win, handle_events, &cub);
	//mlx_hook(cub->mlx_win, 17, 0, handle_close, &cub);
	mlx_loop(cub->mlx);
}

/*int	handle_events(int keycode, t_cub *cub)
{
	if (keycode == ESC)
	{
		mlx_destroy_image(cub->mlx, cub->img.img);
		mlx_destroy_window(cub->data.mlx, cub->data.mlx_win);
		mlx_loop_end(cub->data.mlx);
		mlx_destroy_display(cub->data.mlx);
		end_exit(cub);
		exit(EXIT_SUCCESS);
	}
	else
		ft_printf("pas ESC\n");
	return (0);
}

int	handle_close(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->wi);
	mlx_loop_end(data->mlx);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(EXIT_SUCCESS);
	return (0);
}
*/