/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsion <nsion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:42:59 by nath              #+#    #+#             */
/*   Updated: 2024/01/24 14:18:34 by nsion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	longest_line(char **map)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	len = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
			j++;
		if (len < j)
			len = j;
		i++;
	}
	return (len);
}

char	*fill_the_line(int len)
{
	char	*result;
	int		i;

	i = 0;
	result = malloc((len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	while (i < len)
		result[i++] = '1';
	return (result);
}

void	fill_the_map(t_cub *cub)
{
	int	i;
	int	j;

	i = 0;
	while (cub->map[i])
	{
		cub->new_map[i] = malloc((longest_line(cub->map) + 1) * sizeof(char));
		if (!cub->new_map[i])
			clean_exit("error", cub);
		j = 0;
		while (cub->map[i][j] && j < longest_line(cub->map))
		{
			if (cub->map[i][j] == ' ')
				cub->new_map[i][j] = '1';
			else
				cub->new_map[i][j] = cub->map[i][j];
			j++;
		}
		while (j < longest_line(cub->map))
			cub->new_map[i][j++] = '1';
		cub->new_map[i][j] = '\0';
		i++;
	}
}

void	new_map(t_cub *cub)
{
	int	i;

	i = 0;
	while (cub->map[i])
		i++;
	cub->new_map = malloc((i + 1) * sizeof(char *));
	if (!cub->new_map)
		clean_exit("error", cub);
	cub->new_map[i] = '\0';
	cub->new_map[0] = fill_the_line(longest_line(cub->map));
	fill_the_map(cub);
	cub->new_map[i - 1] = fill_the_line(longest_line(cub->map));
}
