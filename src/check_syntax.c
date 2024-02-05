/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbach <bbach@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 19:02:02 by nsion             #+#    #+#             */
/*   Updated: 2024/02/02 15:08:31 by bbach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	map_end(t_cub *cub)
{
	int	i;

	i = 0;
	while (cub->all[i])
		i++;
	if (cub->all[i - 1][0] != '1' && cub->all[i - 1][0] != ' ')
		clean_all_exit("Error\nInvalid or missing map.", cub);
	else
		return ;
}

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
						clean_all_exit("Error\nDouble element in file", cub);
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

	i = 0;
	while (str[i])
	{
		if (str[i][0] == '1' || str[i][0] == ' ')
			return (i);
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
		map_end(cub);
	else
		clean_all_exit("Error : Syntax not correct", cub);
}

//check_syntax = verifier si tout les element sont present
//find_map = trouve ou ce trouve la map pour ne pas compter d'element apres
//duble = regarde si il y a des doublon d'element
//map_end = verifi si la map est au bon endroit et si elle existe