/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbach <bbach@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 17:03:38 by shiro             #+#    #+#             */
/*   Updated: 2023/12/29 11:24:27 by bbach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	is_cub_file(t_cub *cub, char *file)
{
	int	i;
	int j;

	i = 0;
	while (file[i])
		i++;
	if (file[i - 1] != 'b' || file[i - 2] != 'u' || file[i - 3] != 'c' 
		|| file[i - 4] != '.')
			clean_exit("Error\nWrong file extension", cub);
	i = 0;
	ft_printf("test_is_cub_file_1\n");
	ft_printf("map[%d] : %s\n", i, cub->map[i]);
	while(cub->map[i])
	{
		j = 0;
		ft_printf("test_is_cub_file_2\n");
		while (cub->map[i][j])
		{
			if (cub->map[i][j] != '1' && cub->map[i][j] != '0' && cub->map[i][j] != 'N' 
				&& cub->map[i][j] != 'S' && cub->map[i][j] != 'E' && cub->map[i][j] != 'W')
					{
						ft_printf("test_is_cub_file_3\n");
						exit(ft_printf("Error\nWrong character in map\n"));
					}
			j++;
		}
		i++;
	}
}

int	count_lines(char *file, t_cub *cub)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		clean_exit("Error opening file", cub);
	cub->lines_count = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		cub->lines_count++;
		free(line);
	}
	close(fd);
	return (cub->lines_count);
}

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

void	stock_map(char *file_path, t_cub *cub)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		clean_exit("Error : can't open this file", cub);
	line = malloc(sizeof(char) * 100000);
	if (!line)
		return ;
	i = read(fd, line, 10000);
	if (i == 0)
	{
		free(line);
		clean_exit("Error : empty file", cub);
	}
	line[i] = '\0';
	cub->map = ft_split(line, '\n');
	free(line);
	close(fd);
}


void	init_maps(char *file, t_cub *cub)
{
	int		i;

	cub->map = NULL;
	ft_printf("test_init_maps_1\n");
	stock_map(file, cub);
	is_cub_file(cub, file);	
	i = 0;
	while (cub->map[i])
	{
		ft_printf("map[%d] : %s\n", i, cub->map[i]);
		i++;
	}
}




