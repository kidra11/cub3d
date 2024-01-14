/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nath <nath@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:53:27 by nath              #+#    #+#             */
/*   Updated: 2024/01/15 00:02:27 by nath             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_first_line(t_cub *cub)
{
	int	i;

	i = 0;
	while (cub->map[0][i])
	{
		if (cub->map[0][i] != '1' && cub->map[0][i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

static int	check_last_line(t_cub *cub)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (cub->map[i])
		i++;
	i--;
	while (cub->map[i][j])
	{
		if (cub->map[i][j] != '1' && cub->map[i][j] != ' ')
			return (0);
		j++;
	}
	return (1);
}

static int	check_first_column(t_cub *cub)
{
	int	i;

	i = 0;
	while (cub->map[i])
	{
		if (cub->map[i][0] != '1' && cub->map[i][0] != ' ')
			return (0);
		i++;
	}
	return (1);
}

void	flood_the_wall(t_cub *cub)
{
	int	i;
	int	j;
	int	end;

	end = 0;
	while (cub->map[end])
		end++;
	i = 1;
	while (cub->map[i] && i < end - 1)
	{
		j = 0;
		while (cub->map[i][j])
		{
			if (cub->map[i][j] == '0')
			{
				if (cub->map[i][j + 1] == ' ' || cub->map[i][j - 1] == ' ' 
				|| cub->map[i + 1][j] == ' ' || cub->map[i][j + 1] == '\0' 
				|| cub->map[i - 1][j] == ' ' || cub->map[i + 1][j] == '\0')
					clean_exit("Error\nMap is not closed inside", cub);            
			}
			j++;
		}
		i++;
	}
}

void	elements_in_map(t_cub *cub)
{
	int i; 
	int j;
	
	i = 0;
	j = 0;
	while(cub->map[i])
	{
		while (cub->map[i][j])
		{
			if (cub->map[i][j] != '1' && cub->map[i][j] != '0' && cub->map[i][j] != 'N' 
				&& cub->map[i][j] != 'S' && cub->map[i][j] != 'E' && cub->map[i][j] != 'W' 
				&& cub->map[i][j] != ' ')
						exit(ft_printf("Error\nWrong character in map\n"));
			if (cub->map[i][j] == 'N' || cub->map[i][j] == 'S' || cub->map[i][j] == 'E' 
				|| cub->map[i][j] == 'W')
			{
				cub->data.player_pos_x = i;
				cub->data.player_pos_y = j;
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void	check_map(t_cub *cub)
{
	if (!check_first_line(cub) || !check_last_line(cub) 
		|| !check_first_column(cub))
		clean_exit("Error\nMap is not closed outside", cub);
	flood_the_wall(cub);
	elements_in_map(cub);
}
//check_map =  verifi que la map a es fermer et si on a tout les element necesaire
//elements_in map = 
//flood_the_wall = 
//check_first_column = 
//check_last_line = 
//check_first_line = 