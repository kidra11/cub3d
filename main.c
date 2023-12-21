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

void	init_maps(char *file)
{
	int	fd;
	char *line;
	
	if (is_cub_file(file) == 0)
	{	
		printf("%s\n", file);
		fd = open(file, O_RDONLY);
		if(!fd)
			exit(printf("Error : file does not exist\n"));
		line = get_next_line(fd);
		if(!line)
			exit(printf("Error : can't read this file\n"));
		printf("trier la maps is ok?\n");
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
