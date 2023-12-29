/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbach <bbach@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 16:14:23 by nsion             #+#    #+#             */
/*   Updated: 2023/12/29 14:12:03 by bbach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_1(t_cub *cub)
{
	cub->lines_count = 0;
	cub->map = NULL;
	cub->data.player_pos_x = 0;
	cub->data.player_pos_y = 0;
}

int	main(int ac, char **av)
{
	t_cub cub;

	if (ac != 2)
		clean_exit("Error : Non file.", &cub);
	ft_printf("test_main_1\n");
	init_maps(av[1], &cub);
	return (0);
}
