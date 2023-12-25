/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shiro <shiro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 16:14:23 by nsion             #+#    #+#             */
/*   Updated: 2023/12/25 23:51:14 by shiro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*hihi(const char *str, int start, int end)
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
		exit(printf("Error opening file"));
	lines_count = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		lines_count++;
		free(line);
	}
	close(fd);
	return (lines_count);
}

char	**stock_map(char *file)
{
	int		fd;
	char	*line;
	char	**map;
	int		i;

	fd = open(file, O_RDONLY);
	if (!fd)
		exit(printf("Error : file does not exist\n"));
	map = malloc((count_lines(file) + 1) * sizeof(char *));
	if (!map)
		return (NULL);
	i = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		if (!line)
		{
			close(fd);
			exit(printf("Error : can't read this file\n"));
		}
		map[i++] = hihi(line, 0, ft_strlen(line));
		free(line);
	}
	map[i] = NULL;
	close(fd);
	return (map);
}

void	init_maps(char *file)
{
	char	**map;
	int		i;

	map = NULL;
	if (is_cub_file(file) == 0)
	{	
		map = stock_map(file);
		if (is_squart(map) == 0)
			clean_exit(map, "Error : not valid map");
		if (is_wall(map) == 0)
			clean_exit(map, "Error : not valid map");
		//is_cub
		i = 0;
		while (map[i])
		{
			printf("map[%d] : %s\n", i, map[i]);
			i++;
		}
	}
	else
		clean_exit(map, "Error : is not a .cub file");
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		init_maps(av[1]);
	}
	else
		printf("Error : Non file.\n");
	return (0);
}
