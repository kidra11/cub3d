/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsion <nsion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 17:03:38 by nsion             #+#    #+#             */
/*   Updated: 2024/01/27 16:42:00 by nsion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_all_val(t_cub *cub)
{
	cub->lines_count = 0;
	cub->all = NULL;
	cub->colors = NULL;
	cub->tex = NULL;
	cub->map = NULL;
	cub->new_map = NULL;
	cub->data.no = NULL;
	cub->data.so = NULL;
	cub->data.we = NULL;
	cub->data.ea = NULL;
	cub->data.player_pos_x = 0;
	cub->data.player_pos_y = 0;
	cub->data.red_f = 0;
	cub->data.green_f = 0;
	cub->data.blue_f = 0;
	cub->data.red_c = 0;
	cub->data.green_c = 0;
	cub->data.blue_c = 0;
}

void	init_file(t_cub *cub, char *file)
{
	cub->all = stock(file);
	check_syntax(cub);
	stock_elem(cub);
	check_map(cub);
	check_texture(cub);
	check_colors(cub);
}

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

int	main(int ac, char **av)
{
	t_cub	cub;

	if (ac != 2)
		return (ft_printf("Error : Wrong argument.\n"));
	is_cub_file(av[1]);
	init_all_val(&cub);
	init_file(&cub, av[1]);
	init_game(&cub);
	end_exit(&cub);
	return (0);
}

//main = on va tout check et initialiser et nettoyer pour bien fermer
//is_cub_file = on check si c'est un fichier lisible
//init_file = on stock tout le ficher et check si il est correct et 
//le separer en 3 partie
//faire un init des variable init_variable