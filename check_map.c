/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsion <nsion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 17:03:38 by shiro             #+#    #+#             */
/*   Updated: 2023/12/26 16:01:00 by nsion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_cub_file(char *file)
{
	int	i;

	i = 0;
	while (file[i])
		i++;
	i--;
	if (file[i] == 'b')
	{
		i--;
		if (file[i] == 'u')
		{
			i--;
			if (file[i] == 'c')
			{
				i--;
				if (file[i] == '.')
					return (0);
			}
		}
	}
	return (1);
}

int	is_squart(char **map)
{
	int	i;

	i = 0;
	while (map[i] && map[i + 1] != NULL)
	{
		if (ft_strlen(map[i]) == ft_strlen(map[i + 1]))
			i++;
		else
			return (0);
	}
	return (1);
}

int	wall_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '1')
			i++;
		else
			return (0);
	}
	return (1);
}

int	is_wall(char **map)
{
	int	i;

	i = 0;
	if (wall_line(map[0]) == 0)
		return (0);
	while (map[i])
	{
		if (map[i][0] == '1' && map[i][ft_strlen(map[i]) - 1] == '1')
			i++;
		else
			return (0);
	}
	i--;
	if (wall_line(map[i]) == 0)
		return (0);
	return (1);
}

int has_contour(const char *map, int rows, int cols) 
{
    int col = 0;

    while (col < cols) {
        if (map[col] == '0') {
            return 1;
        }
        col++;
    }

    col = (rows - 1) * cols;
    while (col < rows * cols) {
        if (map[col] == '0') {
            return 1;
        }
        col++;
    }

    int row = 1;

    while (row < rows - 1) {
        if (map[row * cols] == '0') {
            return 1;
        }
        row++;
    }

    row = 1;
    while (row < rows - 1) {
        if (map[row * cols + cols - 1] == '0') {
            return 1;
        }
        row++;
    }

    return 0;
}