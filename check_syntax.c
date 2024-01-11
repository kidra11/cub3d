/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nath <nath@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 19:02:02 by nsion             #+#    #+#             */
/*   Updated: 2024/01/11 21:02:29 by nath             ###   ########.fr       */
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
		j = i + 1;
		while (all[j])
		{
			if (all[i][0] == all[j][0] && all[i][0] != '\n')
				return (1);
            j++;
		} 
		i++;
	}
	return (0);
}

int find_map(char *str)
{
    int i;

    i = 0;
    while(str[i])
    {
        if (str[i] == '1' || str[i] == ' ') 
            i++;
        else
            return (0);
    }
    return (1);
}

void	check_syntax(t_cub *cub)
{
	int	i;
	int	text;
	int	col;
	
	i = 0;
	text = 0;
	col = 0;
	if (duble(cub->all) == 1)
		clean_exit("Error : Can't have doubles.", cub);
	while (cub->all[i] && find_map(cub->all[i]) == 0)
	{
		if (cub->all[i][0] == 'N' || cub->all[i][0] == 'S' || cub->all[i][0] == 'W' || cub->all[i][0] == 'E')
			text++;
		if (cub->all[i][0] == 'F' || cub->all[i][0] == 'C')
			col++;
		i++;
	}
	if (text != 4 && col != 2)
		clean_exit("Error : Syntax not correct", cub);
	ft_printf("syntatx OK\n");
}
