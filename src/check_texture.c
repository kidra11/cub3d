/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lthong <lthong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 13:02:49 by bbach             #+#    #+#             */
/*   Updated: 2024/01/23 20:13:52 by lthong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_1st_letter(t_cub *cub)
{
	int	i;

	i = 0;
	while (cub->tex[i])
	{
		if (cub->tex[i][0] != 'N' && cub->tex[i][0] != 'S' && \
			cub->tex[i][0] != 'W' && cub->tex[i][0] != 'E')
			clean_exit("Error\nWrong texture format\nPlease use as :\nNO XXX\n\
				SO XXX\nWE XXX\nEA XXX", cub);
		i++;
	}
}

void	check_texture_path_1(t_cub *cub)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (cub->tex[i])
	{
		while (cub->tex[i][j])
		{
			if (cub->tex[i][j] == '.' && cub->tex[i][j + 1] == '/')
				k++;
			j++;
		}
		if (k != 1)
			clean_exit("Error\nWrong texture format\nPlease use as :\n\
				NO ./XXX\nSO ./XXX\nWE ./XXX\nEA ./XXX", cub);
		k = 0;
		j = 0;
		i++;
	}
}

void	get_path_texture(t_cub *cub)
{
	int	i;

	i = 0;
	while (cub->tex[i])
	{
		if (cub->tex[i][0] == 'N' && cub->tex[i][1] == 'O')
			cub->data.no = ft_copy(cub->tex[i], 3, ft_strlen(cub->tex[i]));
		if (cub->tex[i][0] == 'S' && cub->tex[i][1] == 'O')
			cub->data.so = ft_copy(cub->tex[i], 3, ft_strlen(cub->tex[i]));
		if (cub->tex[i][0] == 'W' && cub->tex[i][1] == 'E')
			cub->data.we = ft_copy(cub->tex[i], 3, ft_strlen(cub->tex[i]));
		if (cub->tex[i][0] == 'E' && cub->tex[i][1] == 'A')
			cub->data.ea = ft_copy(cub->tex[i], 3, ft_strlen(cub->tex[i]));
		i++;
	}
}

void	check_path_correct(t_cub *cub)
{
	if (access(cub->data.no, F_OK) == -1)
		clean_exit("Error\nWrong texture path", cub);
	if (access(cub->data.so, F_OK) == -1)
		clean_exit("Error\nWrong texture path", cub);
	if (access(cub->data.we, F_OK) == -1)
		clean_exit("Error\nWrong texture path", cub);
	if (access(cub->data.ea, F_OK) == -1)
		clean_exit("Error\nWrong texture path", cub);
}

void	check_texture(t_cub *cub)
{
	check_1st_letter(cub);
	check_texture_path_1(cub);
	get_path_texture(cub);
	check_path_correct(cub);
}
