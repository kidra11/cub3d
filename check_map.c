/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbach <bbach@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 17:03:38 by shiro             #+#    #+#             */
/*   Updated: 2023/12/29 17:44:25 by bbach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	is_cub_file(t_cub *cub, char *file)
{
	int	i;

	i = 0;
	while (file[i])
		i++;
	if (file[i - 1] != 'b' || file[i - 2] != 'u' || file[i - 3] != 'c' 
		|| file[i - 4] != '.')
			clean_exit("Error\nWrong file extension", cub);
}

void	elements_in_map(t_cub *cub)
{
	int i; 
	int j;
	
	i = 0;
	j = 0;
	ft_printf("%s\n", cub->map_copy[i]);
	while(cub->map_copy[i])
	{
		while (cub->map_copy[i][j])
		{
			if (cub->map_copy[i][j] != '1' && cub->map_copy[i][j] != '0' && cub->map_copy[i][j] != 'N' 
				&& cub->map_copy[i][j] != 'S' && cub->map_copy[i][j] != 'E' && cub->map_copy[i][j] != 'W')
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
	int j = 0;

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
	//printf("line : %s\n", line);
	cub->map = ft_split(line, '\n');
	i = 0;
	int o = 0;
	while (cub->map[i])
	{
		if (cub->map[i][0] == 'N' || cub->map[i][0] == 'S' || cub->map[i][0] == 'W' 
		|| cub->map[i][0] == 'E' || cub->map[i][0] == 'F' || cub->map[i][0] == 'C')
			o++;
		if (cub->map[i][0] == '1')
			j++;
		i++;
	}
	//printf("o : %d\n", o);
	printf("j : %d\n", j);
	cub->textures_path = malloc(sizeof(char *) * o + 1);
	if (!cub->textures_path)
		return ;
	cub->textures_path[i + 1] = '\0';
	cub->map_copy = malloc(sizeof(char *) * j + 1);
	if (!cub->map_copy)
		return ;
	cub->map_copy[j + 1] = '\0';
	i = 0;
	j = 0;
	while (cub->map[i])
	{
		if (cub->map[i][0] == 'N' || cub->map[i][0] == 'S' || cub->map[i][0] == 'W' 
			|| cub->map[i][0] == 'E' || cub->map[i][0] == 'F' || cub->map[i][0] == 'C')
		{
				cub->textures_path[i] = ft_copy(cub->map[i], 2, ft_strlen(cub->map[i])); 
				ft_printf("cub->textures_path[%d] : %s\n", i, cub->textures_path[i]);
		}
		if (cub->map[i][0] == '1' || cub->map[i][0] == '0')
		{
			cub->map_copy[j] = ft_copy(cub->map[i], 0, ft_strlen(cub->map[i]));
			ft_printf("cub->map_copy[%d] : %s\n", j, cub->map_copy[j]);
			j++;
		}
		i++;
	}
	free(line);
	close(fd);
}


void	init_maps(char *file, t_cub *cub)
{
	//int		i;

	is_cub_file(cub, file);	
	ft_printf("test_1\n");
	get_map(file, cub);
	ft_printf("test_2\n");
	elements_in_map(cub);
	ft_printf("test 3\n");
	//i = 0;
	ft_printf("test4\n");
	//while (cub->map[i])
	//{
	//	ft_printf("map[%d] : %s\n", i, cub->map[i]);
	//	i++;
	//}
}




