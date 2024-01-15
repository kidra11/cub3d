/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbach <bbach@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 16:14:23 by nsion             #+#    #+#             */
/*   Updated: 2024/01/15 17:19:07 by bbach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_1(t_cub *cub)
{
	cub->lines_count = 0;
	cub->all = NULL;
	cub->couleurs_path = NULL;
	cub->textures_path = NULL;
	cub->map_copy = NULL;
	cub->data.player_pos_x = 0;
	cub->data.player_pos_y = 0;
	cub->data.red_f = 0;
	cub->data.green_f = 0;
	cub->data.blue_f = 0;
	cub->data.red_c = 0;
	cub->data.green_c = 0;
	cub->data.blue_c = 0;

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
		printf("x = %d\n", x);
		printf("y = %d\n", y);
		while (y < SCREEN_WIDTH)
		{
			my_mlx_pixel_put(&cub->img, x, y, trgb(0, cub->data.red_c, cub->data.green_c, cub->data.blue_c));
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(cub->data.mlx, cub->data.mlx_win, cub->img.img, 0, 0);
}

int	main(int ac, char **av)
{
	t_cub cub;


	if (ac != 2)
		return (ft_printf("Error\nWrong number of arguments\n"));
	
	is_cub_file(av[1]);
	init_maps(av[1], &cub);
	
	cub.data.mlx = mlx_init();
	cub.data.mlx_win = mlx_new_window(cub.data.mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "cub3D");
	cub.img.img = mlx_new_image(cub.data.mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	cub.img.addr = mlx_get_data_addr(cub.img.img, &cub.img.bits_per_pixel, &cub.img.line_length, &cub.img.endian);
	put_color_in_game(&cub);
	mlx_loop(cub.data.mlx);
	
	free_everything(&cub);
	return (0);
}
