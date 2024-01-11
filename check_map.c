/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbach <bbach@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 17:03:38 by shiro             #+#    #+#             */
/*   Updated: 2024/01/11 15:31:50 by bbach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	is_cub_file(char *file)
{
	int	i;

	i = 0;
	while (file[i])
		i++;
	if (file[i - 1] != 'b' || file[i - 2] != 'u' || file[i - 3] != 'c' 
		|| file[i - 4] != '.')
		{
			ft_printf("Error\nWrong file extension\n");
			exit(0);
		}
}

void	elements_in_map(t_cub *cub)
{
	int i; 
	int j;
	
	i = 0;
	j = 0;
	while(cub->map_copy[i])
	{
		while (cub->map_copy[i][j])
		{
			if (cub->map_copy[i][j] != '1' && cub->map_copy[i][j] != '0' && cub->map_copy[i][j] != 'N' 
				&& cub->map_copy[i][j] != 'S' && cub->map_copy[i][j] != 'E' && cub->map_copy[i][j] != 'W' 
				&& cub->map_copy[i][j] != ' ')
						exit(ft_printf("Error\nWrong character in map\n"));
			if (cub->map_copy[i][j] == 'N' || cub->map_copy[i][j] == 'S' || cub->map_copy[i][j] == 'E' 
				|| cub->map_copy[i][j] == 'W')
        	{
            	cub->data.player_pos_x = i;
            	cub->data.player_pos_y = j;
       		}
			j++;
		}
		j = 0;
		i++;
	}
}

void	get_map(char *file_path, t_cub *cub)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open(file_path, O_RDONLY);
	if (fd == -1)
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
	cub->all = ft_split(line, '\n');
	free(line);
	all_mallc(cub);
	text_map_malloc(cub);
	close(fd);
}

void	init_maps(char *file, t_cub *cub)
{
	get_map(file, cub);
	flood_the_wall(cub);
	map_at_the_end_of_file(cub);
	elements_in_map(cub);
	check_colors(cub);
	check_texture(cub);
}
