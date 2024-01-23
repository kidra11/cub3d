/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nath <nath@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:42:59 by nath              #+#    #+#             */
/*   Updated: 2024/01/23 18:39:42 by nath             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int longest_line(char **map)
{
    int i;
    int j;
    int len;

    i = 0;
    len = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
            j++;
        if (len < j)
            len = j;
        i++;
    }
    return (len);
}

char *fill_the_line(int len)
{
    char *result;
    int i;

    i = 0;
    result = malloc((len + 1) * sizeof(char));
    if(!result)
        return(NULL);
    while (i < len)
        result[i++] = '1';
    return (result);
}

void    new_map(t_cub *cub)
{
    int i;
    int j;
    char **new_map;

    i = 0;
    new_map = NULL;
    printf_tab(cub->map, "map");
    while(cub->map[i])
        i++;
    new_map = malloc((i + 1) * sizeof(char *));
    if (!new_map)
        clean_exit("error", cub);
    new_map[i] = '\0';
    new_map[0] = fill_the_line(longest_line(cub->map));  
    i = 1;
    //check de fin de ligne en '1'
    //apres fin de ligne que des 1
    //avant fin de ligne que des 1
    //entre les fin de ligne ' ' = '0'
    while (cub->map[i])
    {
        new_map[i] = malloc((longest_line(cub->map) + 1) * sizeof(char));
        if (!new_map[i])
            clean_exit("error", cub);
        j = 0;
        while(cub->map[i][j] && j < longest_line(cub->map))
        {
            if (cub->map[i][j] == ' ')
                new_map[i][j] = '1';
            else
                new_map[i][j] = cub->map[i][j];
            j++;
        }
        while (j < longest_line(cub->map))
        {
            new_map[i][j] = '1';
            j++;
        }
        new_map[i][j] = '\0';
        i++;
    }
    i--;
    new_map[i] = fill_the_line(longest_line(cub->map));
    printf_tab(new_map, "new_map");
}
