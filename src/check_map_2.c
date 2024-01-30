/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsion <nsion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:02:58 by nsion             #+#    #+#             */
/*   Updated: 2024/01/30 16:16:40 by nsion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	elements_in_map(t_cub *cub)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (cub->new_map[i])
	{
		j = 0;
		while (cub->new_map[i][j])
		{
			if (cub->new_map[i][j] != '1' && cub->new_map[i][j] != '0' && \
				cub->new_map[i][j] != 'N' && cub->new_map[i][j] != 'S' && \
				cub->new_map[i][j] != 'E' && cub->new_map[i][j] != 'W' && \
				cub->new_map[i][j] != ' ')
				clean_exit("Error : Wrong element in map\n", cub);
			else if (cub->new_map[i][j] == 'N' || cub->new_map[i][j] == 'S' || \
				cub->new_map[i][j] == 'E' || cub->new_map[i][j] == 'W')
				count++;
			j++;
		}
		i++;
	}
	if (count != 1)
		clean_exit("Error : Wrong number of player\n", cub);
}

void	where_is_the_player(t_cub *cub)
{
	int	i;
	int	j;

	i = 0;
	while (cub->new_map[i])
	{
		j = 0;
		while (cub->new_map[i][j])
		{
			if (cub->new_map[i][j] == 'N' || cub->new_map[i][j] == 'S' || \
				cub->new_map[i][j] == 'W' || cub->new_map[i][j] == 'E')
			{
				cub->data.player_pos_x = j;
				cub->data.player_pos_y = i;
				cub->data.player = cub->new_map[i][j];
				return ;
			}
			j++;
		}
		i++;
	}
	where_the_player_is_looking(cub);
}

void	where_the_player_is_looking(t_cub *cub)
{
	if (cub->data.player == 'N')
		cub->data.player_pa = 0.0;
	else if (cub->data.player == 'S')
		cub->data.player_pa = PI;
	else if (cub->data.player == 'W')
		cub->data.player_pa = 3 * PI / 2;
 	else if (cub->data.player == 'E')
 		cub->data.player_pa = PI / 2;			
}
