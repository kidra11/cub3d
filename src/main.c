/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsion <nsion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 17:03:38 by nsion             #+#    #+#             */
/*   Updated: 2024/01/24 18:14:04 by nsion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	is_cub_file(char *file)
{
	int	i;

	i = 0;
	while (file[i])
		i++;
	if (file[i - 1] != 'b' || file[i - 2] != 'u' || file[i - 3] != 'c'\
		|| file[i - 4] != '.')
	{
		ft_printf("Error\nWrong file extension\n");
		exit(0);
	}
}

int	get_mapx_size(t_cub *cub)
{
	int	i;
	int	j;
	int	count;
	int	x_max;

	i = 0;
	x_max = 0;
	while (cub->map[i])
	{
		j = 0;
		count = 0;
		while (cub->map[i][j])
		{
			if (cub->map[i][j] == '1' || cub->map[i][j] == '0'
				|| cub->map[i][j] == ' ')
				count++;
			j++;
		}
		if (count > x_max)
			x_max = count;
		i++;
	}
	return (x_max);
}

int	get_mapy_size(t_cub *cub)
{
	int	i;

	i = 0;
	while (cub->map[i])
		i++;
	return (i);
}

int	end(t_cub *cub)
{
	mlx_destroy_image(cub->data.mlx, cub->img.img);
	mlx_loop_end(cub->data.mlx);
	mlx_destroy_window(cub->data.mlx, cub->data.mlx_win);
	mlx_destroy_display(cub->data.mlx);
	free(cub->data.mlx);
	end_exit(cub);
	return (0);
}

void	put_color_in_game(t_cub *cub)
{
	int	i;
	int	j;

	i = 0;
	while (i < 320)
	{
		j = 530;
		while (j < 1010)
		{
			if (i < 320 / 2)
				my_mlx_pixel_put(&cub->img, j, i, rgb(cub->data.red_c, cub->data.green_c, cub->data.blue_c));
			else
				my_mlx_pixel_put(&cub->img, j, i, rgb(cub->data.red_f, cub->data.green_f, cub->data.blue_f));
			j++;
		}
		i++;
	}
}
int	main(int ac, char **av)
{
	t_cub	cub;

	if (ac != 2)
		return (ft_printf("Error : Wrong argument.\n"));
	is_cub_file(av[1]);
	init_all_val(&cub);
	init_file(&cub, av[1]);
	cub.data.map_width = get_mapx_size(&cub);
	cub.data.map_height = get_mapy_size(&cub);
	int i = 0;
	while (cub.map[i])
	{
		ft_printf("%s\n", cub.map[i]);
		i++;
	}
	cub.data.mlx = mlx_init();
	cub.data.mlx_win = mlx_new_window(cub.data.mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "cub3D");
	init_player(&cub);
	cub.img.img = mlx_new_image(cub.data.mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	cub.img.addr = mlx_get_data_addr(cub.img.img, &cub.img.bits_per_pixel, &cub.img.line_length, &cub.img.endian);
	put_color_in_game(&cub);
	draw_map(&cub);
	draw_player(&cub);
	printf("Player position: (%f, %f)\n", cub.player.pos_x, cub.player.pos_y);
	printf("Player direction: %f radians\n", cub.player.pa);
	printf("Ray direction: %f radians\n", cub.ray.ra);
	mlx_hook(cub.data.mlx_win, 17, 0, end, &cub);
	mlx_hook(cub.data.mlx_win, 2, 1L<<0, key_move, &cub);
	mlx_hook(cub.data.mlx_win, 3, 1L<<1, key_move_release, &cub);
	mlx_loop(cub.data.mlx);
	end_exit(&cub);
	return (0);
}

//main = on va tout check et initialiser et nettoyer pour bien fermer
//is_cub_file = on check si c'est un fichier lisible
//init_file = on stock tout le ficher et check si il est correct et 
//le separer en 3 partie
//faire un init des variable init_variable