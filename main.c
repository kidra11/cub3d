/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsion <nsion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 16:14:23 by nsion             #+#    #+#             */
/*   Updated: 2023/12/29 19:30:41 by nsion            ###   ########.fr       */
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
		all[i++] = hihi(line, 0, ft_strlen(line));
		free(line);
		line = get_next_line(fd);
	}
	all[i] = NULL;
	close(fd);
	return (all);
}

void	init_maps(char *file)
{
	char	**all;
	int		i;

	all = NULL;
	if (is_cub_file(file) == 0)
	{
		all = stock(file);
		if (check_syntax(all) == 1)
			ft_printf("valid_map\n");
		// si il y a tout les element 
		//textur = stock_text(all);
		//textur = all[0] -> all[7]
		//map = stock_map(all);
		//map = all[7] - > [...]
		//is_valid_map(map);
		//is_valid_textur(texture);
		i = 0;
		while (all[i])
		{
			ft_printf("all[%d] : %s\n", i, all[i]);
			i++;
		}
		clean_exit(all, "");
	}
	else
		clean_exit(all, "Error : is not a .cub file");
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		init_maps(av[1]);
	}
	else
		ft_printf("Error : Non file.\n");
	return (0);
}
