/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbach <bbach@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 17:57:22 by shiro             #+#    #+#             */
/*   Updated: 2024/01/10 10:29:35 by bbach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	clean_exit(char *message, t_cub *cub)
{
	int	i;

	i = 0;
	if (cub->all)
	{
		while (cub->all[i])
		{
			free(cub->all[i]);
			i++;
		}
		free(cub->all);
	}
	if (!message)
		exit(ft_printf("Error\n"));
	exit(ft_printf("%s\n", message));
}

void 	free_2d_array(char ***arr) 
{
	int i;

	i = 0;
    if (arr == NULL || *arr == NULL)
        return;

    while ((*arr)[i] != NULL) 
	{
		free((*arr)[i]);
		i++;
    }
    free(*arr);
    *arr = NULL;
}

void	free_everything(t_cub *cub)
{
	free_2d_array(&cub->map_copy);
	free_2d_array(&cub->textures_path);
	free_2d_array(&cub->couleurs_path);
	free_2d_array(&cub->all);
}