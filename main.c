/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbach <bbach@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 16:14:23 by nsion             #+#    #+#             */
/*   Updated: 2024/01/24 15:02:49 by bbach            ###   ########.fr       */
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

void	init_window_screen(t_cub *cub)
{
	cub->img = (t_img *)malloc(sizeof(t_img));
    if (cub->img == NULL) 
	{
        printf("Erreur : Impossible d'allouer la mémoire pour cub->img.\n");
        return ;
    }
	cub->img = mlx_new_image(cub->data.mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	cub->img->addr = mlx_get_data_addr(cub->img, &cub->img->bits_per_pixel, &cub->img->line_length, &cub->img->endian);
}
int	main(int ac, char **av)
{
	t_cub cub;


	if (ac != 2)
		return (ft_printf("Error\nWrong number of arguments\n"));
	
	is_cub_file(av[1]);
	init_1(&cub);
	init_maps(av[1], &cub);
	
	cub.data.mlx = mlx_init();
	cub.data.mlx_win = mlx_new_window(cub.data.mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "cub3D");
	printf("ici\n");
	init_window_screen(&cub);
	printf("peut etre la ?\n");
	printf("ou peut etre la ?\n");
	put_color_in_game(&cub);	
	printf("ou apparement c'est la ?\n");
	mlx_loop(cub.data.mlx);
	
	free_everything(&cub);
	return (0);
}
