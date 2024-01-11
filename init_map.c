/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbach <bbach@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 18:11:10 by bbach             #+#    #+#             */
/*   Updated: 2024/01/11 14:02:31 by bbach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    all_mallc(t_cub *cub)
{
	int i = 0;
	int o = 0;
    int j = 0;
    int p = 0;

	while (cub->all[i])
	{
		if (cub->all[i][0] == 'N' || cub->all[i][0] == 'S' || cub->all[i][0] == 'W' 
		|| cub->all[i][0] == 'E')
			o++;
        if (cub->all[i][0] == 'F' || cub->all[i][0] == 'C')
            p++;
		if (cub->all[i][0] == '1')
			j++;
		i++;
	}
	cub->textures_path = malloc(sizeof(char *) * (o + 1));
	if (!cub->textures_path)
		return ;
	cub->textures_path[o] = '\0';
	cub->map_copy = malloc((sizeof(char *) * (j + 1)));
	if (!cub->map_copy)
		return ;
	cub->map_copy[j] = '\0';
    cub->couleurs_path = malloc(sizeof(char *) * (p + 1));
    if (!cub->couleurs_path)
        return ;
    cub->couleurs_path[p] = '\0';
}

void    text_map_malloc(t_cub *cub)
{
    int i;
	int j;
    int p;
    int x;

    x = 0;
    p = 0;
    i = 0;
    j = 0;
	while (cub->all[i])
	{
		if (cub->all[i][0] == 'N' || cub->all[i][0] == 'S' || cub->all[i][0] == 'W' 
			|| cub->all[i][0] == 'E')
            {
				cub->textures_path[x] = ft_copy(cub->all[i], 0, ft_strlen(cub->all[i]));
                x++;
            }
        if (cub->all[i][0] == 'F' || cub->all[i][0] == 'C')
        {
            cub->couleurs_path[p] = ft_copy(cub->all[i], 0, ft_strlen(cub->all[i]));
            p++;
        }
		if (cub->all[i][0] == '1' || cub->all[i][0] == '0')
		{
			cub->map_copy[j] = ft_copy(cub->all[i], 0, ft_strlen(cub->all[i]));
			j++;
		}
		i++;
	}
}

void    map_at_the_end_of_file(t_cub *cub)
{
    int i;

    i = 0;
    while (cub->all[i])
        i++;
    if (cub->all[i - 1][0] != '1' && cub->all[i - 1][0] != ' ')
        clean_exit("Error\nMap not at the end of file", cub);
    else
        printf("Map at the end of file\n");
}