/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   where_is_bryan.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbach <bbach@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 14:41:05 by bbach             #+#    #+#             */
/*   Updated: 2024/01/23 15:05:55 by bbach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    where_is_the_player(t_cub *cub)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (cub->map[i])
    {
        while (cub->map[i][j])
        {
            if (cub->map[i][j] == 'N' || cub->map[i][j] == 'S' || \
                cub->map[i][j] == 'W' || cub->map[i][j] == 'E')
            {
                cub->data.player_pos_x = j;
                cub->data.player_pos_y = i;
                cub->data.player = cub->map[i][j];
                return ;
            }
            j++;
        }
        i++;
    }
}

void    where_the_player_is_looking_1(t_cub *cub)
{
    if (cub->data.player == 'N')
    {
        cub->data.player_look_dir_x = 0;
        cub->data.player_look_dir_y = -1;
        cub->data.player_plane_x = 0.66;
        cub->data.player_plane_y = 0;
    }
    else if (cub->data.player == 'S')
    {
        cub->data.player_look_dir_x = 0;
        cub->data.player_look_dir_y = 1;
        cub->data.player_plane_x = -0.66;
        cub->data.player_plane_y = 0;
    }
}
void    where_the_player_is_looking_2(t_cub *cub)
{
    if (cub->data.player == 'W')
    {
        cub->data.player_look_dir_x = -1;
        cub->data.player_look_dir_y = 0;
        cub->data.player_plane_x = 0;
        cub->data.player_plane_y = -0.66;
    }
    else if (cub->data.player == 'E')
    {
        cub->data.player_look_dir_x = 1;
        cub->data.player_look_dir_y = 0;
        cub->data.player_plane_x = 0;
        cub->data.player_plane_y = 0.66;
    }
}
