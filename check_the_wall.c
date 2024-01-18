/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_the_wall.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbach <bbach@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:14:15 by bbach             #+#    #+#             */
/*   Updated: 2024/01/16 13:48:45 by bbach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
}
void    no_double_in_all(t_cub *cub)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (cub->all[i])
    {
        if (ft_isalpha(cub->all[i][0]))
        {
            while (cub->all[j])
            {
                if (ft_isalpha(cub->all[j][0]) && i != j)
                {
                    if (cub->all[i][0] == cub->all[j][0])
                        clean_exit("Error\nDouble element in file", cub);
                }
                j++;
            }
            j = 0 + i;
        }
        i++;
    }
}