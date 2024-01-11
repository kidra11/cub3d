/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nath <nath@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:53:27 by nath              #+#    #+#             */
/*   Updated: 2024/01/11 19:03:29 by nath             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_map(t_cub *cub)
{
	int	i;

	i = 0;
	while (cub->all[i])
		i++;
	if (cub->all[i - 1][0] != '1' && cub->all[i - 1][0] != ' ')
		clean_exit("Error\nInvalid or missing map.", cub);
    else
		printf("map OK!\n");
}

//check_map = on va check tout si la map est bien placer ou si elle existe correctement
//