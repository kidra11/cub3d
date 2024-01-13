/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathalie <nathalie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 19:02:02 by nsion             #+#    #+#             */
/*   Updated: 2024/01/13 17:35:17 by nathalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	duble(t_cub *cub)
{
	int	i;
	int	j;

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

int	find_map(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == '1')
				return (i);
			j++;
		}
		i++;
	}
	return (0);
}

void	check_syntax(t_cub *cub)
{
	int	i;
	int	text;
	int	col;
	int	end;

	i = 0;
	text = 0;
	col = 0;
	duble(cub);
	end = find_map(cub->all);
	while (cub->all[i] && i < end)
	{
		if (cub->all[i][0] == 'N' || cub->all[i][0] == 'S' \
			|| cub->all[i][0] == 'W' || cub->all[i][0] == 'E')
			text++;
		if (cub->all[i][0] == 'F' || cub->all[i][0] == 'C')
			col++;
		i++;
	}
	if (text == 4 && col == 2)
		return ;
	else
		clean_exit("Error : Syntax not correct", cub);
}
