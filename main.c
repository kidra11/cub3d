/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsion <nsion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 16:14:23 by nsion             #+#    #+#             */
/*   Updated: 2023/12/21 18:24:51 by nsion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

int	is_cub_file(char *file)
{
	int i;

	i = 0;
	while(file[i])
		i++;
	i--;
	if (file[i] == 'b')
	{
		i--;
		if(file[i] == 'u')
		{
			i--;
			if(file[i] == 'c')
			{
				i--;
				if(file[i] == '.')
					return(0);
			}
		}
	}
	return(1);
}

char	*hihi(const char *str, int start, int end)
{
	int		i;
	char	*cp;

	i = 0;
	cp = (char *) malloc(((end - start) + 1) * sizeof(char));
	if (!cp)
		return (NULL);
	while (start < end)
		cp[i++] = str[start++];
	cp[i] = 0;
	return (cp);
}

char **stock_file(int fd)
{
	char **map;
	char *line;
	int	i;
	int	len_line;

	len_line = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		len_line++;
		free(line);
	}
	map = malloc((len_line  + 1) * sizeof(char**));
	if (!map)
		return (NULL);
	i = 0;
	while (i < len_line && (line = get_next_line(fd)) != NULL)
	{
		printf("i : %d\n", i);
		map[i] = hihi(line, 0, ft_strlen(line));
		free(line);
		i++;
	}
	map[len_line] = NULL;
	return (map);
}

void	init_maps(char *file)
{
	int	fd;
	//char *line;
	
	if (is_cub_file(file) == 0)
	{	
		printf("%s\n", file);
		fd = open(file, O_RDONLY);
		if(!fd)
			exit(printf("Error : file does not exist\n"));
		char **map = stock_file(fd);
		if (!map)
			exit(printf("Error : empty file\n"));
		//int	i = 0;
		//while (map[i])
		//{
			printf("%s\n", map[0]);
		//	i++;
		//}
		//line = get_next_line(fd);
		//if(!line)
		//	exit(printf("Error : can't read this file\n"));
		//is_squart(file);
		//is_wall(file);
		//is_cub(file);
	}
	else
		exit(printf("Error : is not a .cub file\n"));
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		init_maps(av[1]);
	}
	else
		printf("Error : Non file.\n");
	return(0);
}
