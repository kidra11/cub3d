/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsion <nsion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 19:02:02 by nsion             #+#    #+#             */
/*   Updated: 2023/12/29 19:28:05 by nsion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	duble(char **all)
{
	int	i;
	int	j;

	i = 0;
	while (all[i])
	{
		j = 0;
		while (all[j])
		{
			if (all[i][0] == all[j][0])
				return (1);
			j++;
		} 
		i++;
	}
	return (0);
}

int	check_syntax(char **all)
{
	int	i;
	int	text;
	int	col;
	
	i = 0;
	text = 0;
	col = 0;
	if (duble(all) == 1)
		return (0);
	while (i <= 8)
	{
		if (all[i][0] == 'N' || all[i][0] == 'S' || all[i][0] == 'W' || all[i][0] == 'E')
			text++;
		if (all[i][0] == 'F' || all[i][0] == 'C')
			col++;
		i++;
	}
	if (text != 4 && col != 2)
		return (0);
	return (1);
}
