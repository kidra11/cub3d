/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbach <bbach@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 16:14:23 by nsion             #+#    #+#             */
/*   Updated: 2024/01/10 10:24:45 by bbach            ###   ########.fr       */
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

int	main(int ac, char **av)
{
	t_cub cub;

	if (ac != 2)
		return (ft_printf("Error\nWrong number of arguments\n"));
	is_cub_file(av[1]);
	init_maps(av[1], &cub);
	// init_1(&cub);
	free_everything(&cub);
	return (0);
}
