/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsion <nsion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 17:00:01 by nath              #+#    #+#             */
/*   Updated: 2024/01/22 18:36:40 by nsion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	clean_all_exit(char *message, t_cub *cub)
{
	int	i;

	i = 0;
	if (cub->all)
	{
		while (cub->all[i])
		{
			free(cub->all[i]);
			i++;
		}
		free(cub->all);
	}
	if (!message)
		exit(ft_printf("Error\n"));
	exit(ft_printf("%s\n", message));
}

void	clean_exit(char *message, t_cub *cub)
{
	if (cub->all)
		free_tab(cub->all);
	if (cub->tex)
		free_tab(cub->tex);
	if (cub->colors)
		free_tab(cub->colors);
	if (cub->map)
		free_tab(cub->map);
	if (cub->data.no)
		free(cub->data.no);
	if (cub->data.so)
		free(cub->data.so);
	if (cub->data.we)
		free(cub->data.we);
	if (cub->data.ea)
		free(cub->data.ea);
	if (!message)
		exit(ft_printf("Error\n"));
	exit(ft_printf("%s\n", message));
}

void	end_exit(t_cub *cub)
{
	if (cub->all)
		free_tab(cub->all);
	if (cub->tex)
		free_tab(cub->tex);
	if (cub->colors)
		free_tab(cub->colors);
	if (cub->map)
		free_tab(cub->map);
	if (cub->data.no)
		free(cub->data.no);
	if (cub->data.so)
		free(cub->data.so);
	if (cub->data.we)
		free(cub->data.we);
	if (cub->data.ea)
		free(cub->data.ea);
	exit(0);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	if (tab)
	{
		while (tab[i])
		{
			free(tab[i]);
			i++;
		}
		free(tab);
	}
}
//clean_all_exit = nettoie la variable all et affiche un message d'erreur
//clean_exit = nettoie la variable all