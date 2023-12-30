/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbach <bbach@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 16:14:23 by nsion             #+#    #+#             */
/*   Updated: 2023/12/30 15:47:10 by bbach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_1(t_cub *cub)
{
	cub->lines_count = 0;
	cub->all = NULL;
	cub->data.player_pos_x = 0;
	cub->data.player_pos_y = 0;
}

int	main(int ac, char **av)
{
	t_cub cub;

	if (ac != 2)
		return (ft_printf("Error\nWrong number of arguments\n"));
	is_cub_file(av[1]);
	init_maps(av[1], &cub);
	//clean_exit("fin du game", &cub);
	free_2d_array(&cub.map_copy);
	free_2d_array(&cub.textures_path);
	free_2d_array(&cub.couleurs_path);
	free_2d_array(&cub.all);
	return (0);
}
