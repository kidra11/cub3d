/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_colors_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathalie <nathalie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 16:46:10 by nathalie          #+#    #+#             */
/*   Updated: 2024/01/16 17:57:04 by nathalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_f_color(t_cub *cub, int i)
{
	int	j;
	int	k;

	j = 0;
	k = 0;
	while (cub->colors[i][j])
	{
		if (ft_isdigit(cub->colors[i][j]))
		{
			if (k == 0)
				cub->data.red_f = ft_atoi(&cub->colors[i][j]);
			if (k == 1)
				cub->data.green_f = ft_atoi(&cub->colors[i][j]);
			if (k == 2)
				cub->data.blue_f = ft_atoi(&cub->colors[i][j]);
			while (ft_isdigit(cub->colors[i][j]))
				j++;
			k++;
		}
		if (cub->colors[i][j])
			j++;
	}
}

void	get_c_color(t_cub *cub, int i)
{
	int	j;
	int	k;

	j = 0;
	k = 0;
	while (cub->colors[i][j])
	{
		if (ft_isdigit(cub->colors[i][j]))
		{
			if (k == 0)
				cub->data.red_c = ft_atoi(&cub->colors[i][j]);
			if (k == 1)
				cub->data.green_c = ft_atoi(&cub->colors[i][j]);
			if (k == 2)
				cub->data.blue_c = ft_atoi(&cub->colors[i][j]);
			while (ft_isdigit(cub->colors[i][j]))
				j++;
			k++;
		}
		if (cub->colors[i][j])
			j++;
	}
}

void	check_if_between_0_255(t_cub *cub)
{
	if (cub->data.red_f < 0 || cub->data.red_f > 255)
		clean_exit("Error\nWrong color format\nPlease use as :\n\
			F (0->255), (0->255), (0->255)", cub);
	if (cub->data.green_f < 0 || cub->data.green_f > 255)
		clean_exit("Error\nWrong color format\nPlease use as :\n\
			F (0->255), (0->255), (0->255)", cub);
	if (cub->data.blue_f < 0 || cub->data.blue_f > 255)
		clean_exit("Error\nWrong color format\nPlease use as :\n\
			F (0->255), (0->255), (0->255)", cub);
	if (cub->data.red_c < 0 || cub->data.red_c > 255)
		clean_exit("Error\nWrong color format\nPlease use as :\n\
			F (0->255), (0->255), (0->255)", cub);
	if (cub->data.green_c < 0 || cub->data.green_c > 255)
		clean_exit("Error\nWrong color format\nPlease use as :\n\
			F (0->255), (0->255), (0->255)", cub);
	if (cub->data.blue_c < 0 || cub->data.blue_c > 255)
		clean_exit("Error\nWrong color format\nPlease use as :\n\
			F (0->255), (0->255), (0->255)", cub);
}
