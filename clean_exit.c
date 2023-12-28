/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbach <bbach@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 17:57:22 by shiro             #+#    #+#             */
/*   Updated: 2023/12/28 12:07:18 by bbach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	clean_exit(char *message, t_cub *cub)
{
	int	i;

	i = 0;
	if (cub->map)
	{
		while (cub->map[i])
		{
			free(cub->map[i]);
			i++;
		}
		free(cub->map);
	}
	if (!message)
		exit(ft_printf("Error\n"));
	exit(ft_printf("%s\n", message));
}