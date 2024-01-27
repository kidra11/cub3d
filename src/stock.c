/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbach <bbach@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:29:58 by nsion             #+#    #+#             */
/*   Updated: 2024/01/27 15:15:52 by bbach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*ft_copy(const char *str, int start, int end)
{
	int		i;
	char	*cp;

	i = 0;
	cp = (char *) malloc(((end - start) + 1) * sizeof(char));
	if (!cp)
		return (NULL);
	while (start < end)
	{
		if (str[start] == '\n')
			start++;
		cp[i++] = str[start++];
	}
	cp[i] = 0;
	return (cp);
}

int	count_lines(char *file)
{
	int		fd;
	int		lines_count;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		exit(ft_printf("Error opening file"));
	lines_count = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		lines_count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (lines_count);
}

char	**stock(char *file)
{
	int		fd;
	char	*line;
	char	**all;
	int		i;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		exit(printf("Error : file does not exist\n"));
	all = malloc((count_lines(file) + 1) * sizeof(char *));
	if (!all)
	{
		close(fd);
		return (NULL);
	}
	i = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		all[i++] = ft_copy(line, 0, ft_strlen(line));
		free(line);
		line = get_next_line(fd);
	}
	all[i] = NULL;
	close(fd);
	return (all);
}

//on va stocker tout le ficher dans char **all.
//stock = on va lire et copier le fichier (utilisation de gnl)
//count_lines = on va compter combier all aura de ligne (utilisation de gnl)
//ft_copy = on malloc et copie chaque caratere de la ligne. 
