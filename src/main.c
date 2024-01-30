/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lthong <lthong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 17:03:38 by nsion             #+#    #+#             */
/*   Updated: 2024/01/30 17:09:49 by lthong           ###   ########.fr       */
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
	end_exit(cub);
	return (0);
}

int	main(int ac, char **av)
{
	t_cub	cub;

	if (ac != 2)
		return (ft_printf("Error : Wrong argument.\n"));
	is_cub_file(av[1]);
	init_all_val(&cub);
	init_file(&cub, av[1]);
	ft_printf("Parsing done\n");

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
	init_texture(&cub);
	cub.img.img = mlx_new_image(cub.data.mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	cub.img.addr = mlx_get_data_addr(cub.img.img, &cub.img.bits_per_pixel, &cub.img.line_length, &cub.img.endian);
	put_color_in_game(&cub);
	draw_ray(&cub);
	mlx_hook(cub.data.mlx_win, 2, 0, key_move, &cub);
	mlx_hook(cub.data.mlx_win, 3, 0, key_move_release, &cub);
	mlx_hook(cub.data.mlx_win, 17, 0, end, &cub);
	mlx_loop(cub.data.mlx);

	end_exit(&cub);
	return (0);
}

//main = on va tout check et initialiser et nettoyer pour bien fermer
//is_cub_file = on check si c'est un fichier lisible
//init_file = on stock tout le ficher et check si il est correct et 
//le separer en 3 partie
//faire un init des variable init_variable