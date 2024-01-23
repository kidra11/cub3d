/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_elem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsion <nsion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 20:01:30 by nath              #+#    #+#             */
/*   Updated: 2024/01/23 15:19:29 by nsion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	count_elem(t_cub *cub, int choise)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (cub->all[i])
	{
		if (choise == 1 && (cub->all[i][0] == 'N' || cub->all[i][0] == 'S' || \
			cub->all[i][0] == 'W' || cub->all[i][0] == 'E'))
			result++;
		if (choise == 2 && (cub->all[i][0] == 'F' || cub->all[i][0] == 'C'))
				result++;
		if (choise == 3 && (cub->all[i][0] == '1' || cub->all[i][0] == '0' || \
			cub->all[i][0] == ' ' || cub->all[i][0] == '\t'))
			result++;
		i++;
	}
	return (result);
}

void	text_map_malloc(t_cub *cub)
{
	int	i;
	int	j;
	int	p;
	int	x;

	x = 0;
	p = 0;
	i = 0;
	j = 0;
	while (cub->all[i])
	{
		if (cub->all[i][0] == 'N' || cub->all[i][0] == 'S' || \
			cub->all[i][0] == 'W' || cub->all[i][0] == 'E')
			cub->tex[x++] = ft_copy(cub->all[i], 0, ft_strlen(cub->all[i]));
		if (cub->all[i][0] == 'F' || cub->all[i][0] == 'C')
			cub->colors[p++] = ft_copy(cub->all[i], 0, ft_strlen(cub->all[i]));
		if (cub->all[i][0] == '1' || cub->all[i][0] == '0' || \
			cub->all[i][0] == ' ' || cub->all[i][0] == '\t')
			cub->map[j++] = ft_copy(cub->all[i], 0, ft_strlen(cub->all[i]));
		i++;
	}
}

void	stock_elem(t_cub *cub)
{
	cub->tex = malloc((count_elem(cub, 1) + 1) * sizeof (char *));
	if (!cub->tex)
		cub->tex = NULL;
	cub->tex[count_elem(cub, 1)] = '\0';
	cub->colors = malloc((count_elem(cub, 2) + 1) * sizeof (char *));
	if (!cub->colors)
		cub->colors = NULL;
	cub->colors[count_elem(cub, 2)] = '\0';
	cub->map = malloc((count_elem(cub, 3) + 1) * sizeof (char *));
	if (!cub->map)
		cub->map = NULL;
	cub->map[count_elem(cub, 3)] = '\0';
	text_map_malloc(cub);
}

//stcok_elem = malloc les 3 tableau de tableau et ferme le tableau
//text_malloc = copie la ligne dans la bonne variable
//count_elem = compte pour bien malloc
//elements_in_map = verifi que tout les element sont bien dans la map