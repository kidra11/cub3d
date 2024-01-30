/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsion <nsion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:53:27 by nath              #+#    #+#             */
/*   Updated: 2024/01/30 16:30:43 by nsion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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
				if (cub->map[i][j + 1] == ' ' || cub->map[i][j - 1] == ' ' \
				|| cub->map[i + 1][j] == ' ' || cub->map[i][j + 1] == '\0' \
				|| cub->map[i - 1][j] == ' ' || cub->map[i + 1][j] == '\0')
					clean_exit("Error\nMap is not closed inside", cub);
			}
			j++;
		}
		i++;
	}
}

void	check_map(t_cub *cub)
{
	if (!check_first_line(cub) || !check_last_line(cub) \
		|| !check_first_column(cub))
		clean_exit("Error\nMap is not closed outside", cub);
	flood_the_wall(cub);
	elements_in_map(cub);
	where_is_the_player(cub);
}

void	elements_in_map(t_cub *cub)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (cub->map[i])
	{
		j = 0;
		while (cub->map[i][j])
		{
			if (cub->map[i][j] != '1' && cub->map[i][j] != '0' && \
				cub->map[i][j] != 'N' && cub->map[i][j] != 'S' && \
				cub->map[i][j] != 'E' && cub->map[i][j] != 'W' && \
				cub->map[i][j] != ' ')
				clean_exit("Error : Wrong element in map\n", cub);
			else if (cub->map[i][j] == 'N' || cub->map[i][j] == 'S' || \
				cub->map[i][j] == 'E' || cub->map[i][j] == 'W')
				count++;
			j++;
		}
		i++;
	}
	if (count != 1)
		clean_exit("Error : Wrong number of player\n", cub);
}

void	where_is_the_player(t_cub *cub)
{
	int	i;
	int	j;

	i = 0;
	while (cub->map[i])
	{
		j = 0;
		while (cub->map[i][j])
		{
			if (cub->map[i][j] == 'N' || cub->map[i][j] == 'S' || \
				cub->map[i][j] == 'W' || cub->map[i][j] == 'E')
			{
				cub->data.player_pos_x = j;
				cub->data.player_pos_y = i;
				cub->data.player = cub->map[i][j];
				return ;
			}
			j++;
		}
		i++;
	}
}

double	where_the_player_is_looking(t_cub *cub)
{
	if (cub->data.player == 'N')
		return (0.0);
	else if (cub->data.player == 'S')
		return (PI);
	else if (cub->data.player == 'E')
		return (PI / 2);
	else if (cub->data.player == 'W')
		return (3 * PI / 2);
	else
		return (0.0);
}
//check_map =  verifi que la map a es fermer et si on a tout 
//les element necesaire
//elements_in_map est dans stock eleme
//flood_the_wall = verifi que la map est fermer a l'interieur
//check_first_column = verifi que la premiere colone est bien fermer
//check_last_line = verifi que la derniere ligne est bien fermer
//check_first_line = verifi que la premiere ligne est bien fermer