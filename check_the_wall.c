/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_the_wall.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbach <bbach@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:14:15 by bbach             #+#    #+#             */
/*   Updated: 2024/01/11 17:59:48 by bbach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    fill_inside_the_map_with_wall(t_cub *cub)
{
    int i;

    i = 0;
    while (cub->map_copy[i])
    {
        printf("%s\n", cub->map_copy[i]);
        i++;
    }
}
static int     check_first_line(t_cub *cub)
{
    int i;

    i = 0;
    while (cub->map_copy[0][i])
    {
        if (cub->map_copy[0][i] != '1' && cub->map_copy[0][i] != ' ')
            return (0);
        i++;
    }
    return (1);
}

static int     check_last_line(t_cub *cub)
{
    int i;
    int j;

    j = 0;
    i = 0;
    while (cub->map_copy[i])
        i++;
    i--;
    while (cub->map_copy[i][j])
    {
        if (cub->map_copy[i][j] != '1' && cub->map_copy[i][j] != ' ')
            return (0);
        j++;
    }
    return (1);
}

static int    check_first_column(t_cub *cub)
{
    int i;

    i = 0;
    while (cub->map_copy[i])
    {
        if (cub->map_copy[i][0] != '1' && cub->map_copy[i][0] != ' ')
            return (0);
        i++;
    }
    return (1);
}
void    flood_the_wall(t_cub *cub)
{
    int i;
    int j;
    int end;

    end = 0;
    i = 0;
    j = 0;
    if (!check_first_line(cub) || !check_last_line(cub) 
        || !check_first_column(cub))
        clean_exit("Error\nMap is not closed outside", cub);
    while (cub->map_copy[i])
        i++;
    end = i;
    i = 1;
    while (cub->map_copy[i] && i < end - 1)
    {
        while (cub->map_copy[i][j])
        {
            printf("i = %d\nj = %d\n", i, j);
            printf("le char correspondant a i[j] est %c\n", cub->map_copy[i][j]);
            printf("le char correspondant a i[j + 1] est %c\n", cub->map_copy[i][j + 1]);
            if (cub->map_copy[i][j] == '0')
            {
                if (cub->map_copy[i][j + 1] == ' ' || cub->map_copy[i][j - 1] == ' ' 
                || cub->map_copy[i + 1][j] == ' ' || cub->map_copy[i][j + 1] == '\0' 
                || cub->map_copy[i - 1][j] == ' ' || cub->map_copy[i + 1][j] == '\0')
                       clean_exit("Error\nMap is not closed inside", cub);            
            }
            j++;
        }
        j = 0;
        i++;
    }
    printf("Map is closed\n");
}