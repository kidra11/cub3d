/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nath <nath@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 17:03:38 by nsion             #+#    #+#             */
/*   Updated: 2024/01/14 23:01:22 by nath             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_file(char *file)
{
	t_cub	cub;

	cub.all = stock(file);
	check_syntax(&cub);
	stock_elem(&cub);
	check_map(&cub);
	printf_tab(cub.tex, "tex");
	printf_tab(cub.colors, "colors");
	printf_tab(cub.map, "map");
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
	if (ac != 2)
		return (ft_printf("Error : Wrong argument.\n"));
	is_cub_file(av[1]);
	init_file(av[1]);
	//clean_exit();
	return (0);
}

//main = on va tout check et initialiser et nettoyer pour bien fermer
//is_cub_file = on check si c'est un fichier lisible
//init_file = on stock tout le ficher et check si il est correct et 
//le separer en 3 partie