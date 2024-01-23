/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_colors_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsion <nsion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 18:25:42 by bbach             #+#    #+#             */
/*   Updated: 2024/01/23 14:56:15 by nsion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	two_commas_only(t_cub *cub)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (cub->colors[i])
	{
		while (cub->colors[i][j])
		{
			if (cub->colors[i][j] == ',')
				k++;
			j++;
		}
		if (k != 2)
			clean_exit("Error\nWrong color format\nPlease use as :\n\
				F XXX, XXX, XXX", cub);
		k = 0;
		j = 0;
		i++;
	}
}

void	check_first_letter(t_cub *cub)
{
	int	i;

	i = 0;
	while (cub->colors[i])
	{
		if (cub->colors[i][0] != 'F' && cub->colors[i][0] != 'C')
			clean_exit("Error\nWrong color format\nPlease use as :\n\
				F XXX, XXX, XXX", cub);
		i++;
	}
}

void	three_spaces_only(t_cub *cub)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (cub->colors[i])
	{
		while (cub->colors[i][j])
		{
			if (cub->colors[i][j] == ' ')
				k++;
			j++;
		}
		if (k != 3)
			clean_exit("Error\nWrong color format\nPlease use as :\n\
				F XXX, XXX, XXX", cub);
		k = 0;
		j = 0;
		i++;
	}
}

void	check_format(t_cub *cub)
{
	int	i;
	int	j;

	i = 0;
	while (cub->colors[i])
	{
		j = 1;
		while (cub->colors[i][j])
		{
			if (cub->colors[i][j] != ' ' && cub->colors[i][j] != ',' && \
				!ft_isdigit(cub->colors[i][j]))
				clean_exit("Error\nWrong color format\nPlease use as :\n\
					F XXX, XXX, XXX", cub);
			j++;
		}
		i++;
	}
}

void	check_colors(t_cub *cub)
{
	int	i;

	i = 0;
	two_commas_only(cub);
	check_first_letter(cub);
	three_spaces_only(cub);
	check_format(cub);
	while (cub->colors[i])
	{
		if (cub->colors[i][0] == 'F')
			get_f_color(cub, i);
		if (cub->colors[i][0] == 'C')
			get_c_color(cub, i);
		i++;
	}
	check_if_between_0_255(cub);
}
