/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testeur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lthong <lthong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 17:38:22 by nsion             #+#    #+#             */
/*   Updated: 2024/01/23 20:13:27 by lthong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	printf_tab(char **all, char *name)
{
	int	i;

	i = 0;
	if (!all)
		ft_printf("tab vide\n");
	while (all[i])
	{
		ft_printf("%s[%d] : %s\n", name, i, all[i]);
		i++;
	}
}

//printf_tab = on va afficher le nom du char ** et l'afficher entierement  